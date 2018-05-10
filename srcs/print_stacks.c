/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:55:23 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/09 21:04:45 by yabdulha         ###   ########.fr       */
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

void display_printf(t_frame *frame, int a_flag, int b_flag)
{
	t_clist		*stack_a;
	t_clist		*stack_b;
	char		*a;
	char		*b;

	stack_a = frame->a;
	stack_b = frame->b;

	a_flag = (!stack_a) ? 1 : 0;
	b_flag = (!stack_b) ? 1 : 0;
	while (1)
	{
		a = (!a_flag) ? ft_itoa(stack_a->data) : ft_strdup("");//protect malloc
		b = (!b_flag) ? ft_itoa(stack_b->data) : ft_strdup("");//protect malloc
		a_flag = (!stack_a || stack_a == frame->a->prev) ? 1 : 0;
		b_flag = (!stack_b || stack_b == frame->b->prev) ? 1 : 0;
		(!stack_a && !stack_b) ? free(a) : 0;
		if ((!stack_a && !stack_b))
			break ;
		printf("%15s | %-15s\n", a, b);
		free(a);
		free(b);
		stack_a = (stack_a && stack_a != frame->a->prev) ? stack_a->next : NULL;
		stack_b = (stack_b && stack_b != frame->b->prev) ? stack_b->next : NULL;
	}
}
