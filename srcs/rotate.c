/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/17 17:17:36 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_frame *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		stacks->a = stacks->a->next;
		add_list(stacks, RA);
	}
}

void		rb(t_frame *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		stacks->b = stacks->b->next;
		add_list(stacks, RB);
	}
}

void		rr(t_frame *stacks)
{
	ra(stacks);
	rb(stacks);
}
