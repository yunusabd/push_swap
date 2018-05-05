/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 01:25:07 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Put second element to head->previous, move head there
*/

void		sa(t_frame *stacks)
{
	t_clist	*tmp;

	if (stacks->a == stacks->a->next)
		return ;
	tmp = stacks->a;
	add_to_top(&stacks->a, stacks->a->next->data);
	remove_element(&stacks->a, tmp->next);
}

void		sb(t_frame *stacks)
{
	t_clist	*tmp;

	if (stacks->b == stacks->b->next)
		return ;
	tmp = stacks->b;
	add_to_top(&stacks->b, stacks->b->next->data);
	remove_element(&stacks->b, tmp->next);
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
	add_to_top(&stacks->a, stacks->b->data);
	remove_element(&stacks->b, stacks->b);
}

void		pb(t_frame *stacks)
{
	if (!(stacks->a))
		return ;
	if (!(stacks->b))
		stacks->b = create_clist(stacks->a->data);
	else
		add_to_top(&stacks->b, stacks->a->data);
	remove_head(&(stacks->a));
}
