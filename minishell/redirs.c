/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:20:59 by vspinell          #+#    #+#             */
/*   Updated: 2021/10/25 13:30:19 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_find_replace(char ***cmd)
{
	int	i;
	char str1[1];
	char str2[1];

	*str1 = 39;
	*str2 = 34;
	i = 0;
	puts(str1);
	// puts(str2);
	while((*cmd) && (*cmd)[i])
	{
		if (!ft_strncmp((*cmd)[i], str1, ft_strlen((*cmd)[i])) && ft_strlen(str1) == 1)
			(*cmd)[i][0] = ' ';
		else if (!ft_strncmp((*cmd)[i], str2, ft_strlen((*cmd)[i])) && ft_strlen(str2) == 1)
			(*cmd)[i][0] = ' ';
		i++;
	}
}

size_t	ft_countredir(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while(str && str[i])
	{
		if (str[i] == 60 || str[i] == 62)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_countredir2(char *str, t_term *term)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
		// printf ("-----------------\n%s\n-----------------\n", str);
	while(str && str[i])
	{
		if (str[i] == 34)
		{
			if (term->double_q == 0)
				term->double_q = 1;
			else
				term->double_q = 0;
		}
		else if (str[i] == 39)
		{
			if (term->single_q == 0)
				term->single_q = 1;
			else
				term->single_q = 0;
		}
		if ((str[i] == 60 || str[i] == 62) && (term->single_q == 0 && term->double_q == 0))
			count++;
		i++;
	}
	return (count);
}

// int	ft_last_cmd(t_term *term, int x)
// {
// 	int	len;
// 	char last_c;

// 	len = ft_matrixlen(term->cmd[x]);
// 	last_c = term->cmd[x][len -1][ft_strlen(term->cmd[x][len -1]) - 1];
// 	if (!ft_strncmp(term->cmd[x][len -1], ">>", 2) && ft_strlen(term->cmd[x][len -1]) == 2)
// 		return (-1);
// 	if (!ft_strncmp(term->cmd[x][len -1], "<<", 2) && ft_strlen(term->cmd[x][len -1]) == 2)
// 		return (-1);
// 	if (!ft_strncmp(term->cmd[x][len -1], ">", 1) && ft_strlen(term->cmd[x][len -1]) == 1)
// 		return (-1);
// 	if (!ft_strncmp(term->cmd[x][len -1], "<", 1) && ft_strlen(term->cmd[x][len -1]) == 1)
// 		return (-1);
// 	if (last_c == 60 || last_c == 62)
// 		return(-1);
// 	return (0);
// }

int	ft_checkredirline(t_term *term, int x)
{
	(void)x;
	int		i;
	int		count;
	char	*str;

	str = term->prompt;
	count = 0;
	i = 0;
	// if (ft_matrixlen(term->cmd[x]) == 1 && ft_last_cmd(term, x) == -1)
	// 	return (ft_perror("SuPerBasH: syntax error near unexpected token 'newline'"));
	//printf("primo comando [%s]\nultimo comando[%s]\n", *term->cmd[x], term->cmd[x][ft_matrixlen(term->cmd[x]) - 1]);
	while (str && str[i])
	{
		count = 1;
		while (str[i] == 60)
		{
			if (count > 2 || str[i + 1] == 62)
				return (ft_perror("SuPerBasH: syntax error near unexpected token '<'"));
			count++;
			i++;
		}
		// if (str[i] == ' ' && (str[i + 1] == 60 || str[i + 1] == 62) && count > 1)
		// 	return (ft_perror("SuPerBasH: syntax error near unexpected token stronzo"));
		while (str[i] == 62)
		{
			if (count > 2 || str[i + 1] == 60)
				return (ft_perror("SuPerBasH: syntax error near unexpected token '>'"));
			i++;
			count++;
		}
		if (str[i] == ' ' && (str[i + 1] == 60 || str[i + 1] == 62) && count > 1)
			return (ft_perror("SuPerBasH: syntax error near unexpected token"));
		i++;
	}
	if (ft_isredir(str[ft_strlen(str) - 1]))
		return (ft_perror("SuPerBasH: parse error near '\\n'"));
	return (0);
}

int	ft_nredir_count(char *line, char *c)
{
	int	n1;
	int n2;
	int	i;
	
	n1 = 0;
	n2 = 0;
	i = 0;
	//printf("[%s]\n", c);
	while (line && line[i])
	{
		if (line[i] == c[0])
		{
			if (ft_strlen(c) == 1)
			{
				if (line[i + 1] != c[0])
					n1++;
				else
					i++;
			}
			else if (line[i + 1] == c[1])
				n2++;
		}
		i++;
	}
	if (ft_strlen(c) == 1)
		return (n1);
	else
		return (n2);
}

int ft_str_nredir_count(int x, char **cmd, char *c)
{
	int	count;

	count = 0;
	while (cmd && cmd[x])
	{
		if (ft_nredir_count(cmd[x], c) > 0)
			count++;
		x++;
	}
	return (count);
}

int	ft_check_file(char ***cmd, int x, t_term *term)
{
	int ret;
	ret = 0;

	if (ft_nredir_count((*cmd)[x - 1], ">") > 0)
	{
		term->i = open((*cmd)[x], O_RDWR | O_CREAT | O_TRUNC , 0644);
		if (term->i == -1)
			return (0);
		dup2(term->i, 1);
	}
	else if (ft_nredir_count((*cmd)[x - 1], "<") > 0)
	{
		term->i = open((*cmd)[x], O_RDONLY);
		if (term->i == -1)
		{
			// dup2(term->fd_1, 1);
			printf("SuPerBash: %s: No such file or directory\n", (*cmd)[x]);
			ret = -1;
		}
		else
			dup2(term->i, 0);
		// if (ft_str_nredir_count(x, *cmd, ">") > 0)
			// close(term->i);
	}
	else if (ft_nredir_count((*cmd)[x - 1], ">>") > 0)
	{
		term->i = open((*cmd)[x], O_RDWR | O_APPEND |O_CREAT, 0644);
		if (term->i == -1)
			return (0);
		// if (ft_str_nredir_count(x, *cmd, ">>") == 0 && ft_str_nredir_count(x, *cmd, ">") == 0)
			dup2(term->i, 1);
	}
	else if (ft_nredir_count((*cmd)[x - 1], "<<") > 0)
	{
		if (ft_redir_imput(term, cmd) == -1)
			return(-1);
	}
	// 	char **tmp = NULL;
	// 	int	check = ft_nredir_count((*cmd)[0], "<<");
	// 	int fd = dup(1);
	// 	term->i = open("temp", O_RDWR | O_CREAT, 0644);
	// 	// line  = (*cmd)[x - 1];
	// 	while (1)
	// 	{
	// 		line = readline("> ");
	// 		if (!line || !line[0])
	// 			continue ;
	// 		if (!ft_strncmp((*cmd)[x], line, ft_strlen((*cmd)[x])) && ft_strlen(line) == ft_strlen((*cmd)[x]))
	// 			break ;
	// 		if (check == 0)
	// 		{
	// 			if (!ft_strncmp((*cmd)[x], line, ft_strlen((*cmd)[x])) && ft_strlen(line) == ft_strlen((*cmd)[x]))
	// 				break ;
	// 			if (line)
	// 				ft_matrix_add(&tmp, line);
	// 			free(line);
	// 		}
	// 	}
	// 	free(line);
	// 	if (tmp && tmp[0] )//&& !ft_check_builtin((*cmd)))
	// 	{
	// 		dup2(term->i, 1);
	// 		ft_matrixprint(tmp);
	// 		ft_matrixfree(tmp);
	// 		close (term->i);
	// 		term->i = open("temp", O_RDONLY);
	// 		dup2(term->i, 0);
	// 		dup2(fd, 1);
	// 	}
	// }
	
	ft_matrix_remove(cmd, (*cmd)[x - 1]);
	ft_matrix_remove(cmd, (*cmd)[x - 1]);
	return (ret);
}

int	ft_redir_imput(t_term *term, char ***cmd)
{
	//int	x;

	//x = 0;
	if (ft_str_nredir_count(0, *cmd, "<<") > 0)
	{
		char	*line;
		int		x;

		x = 0;
		line = NULL;
		char **tmp = NULL;
		int	check = ft_nredir_count((*cmd)[0], "<<");
		while (ft_nredir_count((*cmd)[x], "<<") != 1)
			x++;
		x++;
		int fd = dup(1); //per salvarmi l'fd ereditato dal padre
		dup2(term->fd_1, 1); //per visualizzare la readline in caso l'fd originale sia stato cambiato con fd[1]
		term->i = open("temp", O_RDWR | O_CREAT, 0644);
		while (1)
		{
			line = readline("> ");
			if (!line)
				return (-1);
			if (!ft_strncmp((*cmd)[x], line, ft_strlen((*cmd)[x])) && ft_strlen(line) == ft_strlen((*cmd)[x]))
				break ;
			if (check == 0)
			{
				ft_matrix_add(&tmp, line);
				free(line);
			}
		}
		free(line);
		if (check > 0 || tmp == NULL || !tmp[0])
			return (-1);
		dup2(term->i, 1); //per scrivere dentro il file
		ft_matrixprint(tmp);
		ft_matrixfree(tmp);
		close (term->i);
		term->i = open("temp", O_RDONLY);
		dup2(term->i, 0); //per leggere dal file
		dup2(fd, 1); //ristoro l'output sull' fd ereditato dal padre

		// ft_matrix_remove(cmd, (*cmd)[x - 1]);
		// ft_matrix_remove(cmd, (*cmd)[x - 1]);
	}
	return (0);
}

// void	ft_rebuild_block(t_term *term, char ***block)
// {
// 	int		pos;
// 	int 	path_line;
// 	int		i;
// 	char	**tmp;

// 	i = 0;
// 	tmp = NULL;
// 	path_line = ft_findpath(term);
// 	pos = ft_findcmd(term->info.env_copy[path_line], *block);
// 	// printf("%d\n", pos);
// 	while (i < pos && pos != -1)
// 	{
// 		ft_matrix_add(&tmp, (*block)[0]);
// 		//ft_matrixprint(*block);
// 		ft_matrix_remove(block, (*block)[0]);
// 		ft_matrix_add(block, tmp[i]);
// 		i++;
// 	}
// 	ft_matrixfree(tmp);
// }


int	ft_manageredir(t_term *term, char ***cmd)
{
	int	y;
	int n;
	int	i;

	i = 0;
	n = 0;
	y = 0;
	int check = ft_check_specialcase(cmd);
	if (ft_countredir(term->prompt) > 0)
	{
		// (*cmd) = ft_special_realloc(*cmd);
		// printf("[%s]\n", (*cmd)[check]);
		if (check != -1)
		{
			//while (((*cmd)[check][i] != 39 && (*cmd)[check][i] != 34) || ((*cmd)[check][i +1 ] == 34 || (*cmd)[check][i +1 ] == 39))
				
			while((*cmd)[check][i])
			{
				if ((*cmd)[check][i] == 39 || (*cmd)[check][i] == 34)
					{
						(*cmd)[check] =	ft_remove_char((*cmd)[check], i);
						continue ;
					}
				if (!(*cmd)[check][i])
					break ;
				i++;
			}
		}
		i = -1;
		// 	ft_find_replace(cmd);
		while(cmd && (*cmd)[++i])
		{
			// printf()
			if (ft_countredir2((*cmd)[i], term) > 0)
				n++;
		}
		//ft_matrixprint(*cmd);
		//puts("----------------");
		// puts("-----------------");
		while (n--)
		{
			y = 0;
			while (ft_countredir2((*cmd)[y], term) == 0 && (*cmd)[y])
				y++;
			y++;
			if (ft_check_file(cmd, y, term) == -1)
				return (-1);
				
		}
		// 	ft_matrixprint(*cmd);
		// puts("-----------------");
	 }
	ft_quoteclean(cmd);
	return (1);
}