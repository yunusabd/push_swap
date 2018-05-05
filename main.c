/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/05 18:42:51 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int			i;
	t_clist		*a;
	t_clist		*tmp;

	i = 1;
	a = parser(av);
	tmp = a;
	while (a->next != tmp)
	{
		printf(" => %d", a->data);
		a = a->next;
	}
	printf(" => %d\n", a->data);
	printf((check_duplicate(a) == 1) ? "OK\n" : "KO\n");
}
