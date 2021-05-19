/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundredmoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:29:19 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/05/13 17:21:44 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_initflag(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->stack_a;
	while (tmp)
	{
		tmp->count = 0;
		tmp->flag = 1;
		tmp->sub_c = '0';
		tmp->move = NULL;
		tmp = tmp->next;
	}
	tmp = stacks->clone;
	while (tmp)
	{
		tmp->count = 0;
		tmp->flag = 1;
		tmp->sub_c = '0';
		tmp->move = NULL;
		tmp = tmp->next;
	}
}

void	ft_findrealsub(t_stack *stacks)
{
	t_num	*tmp_a;
	t_num	*tmp_c;

	tmp_c = stacks->clone;
	while(tmp_c)
	{
		tmp_a = stacks->stack_a;
		while (tmp_a)
		{
			if(tmp_c->sub_c == '*' && tmp_c->number == tmp_a->number)
			{
				tmp_a->sub_c = '*';
				break ;
			}
			tmp_a = tmp_a->next;
		}
		tmp_c = tmp_c->next;
	}
}

void	ft_findsub(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*tmp2;

	while(stacks->max_flag)
	{
		tmp = stacks->clone;
		while(tmp && tmp->sub_c == '0')
		{
			if(tmp->flag == stacks->max_flag)
				tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->sub_c = '*';
		stacks->max_flag--;	
	}
	ft_findrealsub(stacks);
}

void	ft_findflag(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->clone;
	stacks->max_flag = tmp->flag;
	while(tmp)
	{
		if(tmp->flag > stacks->max_flag)
			stacks->max_flag = tmp->flag;
		tmp = tmp->next;
	}
	ft_findsub(stacks);
}

int		ft_count(t_num *stack, t_num *num, int m)
{
	t_num	*tmp;
	int		lstsize;
	int		len;
	int 	count;

	tmp = stack;
	lstsize = ft_lstsize(stack);
	count = 0;
	while(tmp)
	{
		if(tmp == num)
		{
			len = ft_lstsize(tmp);
			if(len >= m)
			{
				num->move = "ra";
				while(len++ < lstsize)
					count++;
			}
			else
			{
				num->move = "rra";
				while(len-- > 0)
					count++;
			}
		}
		tmp = tmp->next;
	}
	return (count);	
}


void	ft_choice(t_stack *stacks, t_num *stack, t_num *num)
{
	t_num	*tmp;
	int		m;
	int		count_f;
	
	count_f = 0;
	tmp = stack;
 	if (ft_lstsize(stack) % 2 == 0)
		m = ft_lstsize(stack) / 2;
 	else
		m = (ft_lstsize(stack) / 2) + 1;
	if (num)
	{
		count_f = ft_count(stack, num, m);
		if (ft_lstsize(num) >= m)
			while (count_f-- > 0)
				ft_ramove(stacks);
		else
			while (count_f-- > 0)
				ft_rramove(stacks);
	}
}

void	ft_ordersub(t_stack *stacks)
{
	t_num	*tmp;

	tmp = stacks->stack_a;
	while (tmp)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
	tmp = stacks->stack_a;
	while (tmp && tmp->flag != 1)
	{	
		if (tmp->sub_c == '*')
		{
			ft_ramove(stacks);
			tmp->flag = 1;
		}
		else
			ft_pbmove(stacks);
		tmp = stacks->stack_a;
	}
}


void	ft_clone(t_stack *stacks)
{
	t_num	*tmp_a;
	t_num	*newnode;
	
	stacks->clone = NULL;
	tmp_a = stacks->stack_a;
	while(tmp_a)
	{
		if(!stacks->clone)
			stacks->clone = ft_newnode(tmp_a->number);
		else
		{
			newnode = ft_newnode(tmp_a->number);
			ft_lstadd_back(&stacks->clone, newnode);
		}
		tmp_a = tmp_a->next;
	}
	ft_sortclone(stacks);
}

void	ft_sortclone(t_stack *stacks)
{
	t_num	*min;
	t_num	*tmp;

	min = ft_findmin(stacks->clone);
	tmp = stacks->clone;
	while(tmp != min)
	{
		ft_ra_clone(stacks);
		tmp = stacks->clone;
	}
}

void	ft_subsequence(t_stack *stacks)
{
	t_num	*tmp;
	t_num	*tmp2;

	ft_clone(stacks);
	ft_initflag(stacks);
	tmp = stacks->clone;
	while (tmp->next)
	{
		tmp2 = tmp;
		while (tmp2)
		{
			if ((tmp->number < tmp2->number) && (tmp->flag == tmp2->flag))
				tmp2->flag++;
			tmp2 = tmp2->next;	
		}
		tmp = tmp->next;
	}
	ft_findflag(stacks);
	ft_ordersub(stacks);
}


t_num		*ft_findmin(t_num *stack)
{
	t_num	*min;
	t_num	*head_a;
	
	head_a = stack;
	min = head_a;
	while(head_a)
	{
		if(min->number > head_a->number)
			min = head_a;
		head_a = head_a->next;
	}
	return (min);	
}


t_num		*ft_findmax(t_num *stack)
{
	t_num	*max;
	t_num	*head_a;
	
	head_a = stack;
	max = head_a;
	while(head_a)
	{
		if(max->number < head_a->number)
			max = head_a;
		head_a = head_a->next;
	}
	return (max);	
}

void	ft_to_top_b(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd)
{
	t_num	*tmp;
	t_cmd	*newcmd;
	int		len;
	int 	lstsize;
	int		m;
	char	c;
	
	c = '0';
	lstsize = ft_lstsize(stack);
	tmp = stack;
 	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
 	else
		m = (ft_lstsize(tmp) / 2) + 1;
	len = ft_lstsize(node);
	if (len >= m)
		while (len++ < lstsize)
		{
			if(!*cmd)
				*cmd = ft_newcmd("rb");
			else
			{
				newcmd = ft_newcmd("rb");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
	else if (len < m)
		while (len-- > 0)
		{
			if(!*cmd)
				*cmd = ft_newcmd("rrb");
			else
			{
				newcmd = ft_newcmd("rrb");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
}

void	ft_to_top_a(t_num *stack, t_num *node, t_cmd **cmd)
{
	t_num	*tmp;
	t_cmd	*newcmd;
	int		len;
	int 	lstsize;
	int		m;
	
	lstsize = ft_lstsize(stack);
	tmp = stack;
 	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
 	else
		m = (ft_lstsize(tmp) / 2) + 1;
	len = ft_lstsize(node);
	if (len >= m)
		while (len++ < lstsize)
		{
			if(!*cmd)
				*cmd = ft_newcmd("ra");
			else
			{
				newcmd = ft_newcmd("ra");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
	else
		while (len-- > 0)
		{
			if(!*cmd)
				*cmd = ft_newcmd("rra");
			else
			{
				newcmd = ft_newcmd("rra");
				ft_lstadd_backcmd(cmd, newcmd);
			}
		}
}


void	ft_pos_in_a(t_stack *stacks, t_num *stack, t_num *node, t_cmd **cmd)
{
	int m;
	t_num	*tmp;
	t_cmd	*newcmd;

	tmp = stack;
	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
 	else
		m = (ft_lstsize(tmp) / 2) + 1;
	if (node->number < stacks->min_a->number)
		ft_to_top_a(tmp, stacks->min_a, cmd);
	else if (node->number > stacks->max_a->number)
		ft_to_top_a(tmp, stacks->min_a, cmd);			
	else if (node->number < tmp->number && node->number > ft_lstnode(tmp)->number)
		return;
	else
	{
		while(tmp->next)
		{
			if(node->number > tmp->number && node->number < tmp->next->number)
				ft_to_top_a(stack, tmp->next, cmd);
			tmp = tmp->next;
		}
	}
	
}

void	ft_realmove(t_cmd **node, t_cmd *cmd_b, t_cmd *cmd_a)
{
	t_cmd 	*tmp_b;
	t_cmd 	*tmp_a;
	t_cmd	*newcmd;

	tmp_b = cmd_b;
	tmp_a = cmd_a;
	while(tmp_b && tmp_a)
	{
		if(!ft_strncmp(tmp_a->cmd, "ra", 2) && !ft_strncmp(tmp_b->cmd, "rb", 2))
		{
			if(!*node)
				(*node) = ft_newcmd("rr");
			else
			{
				newcmd = ft_newcmd("rr");
				ft_lstadd_backcmd(&(*node), newcmd);
			}
		}
		else if (!ft_strncmp(tmp_a->cmd, "rra", 3) && !ft_strncmp(tmp_b->cmd, "rrb", 3))
		{
			if(!*node)
				(*node) = ft_newcmd("rrr");
			else
			{
				newcmd = ft_newcmd("rrr");
				ft_lstadd_backcmd(&(*node), newcmd);
			}
		}
		else
		{
			if(!*node)
			{

				(*node) = ft_newcmd(cmd_b->cmd);
				newcmd = ft_newcmd(cmd_a->cmd);
				ft_lstadd_backcmd(&(*node), newcmd);
			}
			else
			{
				newcmd = ft_newcmd(cmd_b->cmd);
				ft_lstadd_backcmd(node, newcmd);
				newcmd = ft_newcmd(cmd_a->cmd);
				ft_lstadd_backcmd(&(*node), newcmd);
			}
		}
		tmp_b = tmp_b->next;
		tmp_a = tmp_a->next;
	}
	while(tmp_b)
	{
		if(!*node)
			(*node) = ft_newcmd(cmd_b->cmd);
		else
		{
			newcmd = ft_newcmd(cmd_b->cmd);
			ft_lstadd_backcmd(&(*node), newcmd);
		}
		tmp_b = tmp_b->next;
	}
	while(tmp_a)
	{
		if(!*node)
			(*node) = ft_newcmd(cmd_a->cmd);
		else
		{
			newcmd = ft_newcmd(cmd_a->cmd);
			ft_lstadd_backcmd(&(*node), newcmd);
		}
		tmp_a = tmp_a->next;
	}
	if(!*node)
		(*node) = ft_newcmd("pa");
	else
	{
		newcmd = ft_newcmd("pa");
		ft_lstadd_backcmd(&(*node), newcmd);
	}
	(*node)->count = ft_lstsizecmd((*node));
	
}


void	ft_initcmd(t_stack *stacks)
{
	t_num	*head_a;
	t_num	*head_b;

	head_a = stacks->stack_a;
	head_b = stacks->stack_b;
	while(head_a)
	{
		head_a->cmd = NULL;
		head_a = head_a->next;
	}
	while(head_b)
	{
		head_b->cmd = NULL;
		head_b = head_b->next;
	}
}

void	ft_exec(t_stack *stacks)
{
	t_num	*head_b;
	t_num	*min;
	t_cmd	*tmp;

	head_b = stacks->stack_b;
	min = head_b;
	while(head_b)
	{
		if(head_b->count < min->count)
			min = head_b;
		if(head_b->count < min->count && ft_strncmp(head_b->cmd->cmd, "rr", 2))
			min = head_b;
		head_b = head_b->next;
	}
	tmp = min->cmd;
	
	while (tmp)
	{
		if (!ft_strncmp(tmp->cmd, "ra", 2))
			ft_ramove(stacks);
		else if (!ft_strncmp(tmp->cmd, "rb", 2))
			ft_rbmove(stacks);
		else if (!ft_strncmp(tmp->cmd, "rra", 3))
			ft_rramove(stacks);
		else if (!ft_strncmp(tmp->cmd, "rrb", 3))
			ft_rrbmove(stacks);
		else if (!ft_strncmp(tmp->cmd, "rrr", 3))
			ft_rrrmove(stacks);
		else if (!ft_strncmp(tmp->cmd, "pa", 2))
			ft_pamove(stacks);
		else if (!ft_strncmp(tmp->cmd, "rr", 2))
			ft_rrmove(stacks);
		tmp = tmp->next;
	}			
}

void ft_sort_a(t_stack *stacks)
{
	t_num	*min;
	t_num	*tmp;
	int m;
	int len;

	tmp = stacks->stack_a;
	if (ft_lstsize(tmp) % 2 == 0)
		m = ft_lstsize(tmp) / 2;
 	else
		m = (ft_lstsize(tmp) / 2) + 1;
	min = ft_findmin(stacks->stack_a);
	len = ft_lstsize(min);
	while (!ft_sorted(stacks->stack_a))
	{
		if (len >= m)
			ft_ramove(stacks);
		else
			ft_rramove(stacks);
	}
}


void	ft_finaltry(t_stack *stacks)
{
	t_num	*head_b;
	t_cmd	*cmd_b;
	t_cmd	*cmd_a;
	t_cmd	*newcmd;
	t_num  *head_a;

	int i = 0;


	ft_initcmd(stacks);
	while(stacks->stack_b)
	{
		stacks->min_a = ft_findmin(stacks->stack_a);
		stacks->max_a = ft_findmax(stacks->stack_a);
		head_b = stacks->stack_b;
		while (head_b)
		{
			cmd_b = NULL;
			cmd_a = NULL;
			head_b->cmd = NULL;
			ft_to_top_b(stacks, stacks->stack_b, head_b, &cmd_b);
			ft_pos_in_a(stacks, stacks->stack_a, head_b, &cmd_a);
			ft_realmove(&head_b->cmd, cmd_b, cmd_a);
			head_b->count = head_b->cmd->count;
			ft_cleancmd(&cmd_b);
			ft_cleancmd(&cmd_a);
			head_b = head_b->next;
		}
		ft_exec(stacks);
		head_a = stacks->stack_a;
		head_b = stacks->stack_b;
		while(head_a)
		{
			ft_cleancmd(&head_a->cmd);
			head_a = head_a->next;
		}
		while(head_b)
		{
			ft_cleancmd(&head_b->cmd);
			head_b = head_b->next;
		}
	}
	ft_sort_a(stacks);
}

void	ft_hundred(t_stack *stacks)
{
	ft_subsequence(stacks);
	ft_finaltry(stacks);	
}
