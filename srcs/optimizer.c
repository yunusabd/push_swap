/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:08:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/25 01:03:50 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_ra(t_frame *stacks)
{
	t_moves	*tmp;

	tmp = stacks->moves;
	while (tmp->next != stacks->moves)
	{
		if ((tmp->move == RA && tmp->next->move == RB) ||
				(tmp->move == RB && tmp->next->move == RA))
		{
			delete_move(stacks, tmp->next);
			tmp->move = RR;
			return (1);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

static int	check_pa(t_frame *stacks)
{
	t_moves	*tmp;

	tmp = stacks->moves;
	while (tmp->next != stacks->moves)
	{
		if ((tmp->move == PA && tmp->next->move == PB) ||
				(tmp->move == PB && tmp->next->move == PA))
		{
			delete_move(stacks, tmp->next);
			delete_move(stacks, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	check_rra(t_frame *stacks)
{
	t_moves	*tmp;

	tmp = stacks->moves;
	while (tmp->next != stacks->moves)
	{
		if ((tmp->move == RRA && tmp->next->move == RA) ||
				(tmp->move == RA && tmp->next->move == RRA))
		{
			delete_move(stacks, tmp->next);
			delete_move(stacks, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	check_rrb(t_frame *stacks)
{
	t_moves	*tmp;

	tmp = stacks->moves;
	while (tmp->next != stacks->moves)
	{
		if ((tmp->move == RRB && tmp->next->move == RB) ||
				(tmp->move == RB && tmp->next->move == RRB))
		{
			delete_move(stacks, tmp->next);
			delete_move(stacks, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			optimizer(t_frame *stacks, t_moves *moves)
{
	t_moves	*tmp;

	if (check_ra(stacks))
		return (1);
	if (check_pa(stacks))
		return (1);
	if (check_rra(stacks))
		return (1);
	if (check_rrb(stacks))
		return (1);
	tmp = moves;
	while (tmp->next != stacks->moves)
	{
		if ((tmp->move == SA && tmp->next->move == SB) ||
				(tmp->move == SB && tmp->next->move == SA))
		{
			delete_move(stacks, tmp->next);
			tmp->move = SS;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
