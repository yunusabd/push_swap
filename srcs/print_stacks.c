/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:55:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/25 00:58:26 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_frame *stacks)
{
	t_clist		*tmp;

	tmp = stacks->a;
	printf("%s", "Stack A: ");
	while (tmp && tmp != stacks->a->prev)
	{
		printf("[%5d] ", tmp->data);
		tmp = tmp->next;
	}
	if (tmp)
		printf("[%5d]\n", tmp->data);
	printf("%s", "Stack B: ");
	tmp = stacks->b;
	while (tmp && tmp != stacks->b->prev)
	{
		printf("[%5d] ", tmp->data);
		tmp = tmp->next;
	}
	if (tmp)
		printf("[%5d]", tmp->data);
	printf("\n");
}
