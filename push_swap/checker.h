/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:46:04 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 12:53:09 by fulloa-s         ###   ########.fr       */
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
	struct	s_cmd	*next;
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

// PARSING
void	ft_parsing(int argc, char **argv, t_stack *stacks);
int		ft_atoi(const char *str, t_num **stack_a);
int		ft_atoinumb(const char *str, long int i, long int sign, t_num **stack_a);
int		ft_isdigit(int c);
void	ft_error(t_num **node);
void	ft_checkstr(char *str, t_stack *stacks);
int		count_words(char *str, char c);
char	*malloc_word(char *str, char c);
char	**ft_split(char const *s, char c);
void	ft_check_duplicate(t_stack *stacks);
void	ft_readcmd(t_stack *stacks);
int 	get_next_line(char **line);
void	ft_checkline(char *line, t_stack *stacks);
int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	ft_bzero(void *s, size_t n);
void	ft_clean_checker(t_num **stack);

// MOVES

void	ft_moves(t_stack *stacks);
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

// OK KO
void	ft_lastcheck(t_stack *stacks);

// PUSH_SWAP

void 	ft_rightmove(t_stack *stacks);
void	ft_threemoves(t_stack *stacks);
void	ft_fivemoves(t_stack *stacks);
int		ft_sorted(t_num *stack);
void 	ft_putchar(char c);
void 	ft_putstr(char *str);
void	ft_subsequence(t_stack *stacks);
void	ft_findflag(t_stack *stacks);
// NEW
void	ft_hundred(t_stack *stacks);
void	ft_initflag(t_stack *stacks);
void	ft_definechunk(t_stack *stacks);
void	ft_findchunk(t_stack *stacks);
void	ft_range(t_stack *stacks);
int 	ft_rev_sorted(t_num *stack);

// NEW NEW

t_num		*ft_findmin(t_num *stack);
t_num		*ft_findmax(t_num *stack);
void		ft_sortclone(t_stack *stacks);
void		ft_clone(t_stack *stacks);
void		ft_choice(t_stack *stacks, t_num *stack, t_num *num);
int			ft_count(t_num *stack, t_num *num, int m);
void		ft_initcmd(t_stack *stacks);


// PRINT
void	ft_print(t_stack *stacks, t_cmd *tmp);
void	ft_print_swap(t_stack *stacks);


#endif