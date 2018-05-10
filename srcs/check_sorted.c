/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:59:44 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/10 20:51:31 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_frame *stacks)
{
	int			len;
	t_clist		*tmp;

	if (!stacks->a || (stacks->b))
		return (0);
	len = count_list(stacks->a);
	tmp = stacks->a;
	while (len && tmp && tmp != stacks->a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
		len--;
	}
	return (1);
}

/*
** Check if elements are in the right order, but the first element isn't 
** neccessarily the smallest number.
*/

int		right_order(t_frame *stacks)
{
	int			nb;
	t_clist		*tmp;

	if (!stacks->a || (stacks->b))
		return (0);
	if (count_list(stacks->a) < 2)
		return (1);
	nb = stacks->a->data;
	tmp = stacks->a->next;
	while (nb != stacks->a->prev->data)
	{
		printf("nb: %d, tmp: %d\n", nb, tmp->data);
		if (nb >= tmp->data)
			return (0);
		nb = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}
