/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 16:58:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
