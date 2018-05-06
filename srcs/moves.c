/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 16:55:36 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Put second element to head->previous, move head there
*/

void		sa(t_frame *stacks)
{
	int		tmp;

	if (stacks->a && stacks->a != stacks->a->next)
	{
		tmp = stacks->a->data;
		stacks->a->data = stacks->a->next->data;
		stacks->a->next->data = tmp;
	}
}

void		sb(t_frame *stacks)
{
	int		tmp;

	if (stacks->b && stacks->b != stacks->b->next)
	{
		tmp = stacks->b->data;
		stacks->b->data = stacks->b->next->data;
		stacks->b->next->data = tmp;
	}
}

void		ss(t_frame *stacks)
{
	sa(stacks);
	sb(stacks);
}

void		pa(t_frame *stacks)
{
	if (!(stacks->b))
		return ;
	if (stacks->a)
		add_to_top(&stacks->a, stacks->b->data);
	else
		stacks->a = create_clist(stacks->b->data);
	remove_head(&(stacks->b));
}

void		pb(t_frame *stacks)
{
	if (!(stacks->a))
		return ;
	if (stacks->b)
		add_to_top(&stacks->b, stacks->a->data);
	else
		stacks->b = create_clist(stacks->a->data);
	remove_head(&(stacks->a));
}

void		ra(t_frame *stacks)
{
	if (stacks->a && stacks->a->next)
		stacks->a = stacks->a->next;
}

void		rb(t_frame *stacks)
{
	if (stacks->b && stacks->b->next)
		stacks->b = stacks->b->next;
}

void		rr(t_frame *stacks)
{
	ra(stacks);
	rb(stacks);
}

void		rra(t_frame *stacks)
{
	if (stacks->a && stacks->a->prev)
		stacks->a = stacks->a->prev;
}

void		rrb(t_frame *stacks)
{
	if (stacks->b && stacks->b->prev)
		stacks->b = stacks->b->prev;
}

void		rrr(t_frame *stacks)
{
	rra(stacks);
	rrb(stacks);
}
