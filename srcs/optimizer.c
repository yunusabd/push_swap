/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:08:41 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/19 13:48:31 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		optimizer(t_frame *stacks, t_moves *moves)
{
	t_moves	*tmp;

	tmp = moves;
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
	tmp = moves;
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
	tmp = moves;
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
	tmp = moves;
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

