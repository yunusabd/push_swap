/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/27 20:48:21 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_usage(void)
{
	ft_printf("Usage:\n\t./push_swap \"50 40 60\" OR ./checker \"50 40 60\"\n");
	ft_printf("Options:\n\t[-c (colored moves)]\n\t[-v (visualize moves)]");
	ft_printf("\n\t[-s (set visualizer speed to slow)]");
	ft_printf("\n\t[-m (count # of moves)]\n");
	ft_printf("\t[-u (usage)] [-h (help)] \n");
	ft_printf("Combined use:\n\t/push_swap \"50 40 60\" | ");
	ft_printf("./checker \"50 40 60\"\n");
}

int				main(int ac, char **av)
{
	t_frame		*stacks;

	if (ac < 2)
		return (0);
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (0);
	stacks->b = NULL;
	create_moves(stacks, 11);
	parser(av, stacks);
	if (stacks->a && (stacks->flags & USAGE))
	{
		print_usage();
		free_stacks(stacks);
		free(stacks);
		return (0);
	}
	if (!(stacks->a))
		exit_push_swap(stacks);
	get_input(stacks);
	if (stacks->flags & VISUALIZER)
		init_vis(stacks, "\033[31;5;mEND\033[0m", 0);
	ft_printf((is_sorted(stacks) == 1) ? "OK\n" : "KO\n");
	free_stacks(stacks);
	free(stacks);
	return (0);
}
