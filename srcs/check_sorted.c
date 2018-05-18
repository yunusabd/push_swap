/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:59:44 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/18 02:28:50 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_frame *stacks)
{
	t_clist		*tmp;

	if (!stacks->a || (stacks->b))
		return (0);
	tmp = stacks->a;
	while (tmp->next != stacks->a)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->data == tmp->next->data)
		return (0);
	return (1);
}

/*
** Check if elements are in the right order, but the first element isn't 
** neccessarily the smallest number.
*/

int		right_order(t_clist *stack)
{
	int			nb;
	t_clist		*tmp;
	t_clist		*tmp2;

	if (!stack)
		return (0);
	if (count_list(stack) < 2)
		return (1);
	nb = get_min(stack);
	tmp = stack->next;
	while (nb != tmp->data)
		tmp = tmp->next;
	tmp2 = tmp->next;
	while (tmp2 != tmp)
	{
		if (nb >= tmp2->data)
			return (0);
		nb = tmp2->data;
		tmp2 = tmp2->next;
	}
	return (1);
}
