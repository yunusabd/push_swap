/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 00:12:53 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/17 02:26:07 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_frame *stacks, int move)
{
	t_moves	*new;
	t_moves *tmp;

	if (!(new = (t_moves*)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = NULL;
	tmp = stacks->moves;
	while ((tmp->next))
		tmp = tmp->next;
	tmp->next = new;
}

void	create_moves(t_frame *stacks, int move)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(*new))))
		error_exit(stacks);
	new->move = move;
	new->next = NULL;
	stacks->moves = new;
}

void	delete_move(t_frame *stacks, t_moves *move)
{
	t_moves	*tmp;

	tmp = stacks->moves;
	while (tmp->next != move)
		tmp = tmp->next;
	if (move->next)
		tmp->next = move->next;
	else
		tmp->next = NULL;
	free(move);
}
