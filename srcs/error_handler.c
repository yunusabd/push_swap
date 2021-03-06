/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:04:28 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/27 19:24:33 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stacks->moves = NULL;
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
	free_moves(stacks);
}

void		error_exit(t_frame *stacks)
{
	free_stacks(stacks);
	free(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

void		exit_push_swap(t_frame *stacks)
{
	free_stacks(stacks);
	free(stacks);
	exit(0);
}
