/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:59:44 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/07 01:10:30 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_frame *stacks)
{
	t_clist		*tmp;

	if (stacks->b || !(stacks->a))
		return (0);
	tmp = stacks->a;
	while (tmp && tmp != stacks->a->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
