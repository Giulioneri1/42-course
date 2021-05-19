/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:43:45 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 17:27:26 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_cmd	*ft_newcmd(char *str)
{
	t_cmd	*new;
	int len;

	len = ft_strlen(str);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = malloc(sizeof(char) * (len + 1));
	ft_memcpy(new->cmd, str, len + 1);
	new->cmd[len] = '\0';
	new->next = NULL;
	return (new);
}

t_num	*ft_newnode(int num)
{
	t_num	*new;

	new = (t_num *)malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->number = num;
	new->next = NULL;
	return (new);
}

t_num	*ft_lstnode(t_num *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_cmd	*ft_lstnodecmd(t_cmd *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_lstadd_back(t_num **node, t_num *new)
{
	if (!*node)
		*node = new;
	else
		ft_lstnode(*node)->next = new;
	new->next = NULL;
}

void	ft_lstadd_backcmd(t_cmd **node, t_cmd *new)
{
	if (!*node)
		*node = new;
	else
		ft_lstnodecmd(*node)->next = new;
	new->next = NULL;
}

void	ft_lstadd_front(t_num **lst, t_num *new)
{
	if(!*lst)
		new->next = 0;
	else
		new->next = *lst;
	*lst = new;
}

int	ft_atoinumb(const char *str, long int i, long int sign, t_num **stack_a)
{
	long int	number;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	number = number * sign;
	if (number > 2147483647 || number < -2147483648)
		ft_error(stack_a);
	return (number);
}

int	ft_atoi(const char *str, t_num **stack_a)
{
	long int	i;
	long int	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}	
	res = ft_atoinumb(str, i, sign, stack_a);
	return ((int)res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_count_words(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

char	*ft_malloc_word(char *str, char c)
{
	char	*ptr;
	char	*tmp1;
	char	*tmp2;
	size_t	count;

	count = 0;
	tmp1 = str;
	while (*str && *str != c)
	{
		count++;
		str++;
	}
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	tmp2 = ptr;
	while (*tmp1 && *tmp1 != c)
		*ptr++ = *tmp1++;
	*ptr = '\0';
	return (tmp2);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	**tmp;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words((char *)s, c);
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			*ptr++ = ft_malloc_word((char *)s, c);
			while (*s && *s != c)
				s++;
		}
	}
	*ptr = NULL;
	return (tmp);
}

void	ft_checkline(char *line, t_stack *stacks)
{
	int i;
	
	i = 0;
	if (ft_strlen(line) != 2 && ft_strlen(line) != 3)
		ft_error(&stacks->stack_a);
	if (ft_strlen(line) == 2 && (ft_strncmp(line, "sa", 2) != 0 && \
	ft_strncmp(line, "sb", 2) != 0 && ft_strncmp(line, "ss", 2) != 0 && \
	ft_strncmp(line, "pa", 2) != 0 && ft_strncmp(line, "pb", 2) != 0 && \
	ft_strncmp(line, "ra", 2) != 0 && ft_strncmp(line, "rb", 2) != 0 && \
	ft_strncmp(line, "rr", 2) != 0))
		ft_error(&stacks->stack_a);
	if (ft_strlen(line) == 3 && (ft_strncmp(line, "rra", 3) != 0 && \
	ft_strncmp(line, "rrb", 3) != 0 && ft_strncmp(line, "rrr", 3) != 0))
		ft_error(&stacks->stack_a);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((((unsigned char *)s1)[i]) - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_error(t_num **stack)
{
	ft_clean_checker(stack);
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_clean_checker(t_num **stack)
{
	t_num *ptr;
	t_cmd *ptr_2;
	
	while (*stack)
	{
		ptr = (*stack)->next;
		(*stack)->number = 0;
		free(*stack);
		(*stack) = ptr;
	}	
}


void	ft_clean(t_num **stack)
{
	t_num *ptr;
	t_cmd *ptr_2;
	
	while (*stack)
	{
		ptr = (*stack)->next;
		(*stack)->number = 0;
		if((*stack)->cmd)
		{
			while((*stack)->cmd)
			{
				ptr_2 = (*stack)->cmd->next;
				free((*stack)->cmd->cmd);
				free((*stack)->cmd);
				(*stack)->cmd = ptr_2;
			}
		}
		free(*stack);
		(*stack) = ptr;
	}	
}

void	ft_cleancmd(t_cmd **cmds)
{
	t_cmd *ptr;
	
	while ((*cmds))
	{
		ptr = (*cmds)->next;
		ft_bzero((*cmds)->cmd, ft_strlen((*cmds)->cmd));
		free((*cmds)->cmd);
		free(*cmds);
		(*cmds) = ptr;
	}	
}

void	ft_checkstr(char *str, t_stack *stacks)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i])|| str[i] == ' ' || (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		else
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
}

void	ft_parsing(int argc, char **argv, t_stack *stacks)
{
	int		i;
	int		j;
	int		num;
	t_num	*newnode;
	char	**numbers;
	
	stacks->head = 0;
	i = 1;
	while (i < argc)
	{
		ft_checkstr(argv[i], stacks);
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
		{
			num = ft_atoi(numbers[j], &stacks->stack_a);
			if (!(stacks->head))
			{
				stacks->stack_a = ft_newnode(num);
				stacks->head = 1;
			}
			else
			{
				newnode = ft_newnode(num);
				ft_lstadd_back(&stacks->stack_a, newnode);
			}
			free(numbers[j]);
			j++;
		}
		i++;
		free(numbers);
	}
}

void	ft_check_duplicate(t_stack *stacks)
{
	t_num *tmp;
	t_num *tmp2;
	int num;
	int num2;

	tmp = stacks->stack_a;
	while (tmp)
	{
		num = tmp->number;
		tmp2 = tmp; 
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
			num2 = tmp2->number;
			if (num == num2)
				ft_error(&stacks->stack_a);
		}
		tmp = tmp->next;
	}
}
