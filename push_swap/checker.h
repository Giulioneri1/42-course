/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:04:04 by gneri             #+#    #+#             */
/*   Updated: 2021/05/18 15:04:07 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char			*cmd;
	int				count;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_num
{
	int				count;
	int				number;
	int				flag;
	char			*move;
	char			sub_c;
	char			max_max;
	t_cmd			*cmd;
	struct s_num	*next;

}	t_num;

typedef struct s_stack
{
	t_num	*stack_a;
	t_num	*stack_b;
	t_num	*max_a;
	t_num	*min_a;
	t_num	*clone;
	t_cmd	*cmds;
	int		chunk;
	int		chunks;
	int		head;
	int		range;
	int		max_number;
	int		min_number;
	int		max_flag;
}	t_stack;

// LIST
t_num	*ft_newnode(int num);
t_num	*ft_lstnode(t_num *node);
t_cmd	*ft_lstnodecmd(t_cmd *node);
t_cmd	*ft_newcmd(char *str);
void	ft_lstadd_back(t_num **node, t_num *new);
void	ft_lstadd_backcmd(t_cmd **node, t_cmd *new);
void	ft_clean(t_num **head);
void	ft_lstadd_front(t_num **lst, t_num *new);
void	ft_cleancmd(t_cmd **cmds);
int		ft_lstsize(t_num *lst);
int		ft_lstsizecmd(t_cmd *lst);
void	ft_parse_numbers(t_stack *stacks, char **numbers);
void	ft_parsing(int argc, char **argv, t_stack *stacks);
int		ft_atoi(char *str, t_num **stack_a);
int		ft_atoinumb(char *str, long int i, long int sign, t_num **stack_a);
int		ft_isdigit(int c);
void	ft_error(t_num **node);
void	ft_checkstr(char *str, t_stack *stacks);
int		ft_count_words(char *str, char c);
char	*ft_malloc_word(char *str, char c);
char	**ft_split(char const *s, char c);
void	ft_check_duplicate(t_stack *stacks);
void	ft_readcmd(t_stack *stacks);
int		ft_get_next_line(char **line);
void	ft_checkline(char *line, t_stack *stacks);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	ft_bzero(void *s, size_t n);
void	ft_clean_checker(t_num **stack);
void	ft_moves(t_stack *stacks);
void	ft_moves2(t_stack *stacks, t_cmd *tmp);
void	ft_sa(t_stack *stacks);
void	ft_sb(t_stack *stacks);
void	ft_ra(t_stack *stacks);
void	ft_rra(t_stack *stacks);
void	ft_pa(t_stack *stacks);
void	ft_pb(t_stack *stacks);
void	ft_rb(t_stack *stacks);
void	ft_rrb(t_stack *stacks);
void	ft_pbmove(t_stack *stacks);
void	ft_pamove(t_stack *stacks);
void	ft_rbmove(t_stack *stacks);
void	ft_ramove(t_stack *stacks);
void	ft_rrbmove(t_stack *stacks);
void	ft_rramove(t_stack *stacks);
void	ft_samove(t_stack *stacks);
void	ft_sbmove(t_stack *stacks);
void	ft_ra_clone(t_stack *stacks);
void	ft_rrmove(t_stack *stacks);
void	ft_rrrmove(t_stack *stacks);
void	ft_lastcheck(t_stack *stacks);
void	ft_rightmove(t_stack *stacks);
void	ft_three_numbers(t_stack *stacks);
void	ft_five_numbers(t_stack *stacks);
int		ft_sorted(t_num *stack);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_subsequence(t_stack *stacks);
void	ft_findflag(t_stack *stacks);
void	ft_initflag(t_stack *stacks);
t_num	*ft_findmin(t_num *stack);
t_num	*ft_findmax(t_num *stack);
void	ft_sortclone(t_stack *stacks);
void	ft_clone(t_stack *stacks);
void	ft_choice(t_stack *stacks, t_num *stack, t_num *num);
int		ft_count(t_num *stack, t_num *num, int m);
int		ft_count2(t_num *stack, t_num *num, int m, int count);
void	ft_initcmd(t_stack *stacks);
void	ft_algorithm(t_stack *stacks);
void	ft_exec_algorithm(t_stack *stacks, t_num *head_b);
void	ft_print_moves(t_stack *stacks);
void	ft_clean_algorithm(t_stack *stacks);
void	ft_realmove(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a);
void	ft_clean_algorithm(t_stack *stacks);
int		ft_find_doubles(t_cmd **node, t_cmd *tmp_b, t_cmd *tmp_a);
void	ft_moves_list(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a);
void	ft_cmds_list(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a);
void	ft_pa_node(t_cmd **node);
void	ft_rr_node(t_cmd **node);
void	ft_rrr_node(t_cmd **node);
void	ft_to_top_a(t_num *stack, t_num *node, t_cmd **cmd);
void	ft_to_top_a2(t_cmd **cmd, int len);
void	ft_to_top_b(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd);
void	ft_to_top_b2(t_cmd **cmd, int len);
void	ft_pos_in_a(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd);
void	ft_five_numbers2(t_stack *stacks, t_num	*head_a, t_num	*head_b);
void	ft_five_numbers3(t_stack *stacks, t_num	*head_a, t_num	*head_b, int m);
void	ft_findsub(t_stack *stacks);
void	ft_findrealsub(t_stack *stacks);
void	ft_ra_clone(t_stack *stacks);
void	ft_sortclone(t_stack *stacks);
void	ft_clone(t_stack *stacks);

#endif
