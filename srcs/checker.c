/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/12 20:51:52 by yabdulha         ###   ########.fr       */
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
	get_input(stacks);
	print_stacks(stacks);
	printf((check_duplicate(stacks->a) == 1) ? "\nno duplicates\n" : "\nduplicates found\n");
	printf((is_sorted(stacks) == 1) ? "sorted\n" : "not sorted\n");
	free_stacks(stacks);
	return (0);
}
