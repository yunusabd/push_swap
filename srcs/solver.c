/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:41:38 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/25 00:48:25 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				greater_median(t_frame *stacks, int median, int flag)
{
	if (stacks->a->data >= (median / 4))
	{
		if (flag > 0 && flag--)
			rr(stacks);
		else
			ra(stacks);
	}
	else
		ra(stacks);
	return (flag);
}

int				finish(t_frame *stacks)
{
	(stacks->a->data > stacks->a->next->data) ? sa(stacks) : 0;
	while ((stacks->b))
		smart_rotate(stacks);
	return (1);
}

static void		resplit(t_frame *stacks, int min, int counter)
{
	int	pushed;

	pushed = sort_back(stacks, min);
	sort_back_a(stacks, sort_back(stacks, counter - min));
	sort_back_a(stacks, pushed);
}

void			split_a(t_frame *stacks, int len, int i, int flag)
{
	int	median;
	int	counter;
	int	min;

	if ((len == 2 || len == 1) && finish(stacks))
		return ;
	counter = 0;
	median = get_median(stacks->a, len);
	min = 0;
	while (i++ < len)
	{
		if (stacks->a->data <= median)
		{
			while (flag > 0 && flag--)
				rb(stacks);
			if (stacks->a->data < (median / 2) && flag++ >= 0)
				min++;
			pb(stacks);
			counter++;
		}
		else
			flag = greater_median(stacks, median, flag);
	}
	(counter > 20) ? resplit(stacks, min, counter) : 0;
	split_a(stacks, len - counter, 0, 0);
}

int				solver(t_frame *stacks)
{
	int		len;
	t_clist	*tmp;
	t_clist	*new;
	int		i;

	new = NULL;
	new = normalize(stacks, new, 0, 0);
	free_stacks(stacks);
	stacks->a = new;
	stacks->b = NULL;
	stacks->moves = NULL;
	stacks->p = 0;
	create_moves(stacks, 11);
	len = count_list(stacks->a);
	split_a(stacks, len, 0, 0);
	tmp = stacks->a;
	if (right_order(stacks->a))
	{
		i = 0;
		while (i++ < (len / 2) && tmp->data != 1)
			tmp = tmp->next;
		while (!is_sorted(stacks))
			jt((i < (len / 2)) ? 4 : 1, stacks);
	}
	return (1);
}
