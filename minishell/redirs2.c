/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vspinell <vspinell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:27 by vspinell          #+#    #+#             */
/*   Updated: 2021/10/22 19:26:54 by vspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isredir(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

char	**ft_special_realloc(char **cmd)
{
	char **tmp = NULL;
	int	i;
	int	y;
	char	*str;
	int	len;

	i = 0;
	//while (i < x)
	//	ft_matrix_add(&tmp, cmd[i]);
	while (cmd[i])
	{
		if (ft_countredir(cmd[i]) != ft_strlen(cmd[i]))
		{
			y = 0;
			// int count = 0;
			while (cmd[i][y])
			{
				if (!ft_isredir(cmd[i][y]))
				{
					len = 0;
					while (!ft_isredir(cmd[i][y]) && cmd[i][y])
					{
						y++;
						len++;
					}
					str = malloc(len + 1);
					ft_memcpy(str, cmd[i] + (y - len), len);
					str[len] = '\0';
					ft_matrix_add(&tmp, str);
					free(str);
				}
				else
				{
					len = 0;
					while ((cmd[i][y] == '>' || cmd[i][y] == '<') && cmd[i][y])
					{
						len++;
						y++;
					}
					str = malloc(len + 1);
					ft_memcpy(str, cmd[i] + (y - len), len);
					str[len] = '\0';
					ft_matrix_add(&tmp, str);
					free(str);
				}
			}
		}
		else
			ft_matrix_add(&tmp, cmd[i]);
		i++;
	}
	// ft_matrix_add(&tmp, NULL);
	ft_matrixfree(cmd);
	//ft_matrixprint(tmp);
	return (tmp);
}

char	*ft_remove_char(char *str, int pos)
{
	char	*tmp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tmp = malloc(ft_strlen(str));
	while (str && str[i])
	{
		if (i != pos)
			tmp[y++] = str[i];
		i++;
	}
	tmp[y] = '\0';
	free(str);
	return (tmp);
}

void	ft_quoteclean(char ***cmd)
{
	int	i;
	int	d_q;
	int	s_q;
	int	y;

	i = 0;
	s_q = 0; // single quotes = 39
	d_q = 0; //double quotes = 34
	while (*cmd && (*cmd)[i])
	{
		y = 0;
		// puts ("------------------");
		// puts((*cmd)[i]);
		// puts ("------------------");
		while ((*cmd)[i][y])
		{
			if (((*cmd)[i][y] == 34 && s_q == 0) || ((*cmd)[i][y] == 34 && d_q == 1))
			{
				if (d_q == 0)
					d_q = 1;
				else
					d_q = 0;
				(*cmd)[i] = ft_remove_char((*cmd)[i], y);
				if (!(*cmd)[i][y])
					break ;
				if ((*cmd)[i][y] == 34 || (*cmd)[i][y] == 39)
					continue ;
			}
			else if (((*cmd)[i][y] == 39 && d_q == 0) || ((*cmd)[i][y] == 39 && s_q == 1))
			{
				if (s_q == 0)
					s_q = 1;
				else
					s_q = 0;
				(*cmd)[i] = ft_remove_char((*cmd)[i], y);
				if (!(*cmd)[i][y])
					break ;
				if ((*cmd)[i][y] == 39 || (*cmd)[i][y] == 34)
					continue ;
			}
			y++;
			//if ((*cmd)[i] != (*cmd)[0])
			//printf("%d) single [%d] double [%d]\n", y, s_q, d_q);
		}
		i++;
	}
	// if (s_q == 1 || d_q == 1)
	// {
	// 	printf("SuPerBasH:~$: unexpected EOF while looking for matching quotes\n");
	// 	return (0);
	// }
}

int	ft_check_specialcase(char ***cmd)
{
	int	i;
	int	d_q;
	int	s_q;
	int	y;
	int u;

	u = 0;
	i = 0;
	s_q = 0; // single quotes = 39
	d_q = 0; //double quotes = 34
	while (*cmd && (*cmd)[i])
	{
		y = 0;
		while ((*cmd)[i][y])
		{
			if (((*cmd)[i][y] == 34 && s_q == 0) || ((*cmd)[i][y] == 34 && d_q == 1))
			{
				if (d_q == 0)
				{
					d_q = 1;
					u = i;
				}
				else
					d_q = 0;
			}
			else if (((*cmd)[i][y] == 39 && d_q == 0) || ((*cmd)[i][y] == 39 && s_q == 1))
			{
				if (s_q == 0)
				{
					s_q = 1;
					u = i;
				}
				else
					s_q = 0;
			}
			y++;
		}
		i++;
	}
	if (s_q == 1 || d_q == 1)
		return (u);
	return (-1);
}