/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/17 17:20:40 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	int			len;
	t_frame		*stacks;
	static char	*m[12] = {"rrr", "rra", "rrb", "rr", "ra", "rb",
		"ss", "sa", "sb", "pa", "pb", "start"};

	ac += 0;
	i = 1;
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (1);
	stacks->b = NULL;
	create_moves(stacks, 11);
	parser(av, stacks);
	len = count_list(stacks->a);
	solver(stacks);
	while (optimizer(stacks, stacks->moves) == 1)
		i++;
	while (stacks->moves)
	{
		printf("%s\n", m[stacks->moves->move]);
		stacks->moves = stacks->moves->next;
	}
	free_stacks(stacks);
	return (0);
}
