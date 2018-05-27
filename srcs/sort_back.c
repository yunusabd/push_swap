/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:41:38 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/26 01:18:00 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			smart_rotate(t_frame *stacks)
{
	t_rotate	*info;

	if (!(stacks->a) || !(info = parse_info(stacks->b)))
		return ;
	if ((ABS(info->maxdist)) - 1 <= (ABS(info->mindist)) &&
		((ABS(info->maxdist)) - 1 <= (ABS(info->mindist2))))
		push_biggest(stacks, info);
	else if (stacks->p ^ 1 && (ABS(info->maxdist2)) - 1 <= (ABS(info->mindist))
			&& (ABS(info->maxdist2)) - 1 <= (ABS(info->mindist2)))
		push_biggest(stacks, info);
	else
		push_smallest(stacks, info);
	free(info);
}

void			sort_back_a(t_frame *stacks, int len)
{
	int	median;
	int	i;

	i = 0;
	median = get_median(stacks->a, len);
	while (i++ < len)
	{
		if (stacks->a->data >= median)
			pb(stacks);
		else
		{
			pb(stacks);
			rb(stacks);
		}
	}
}

int				sort_back(t_frame *stacks, int len)
{
	int	median;
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	median = get_median(stacks->b, len);
	while (i++ < len)
	{
		if (stacks->b->data > median)
		{
			pa(stacks);
			tmp++;
		}
		else
		{
			rb(stacks);
		}
	}
	return (tmp);
}
