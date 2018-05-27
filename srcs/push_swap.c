/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/27 20:38:26 by yabdulha         ###   ########.fr       */
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
			ft_printf("%s%s\033[0m\n", get_color(mv), m[mv]);
		else
			ft_printf("%s\n", m[mv]);
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
	ft_printf("--> %d moves for %d numbers.\n", i, count_list(stacks->a));
}

static void		print_usage(void)
{
	ft_printf("Usage:\n\t./push_swap \"50 40 60\" OR ./push_swap 50 40 60\n");
	ft_printf("Options:\n\t[-c (colored moves)]\n");
	ft_printf("\t[-m (count # of moves)]\n\t[-n (hide moves)]\n");
	ft_printf("\t[-u (usage)]\n");
	ft_printf("Combined use:\n\t/push_swap \"50 40 60\" | ");
	ft_printf("./checker \"50 40 60\"\n");
}

static void		special_handler(t_frame *s)
{
	t_clist *new;

	new = NULL;
	new = normalize(s, new, 0, 0);
	free_stacks(s);
	s->a = new;
	create_moves(s, 11);
	if (is_sorted(s) && (s->flags & MOVES))
		print_moves_count(s);
	if (is_sorted(s))
		exit_push_swap(s);
	if (s->a->data == 1 && s->a->next->data == 3 && s->a->next->next->data == 2)
		jt(SA, s);
	if (s->a->data == 3 && s->a->next->data == 2 && s->a->next->next->data == 1)
		jt(SA, s);
	if (s->a->data == 2 && s->a->next->data == 3 && s->a->next->next->data == 1)
		jt(RRA, s);
	if (s->a->data == 2 && s->a->next->data == 1 && s->a->next->next->data == 3)
		jt(SA, s);
	if (s->a->data == 3 && s->a->next->data == 1 && s->a->next->next->data == 2)
		jt(RA, s);
}

int				main(int ac, char **av)
{
	t_frame		*stacks;

	if (ac < 2)
		return (0);
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (0);
	stacks->b = NULL;
	stacks->moves = NULL;
	parser(av, stacks);
	if (stacks->a && (stacks->flags & USAGE))
		print_usage();
	if (!(stacks->a) || stacks->flags & USAGE)
		exit_push_swap(stacks);
	(is_sorted(stacks) || count_list(stacks->a) == 3) ?
		special_handler(stacks) : solver(stacks);
	while (optimizer(stacks, stacks->moves) == 1)
		ac++;
	(stacks->flags & MOVES) ? print_moves_count(stacks) : print_moves(stacks);
	free_stacks(stacks);
	free(stacks);
	return (0);
}
