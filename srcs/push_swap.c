/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/23 18:20:34 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_moves(t_frame *stacks)
{
	int			mv;
	static char	*m[12] = {"rrr", "rra", "rrb", "rr", "ra", "rb",
		"ss", "sa", "sb", "pa", "pb", "start"};

	if (stacks->flags & HIDE)
		return ;
	stacks->moves = stacks->moves->next;
	while (stacks->moves->move != 11)
	{
		mv = stacks->moves->move;
		if (stacks->flags & COLORS)
			printf("%s%s\033[0m\n", get_color(mv), m[mv]);
		else
			printf("%s\n", m[mv]);
		stacks->moves = stacks->moves->next;
	}
}

static void		print_moves_count(t_frame *stacks)
{
	t_moves	*tmp;
	int		i;

	i = 0;
	tmp = stacks->moves;
	while (tmp != stacks->moves->prev)
	{
		tmp = tmp->next;
		i++;
	}
	printf("--> %d moves for %d numbers.\n", i, count_list(stacks->a));
}

static void		print_usage()
{
	printf("Usage:\n\t./push_swap \"50 40 60\" OR ./push_swap 50 40 60\n");
	printf("Options:\n\t[-c (colored moves)]\n");
	printf("\t[-m (count # of moves)]\n\t[-h (hide moves)]\n\t[-u (usage)]\n");
	printf("Combined use:\n\t/push_swap \"50 40 60\" | ");
	printf("./checker \"50 40 60\"\n");
}

int				main(int ac, char **av)
{
	t_frame		*stacks;

	if (ac < 2)
	{
		print_usage();
		return (0);
	}
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (0);
	stacks->b = NULL;
	stacks->moves = NULL;
	parser(av, stacks);
	if (stacks->flags & USAGE)
	{
		print_usage();
		error_exit(stacks);
	}
	solver(stacks);
	while (optimizer(stacks, stacks->moves) == 1)
		ac++;
	if (stacks->flags & MOVES)
		print_moves_count(stacks);
	else
		print_moves(stacks);
	free_stacks(stacks);
	free(stacks);
	return (0);
}
