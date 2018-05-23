/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:04:28 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/22 11:45:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error_exit(t_frame *stacks)
{
	free_stacks(stacks);
	exit(1);
}

static void	free_moves(t_frame *stacks)
{
	t_moves	*tmp;

	if (stacks->moves)
	{
		while (stacks->moves != stacks->moves->next)
		{
			tmp = stacks->moves->next;
			delete_move(stacks, stacks->moves);
			stacks->moves = tmp;
		}
		delete_move(stacks, stacks->moves);
	}
}

void		free_stacks(t_frame *stacks)
{
	t_clist	*tmp;

	if (stacks->a)
	{
		while (stacks->a != stacks->a->next)
		{
			tmp = stacks->a->next;
			remove_head(&(stacks->a));
			stacks->a = tmp;
		}
		remove_head(&(stacks->a));
		stacks->a = NULL;
	}
	if (stacks->b)
	{
		while (stacks->b != stacks->b->next)
		{
			tmp = stacks->b->next;
			remove_head(&(stacks->b));
			stacks->b = tmp;
		}
		remove_head(&(stacks->b));
		stacks->b = NULL;
	}
	if (stacks->moves)
		free_moves(stacks);
}
