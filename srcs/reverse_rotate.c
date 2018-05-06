/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 17:00:46 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
