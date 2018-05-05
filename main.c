/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/06 01:26:48 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	t_clist		*tmp;
	t_frame		*stacks;

	ac += 0;
	i = 1;
	stacks = (t_frame*)malloc(sizeof(*stacks));
	stacks->b = NULL;
	parser(av, stacks);
	tmp = stacks->a;
	while (stacks->a->next != tmp)
	{
		printf(" => %d", stacks->a->data);
		stacks->a = stacks->a->next;
	}
	printf(" => %d\n", stacks->a->data);

	stacks->a = tmp;
	remove_head(&(stacks->a));
	remove_head(&(stacks->a));
	remove_head(&(stacks->a));
	remove_head(&(stacks->a));
	remove_head(&(stacks->a));
	//pb(stacks);
	tmp = stacks->a;
	while (stacks->a && stacks->a->next != tmp)
	{
		printf(" => %d", stacks->a->data);
		stacks->a = stacks->a->next;
	}
	printf(" => %d\n", stacks->a->data);

//	printf((check_duplicate(stacks->a) == 1) ? "OK\n" : "KO\n");
	return (0);
}
