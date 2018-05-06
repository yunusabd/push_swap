/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/06 22:05:34 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_frame		*stacks;

	ac += 0;
	i = 1;
	stacks = (t_frame*)malloc(sizeof(*stacks));
	stacks->b = NULL;
	parser(av, stacks);
	pb(stacks);
	print_stacks(stacks);
	printf((check_duplicate(stacks->a) == 1) ? "OK\n" : "KO\n");
	free_stacks(stacks);
	return (0);
}
