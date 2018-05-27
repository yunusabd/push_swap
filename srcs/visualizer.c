/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/27 20:26:04 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		free_numbers(t_line *x)
{
	t_line	*tmp;

	if (x)
	{
		while (x != NULL)
		{
			tmp = x->next;
			free(x->s);
			free(x);
			x = tmp;
		}
	}
}

static t_line	*create_line_element(t_clist *stack)
{
	t_line	*new;

	if (!(new = (t_line*)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->s = ft_itoa_base_max((intmax_t)stack->data, 10)))
		return (NULL);
	new->next = NULL;
	return (new);
}

static t_line	*parse_stack(t_clist *stack)
{
	t_clist	*tmp;
	t_line	*t;
	t_line	*head;

	if (!stack || (!(head = create_line_element(stack))))
		return (NULL);
	tmp = stack->next;
	if (tmp == stack)
		return (head);
	t = head;
	while (tmp && tmp != stack)
	{
		if (!(t->next = create_line_element(tmp)))
		{
			free_numbers(head);
			return (NULL);
		}
		t = t->next;
		tmp = tmp->next;
	}
	return (head);
}

static void		print_vis(t_frame *stacks, char *command, int i)
{
	t_line	*a;
	t_line	*b;
	t_line	*tmp;
	t_line	*tmp2;

	a = parse_stack(stacks->a);
	b = parse_stack(stacks->b);
	if (!(a || b))
		return ;
	tmp = a;
	tmp2 = b;
	if (stacks->flags & COLORS)
		ft_printf("\tCurrent move:\t%s%s\n", get_color(i), command);
	else
		ft_printf("\tCurrent move:\t%s\n", command);
	ft_printf("%s", get_color(stacks->moves->move));
	ft_printf("\033[0m");
	while (a || b)
	{
		ft_printf("\t%7s | %s\n", a ? a->s : " ", b ? b->s : " ");
		a = (a) ? a->next : a;
		b = (b) ? b->next : b;
	}
	free_numbers(tmp);
	free_numbers(tmp2);
}

void			init_vis(t_frame *stacks, char *command, int i)
{
	usleep((stacks->flags & SLOW) ? 1000000 : 100000);
	ft_printf("\E[H\E[2J");
	ft_printf("\033[1m\033[34m");
	ft_printf("%15s   %-15s\x1b[0m", "Stack A", "Stack B");
	print_vis(stacks, command, i);
	ft_printf("\e[48;5;208m");
	ft_printf("\033[35m");
	ft_printf("\033[0m");
}
