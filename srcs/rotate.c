/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:11:27 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/11 17:49:33 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_frame *stacks)
{
	if (stacks->a && stacks->a->next)
	{
		stacks->a = stacks->a->next;
		write(1, "ra\n", 3);
	}
}

void		rb(t_frame *stacks)
{
	if (stacks->b && stacks->b->next)
	{
		stacks->b = stacks->b->next;
		write(1, "rb\n", 3);
	}
}

void		rr(t_frame *stacks)
{
	ra(stacks);
	rb(stacks);
	write(1, "rr\n", 3);
}
