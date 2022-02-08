/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:15:48 by francesco         #+#    #+#             */
/*   Updated: 2021/10/26 19:15:46 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_info_exit;

char	*ft_realloc(char *path, char *cmd)
{
	size_t		i;
	int			j;
	size_t		len;
	char		*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(path) + ft_strlen(cmd) + 1;
	tmp = malloc(sizeof(char) * len + 2);
	while (i < ft_strlen(path))
	{
		tmp[i] = path[i];
		i++;
	}
	tmp[i++] = '/';
	while (i < len)
	{
		tmp[i] = cmd[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_usexecve(char *path, t_term *term, char **cmd)
{
	char	**path_matrix;
	int		i;
	char	*tmp;

	i = 0;
	execve(cmd[0], cmd, term->info.env_copy);
	path_matrix = ft_split(path + 5, ':');
	while (path_matrix[i])
	{
		tmp = ft_realloc(path_matrix[i], cmd[0]);
		if (execve(tmp, cmd, term->info.env_copy) == -1)
			i++;
		else
		{
			free(tmp);
			i = -1;
			break ;
		}
		free(tmp);
	}
	ft_matrixfree(path_matrix);
	exit(127);
}

int	ft_findpath(t_term *term, char *path)
{
	int	i;

	i = 0;
	while (term->info.env_copy[i])
	{
		if ((ft_strncmp(path, term->info.env_copy[i], ft_strlen(path)) != 0))
			i++;
		else
			return (i);
	}
	if (!ft_strncmp("PATH=", path, ft_strlen("PATH=")) && ft_strlen(path) == 5)
	{
		printf("\033[0;31mERROR, no PATH ENV\033[0;37m\n");
		exit(1);
	}
	return (-1);
}

int	ft_manage_env(t_term *term, int i)
{
	int		y;
	int		ret;
	int		x;

	x = -1;
	y = 0;
	ret = 0;
	while (term->cmd[i][y])
	{	
		ret = handler_env(term, &term->cmd[i][y], i);
		if (ret == 0 || ret == 2 || ret == 3)
			break ;
		y++;
	}
	if (ret == 2)
	{
		y = ft_control_env(term->cmd[i]);
		while (++x < y)
			ft_matrix_remove(&term->cmd[i], term->cmd[i][0]);
	}
	return (ret);
}

void	ft_pipeline(t_term *term, int path_line)
{
	int		status;
	pid_t	pid;
	int		i;
	int		fd[2];
	int		y;
	struct stat buff;

	i = 0;
	while (term->cmd[i])
	{
		pipe(fd);
		if (ft_manage_env(term, i) != 1 && ft_manage_env(term, i) != 3)
		{
			if (i >= 0 && i < term->n_cmd - 1 && term->n_cmd != 1)
			{
				dup2(fd[1], 1);
				close(fd[1]);
			}
			else if (i == term->n_cmd - 1 && term->n_cmd == 1)
			{
				close(fd[1]);
				close(fd[0]);
				dup2(term->fd_1, 1);
			}
			//int fd_f0;
			//fd_f0 = dup(0);
			y = 0;
			while (term->cmd[i] && term->cmd[i][y])
				handler_dollar(term, &term->cmd[i][y++]);
			term->cmd[i] = ft_special_realloc(term->cmd[i]);
			// ft_quoteclean(&term->cmd[i]);
			if (ft_manageredir(term, &term->cmd[i]) != -1)
			{
				if (ft_check_builtin(term->cmd[i]))
					ft_builtinfunctions(term, term->cmd[i]);
				else
				{
					pid = fork();
					handle_signals(2);
					if (pid == 0)
					{
						// if (!ft_redir_imput(term, &term->cmd[i]))
							ft_usexecve(term->info.env_copy[path_line], term, term->cmd[i]);
						// else
						// 	exit(0);
					}
					waitpid(pid, &status, 0);
					if (WIFSIGNALED(status))
						g_info_exit = 128 + WTERMSIG(status);
					else
						g_info_exit = WEXITSTATUS(status);
					if (WEXITSTATUS(status) == 127)
					{
						dup2(term->fd_1, 1);
						printf("%s: command not found\n", term->cmd[i][0]);
						// if (term->n_cmd > 1)
						// 	g_info_exit = 0;
					}
				}
			}
			if(!stat("temp", &buff))
				unlink("temp");
			close(term->i);
			dup2(fd[0], 0);
			close(fd[0]);
			dup2(term->fd_1, 1);
		}
		i++;
	}
}

int	ft_checkquotes(char *str)
{
	int	i;
	int	d_q;
	int	s_q;

	i = 0;
	s_q = 0; // single quotes = 39
	d_q = 0; //double quotes = 34
	while (str && str[i])
	{
			if ((str[i] == 34 && s_q == 0) || (str[i] == 34 && d_q == 1))
			{
				if (d_q == 0)
					d_q = 1;
				else
					d_q = 0;
			}
			else if ((str[i] == 39 && d_q == 0) || (str[i] == 39 && s_q == 1))
			{
				if (s_q == 0)
					s_q = 1;
				else
					s_q = 0;
			}
		i++;
	}
	if (s_q == 1 || d_q == 1)
	{
		printf("SuPerBasH:~$: unexpected EOF while looking for matching quotes\n");
		return (0);
	}
	return (1);
}

void	ft_parsing(t_term *term)
{
	char 	**tmp;
	int		i;
	int		path_line;

	i = 0;	
	term->n_cmd = 0;
	term->prompt = NULL;
	term->single_q = 0;
	term->double_q = 0;
	dup2(term->fd_0, 0);
	handle_signals(1);
	term->prompt = readline("SuPerBasH:~$ ");
	if (!term->prompt)
		exit(0);
	else if (!term->prompt[0] || ft_isspace(term->prompt))
		return ;
	add_history(term->prompt);
	if (!ft_checkquotes(term->prompt))
	{
		free(term->prompt);
		g_info_exit = 2;
		return ;
	}
	if (ft_checkredirline(term, i) == -1)
	{
		free(term->prompt);
		return ;
	}
	tmp = ft_split(term->prompt, '|');
	while (tmp[i])
		i++;
	term->n_cmd = i;
	term->cmd = (char ***)malloc(sizeof(char **) * (i + 1));
	term->cmd[i] = NULL;
	int c = -1;
	while (++c < i)
	{
		term->cmd[c] = ft_split(tmp[c], ' ');
		// ft_quoteclean(&term->cmd[c]);
		//ft_checkline(term->cmd[c], 39);
	}
	
	// ft_matrixprint(term->cmd[0]);
	// puts("-----------------");
	// return ;

	path_line = ft_findpath(term, "PATH=");
	ft_pipeline(term, path_line);
	ft_matrixfree(tmp);
	i = -1;
	while (term->cmd[++i])
		ft_matrixfree(term->cmd[i]);
	free(term->cmd);
	free(term->prompt);
}

void	ft_fillstruct(int argc, char **argv, char **env, t_term *term)
{
	term->info.argc = argc;
	term->info.argv = argv;
	ft_matrixcopy(&term->info.env_copy, env);
}


void	ft_info_list2(t_term *term, char **tmp, char **tmp1)
{
	char *norme;

	norme = NULL;
	norme = ft_itoa(g_info_exit);
	term->env = ft_lstnew("?", norme);
	free(norme);
	*tmp = NULL;
	*tmp1 = NULL;
}

void	ft_info_list(t_term *term)
{
	char		*tmp;
	char		*tmp1;
	t_list		*new;
	int			i;
	int			y;

	i = -1;
	y = 0;
	ft_info_list2(term, &tmp, &tmp1);
	while (term->info.env_copy[++i])
	{
		y = ft_strchr(term->info.env_copy[i], '=');
		tmp = malloc(sizeof(char) * (y + 1));
		ft_memcpy(tmp, term->info.env_copy[i], y);
		tmp[y] = '\0';
		tmp1 = malloc(sizeof(char) * (ft_strlen(term->info.env_copy[i]) - y));
		ft_memcpy(tmp1, term->info.env_copy[i] + y + 1,
			ft_strlen(term->info.env_copy[i]) - y);
		tmp1[ft_strlen(tmp1)] = '\0';
		new = ft_lstnew(tmp, tmp1);
		ft_lstadd_back(&term->env, new);
		free(tmp);
		free(tmp1);
	}
}

void	ft_init(t_term *term)
{
	term->env = NULL;
	g_info_exit = 0;
	term->fd_0 = dup(0);
	term->fd_1 = dup(1);
	term->double_q = 0;
	term->single_q = 0;
	term->c_quote = 0;
	term->q_skip = 0;

}

void	ft_print_minishell()
{
	printf("\n%s   ███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n", KYEL);
    printf("%s   ████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n", KYEL);
    printf("%s   ██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n", KYEL);
    printf("%s   ██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n", KYEL);
    printf("%s   ██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n", KYEL);
    printf("%s   ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n", KYEL);
    printf("%s                                                                      \n", KYEL);
    printf(KNRM);
}

int	main(int argc, char **argv, char **env)
{
	t_term	term;
	ft_init(&term);
	ft_fillstruct(argc, argv, env, &term);
	ft_info_list(&term);
	ft_print_minishell();
	while (1)
		ft_parsing(&term);
	t_list *head;
	while(term.env)
	{
		head = term.env->next;
		free(term.env->old_word);
		free(term.env->new_word);
		free(term.env);
		term.env = head;
	}
	ft_matrixfree(term.info.env_copy);
}
