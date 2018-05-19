/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/19 13:47:01 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_frame *stacks, int move)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = stacks->moves;
	new->prev = stacks->moves->prev;
	stacks->moves->prev->next = new;
	stacks->moves->prev = new;
}

void	create_moves(t_frame *stacks, int move)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = new;
	new->prev = new;
	stacks->moves = new;
}

void	delete_move(t_frame *stacks, t_moves *move)
{
	if (stacks->moves)
	{
		move->prev->next = move->next;
		move->next->prev = move->prev;
		free(move);
		move = NULL;
	}
}
