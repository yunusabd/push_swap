/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:55:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 22:30:43 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stacks(t_frame *stacks)
{
	t_clist		*tmp;

	tmp = stacks->a;
	printf("%s\n", "Stack A");
	while (stacks->a->next != tmp)
	{
		printf("%d ", stacks->a->data);
		stacks->a = stacks->a->next;
	}
	if (stacks->a)
	printf("%d\n", stacks->a->data);

	printf("%s\n", "Stack B");
	tmp = stacks->b;
	while (stacks->b && stacks->b->next != tmp)
	{
		printf("%d ", stacks->b->data);
		stacks->b = stacks->b->next;
	}
	if (stacks->b)
		printf("%d\n", stacks->b->data);
}
