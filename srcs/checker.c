/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 15:11:16 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_line			*parse_stack(t_clist *stack)
{
	t_clist	*tmp;
	t_line	*t;
	t_line	*new;
	t_line	*head;

	if (!stack)
		return (NULL);
	head = (t_line*)malloc(sizeof(*new));
	head->s = ft_itoa(stack->data);
	head->next = NULL;
	tmp = stack->next;
	t = head;
	while (tmp && tmp != stack)
	{
		while (t->next != NULL)
			t = t->next;
		new = (t_line*)malloc(sizeof(*new));
		new->s = ft_itoa(tmp->data);
		new->next = NULL;
		t->next = new;
		tmp = tmp->next;
	}
	return (head);
}

void			display_stacks(t_frame *stacks, char *command)
{
	t_line	*a;
	t_line	*b;

	a = parse_stack(stacks->a);
	b = parse_stack(stacks->b);
	usleep((stacks->flags & SLOW) ? 1000000 : 100000);
	printf("\E[H\E[2J");
	printf("\E[48;55;208m");
	printf("\033[1m\033[35m");
	printf("%15s   %-15s", "Stack A", "Stack B");
	if (stacks->flags & COLORS)
		printf("\tCurrent move:\t%s%s\033[0m\n", get_color(stacks->moves->move),
				command);
	else
		printf("\tCurrent move:\t%s\n", command);
	printf("\n");
	while (a || b)
	{
		printf("\t%7s | %s\n", a ? a->s : " ", b ? b->s : " ");
		a = (a) ? a->next : a;
		b = (b) ? b->next : b;
	}
	printf("\E[48;5;208m");
	printf("\033[35m");
	printf("\033[0m");
}

static void		print_usage(void)
{
	printf("Usage:\n\t./push_swap \"50 40 60\" OR ./checker \"50 40 60\"\n");
	printf("Options:\n\t[-c (colored moves)]\n\t[-v (visualize moves)]");
	printf("\n\t[-s (set visualizer speed to slow)]");
	printf("\t[-m (count # of moves)]\n\t[-h (hide moves)] [-u (usage)]\n");
	printf("Combined use:\n\t/push_swap \"50 40 60\" | ");
	printf("./checker \"50 40 60\"\n");
}

int				main(int ac, char **av)
{
	int			i;
	t_frame		*stacks;

	if (ac < 2)
	{
		print_usage();
		return (0);
	}
	i = 1;
	stacks = (t_frame*)malloc(sizeof(*stacks));
	stacks->b = NULL;
	create_moves(stacks, 11);
	parser(av, stacks);
	if (stacks->flags & USAGE)
	{
		print_usage();
		error_exit(stacks);
	}
	get_input(stacks);
	if (stacks->flags & VISUALIZER)
		display_stacks(stacks, "\033[31;5;mEND\033[0m");
	printf((is_sorted(stacks) == 1) ? "OK\n" : "KO\n");
	free_stacks(stacks);
	free(stacks);
	return (0);
}
