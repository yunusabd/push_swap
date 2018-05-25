/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:41:38 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/25 01:01:38 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If nb is negative, rotate stack b back by nb, otherwise rotate forward.
*/

void			do_rotate(int nb, t_frame *stacks)
{
	while (nb != 0)
	{
		(nb < 0) ? jt(2, stacks) : jt(5, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}

void			do_rotate_a(int nb, t_frame *stacks)
{
	while (nb != 0)
	{
		(nb < 0) ? jt(1, stacks) : jt(4, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}

void			go_shortest_b(t_frame *stacks, int nb)
{
	int		distance;

	if (!stacks->b)
		return ;
	distance = get_dist(stacks->b, nb);
	do_rotate(distance, stacks);
}

void			push_biggest(t_frame *stacks, t_rotate *info)
{
	if (stacks->p ^ 1 &&
			(ABS(get_dist(stacks->b, info->max - 1))) < (ABS(info->maxdist)))
	{
		go_shortest_b(stacks, info->max - 1);
		pa(stacks);
		stacks->p ^= 1;
	}
	else
	{
		go_shortest_b(stacks, info->max);
		pa(stacks);
		if (stacks->p & 1)
		{
			sa(stacks);
			stacks->p ^= 1;
		}
	}
}

void			push_smallest(t_frame *stacks, t_rotate *info)
{
	if ((ABS(get_dist(stacks->b, info->min + 1))) < (ABS(info->mindist)))
	{
		go_shortest_b(stacks, info->min + 1);
		pa(stacks);
		go_shortest_b(stacks, info->min);
		pa(stacks);
		ra(stacks);
		ra(stacks);
	}
	else
	{
		go_shortest_b(stacks, info->min);
		pa(stacks);
		ra(stacks);
	}
}
