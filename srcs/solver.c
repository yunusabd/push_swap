/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/13 04:00:33 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			qs_b(t_frame *stacks, int len);
void			quicksort(t_frame *stacks, int len, int up);

int				get_min(t_clist *stack)
{
	int		ret;
	t_clist	*tmp;

	ret = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (ret > tmp->data)
			ret = tmp->data;
		tmp = tmp->next;
	}
	return (ret);
}

int				get_max(t_clist *stack)
{
	int		ret;
	t_clist	*tmp;

	ret = stack->data;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (ret < tmp->data)
			ret = tmp->data;
		tmp = tmp->next;
	}
	return (ret);
}

t_clist			*get_max_ptr(t_clist *stack)
{
	t_clist	*ret;
	t_clist	*tmp;

	ret = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (ret->data < tmp->data)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

t_clist			*get_min_ptr(t_clist *stack)
{
	t_clist	*ret;
	t_clist	*tmp;

	ret = stack;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (ret->data > tmp->data)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

/*
 ** Check min, count distance to head to rotate and reverse rotate.
 ** Same for max. Execute smaller value.
 */

t_rotate		*parse_info(t_clist *stack)
{
	t_rotate	*info;
	t_clist		*tmp;
	int			counter;

	if (!stack)
		return (NULL);
	info = (t_rotate*)malloc(sizeof(*info));
	counter = 0;
	info->len = count_list(stack);
	info->min = get_min(stack);
	info->max = get_max(stack);
	info->minptr = get_min_ptr(stack);
	info->maxptr = get_max_ptr(stack);
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp == info->minptr)
			info->mindist = counter;
		else if (tmp == info->maxptr)
			info->maxdist = counter;
		tmp = tmp->next;
		counter++;
	}
	if (tmp == info->minptr)
		info->mindist = counter;
	else if (tmp == info->maxptr)
		info->maxdist = counter;
	counter = 0;
	tmp = stack;
	while (tmp != stack->next)
	{
		if (tmp == info->minptr)
			info->mindist = ((ABS(counter)) < info->mindist) ? counter : info->mindist;
		else if (tmp == info->maxptr)
			info->maxdist = ((ABS(counter)) < info->maxdist) ? counter : info->maxdist;
		tmp = tmp->prev;
		counter--;
	}
	if (tmp == info->minptr)
		info->mindist = ((ABS(counter)) < info->mindist) ? counter : info->mindist;
	else if (tmp == info->maxptr)
		info->maxdist = ((ABS(counter)) < info->maxdist) ? counter : info->maxdist;
	return (info);
}

void			index_compare(t_frame *stacks)
{
	if (stacks->b->data - stacks->a->data == -1)
	{
		printf("top b to top a\n");
		pa(stacks);
	}
	if (stacks->b->data - stacks->a->data == 1)
	{
		printf("top b to second a\n");
		pa(stacks);
		sa(stacks);
	}
	else if (stacks->b->data - stacks->a->prev->data == 1)
	{
		printf("top b to bottom a\n");
		rra(stacks);
		pa(stacks);
	}
	else if (stacks->b->data - stacks->a->prev->data == -1)
	{
		printf("top b to second from bottom a\n");
		pa(stacks);
		ra(stacks);
	}
}

/*
 ** If nb is negative, rotate stack b back by nb, otherwise rotate forward.
 */

void			do_rotate(int nb, t_frame *stacks)
{
	while (nb != 0)
	{
		//index_compare(stacks);
		(nb < 0) ? jt(2, stacks) : jt(5, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}


int				smart_rotate(t_frame *stacks)
{
	t_rotate	*info;
	int			rotate;
	int			i;

	info = parse_info(stacks->b);
	i = 0;
	rotate = 0;
	if ((ABS(info->maxdist)) <= (ABS(info->mindist)))
	{
		do_rotate(info->maxdist, stacks);
		pa(stacks);
		rotate++;
	}
	else
	{
		do_rotate(info->mindist, stacks);
		pa(stacks);
		ra(stacks);
	}
	free(info);
	return (rotate);
}

void			qs_b(t_frame *stacks, int len)
{
	int	median;
	int	i;
	int	b_len;
	int	counter;

	print_stacks(stacks);
	if (!(stacks->b) || len == 1)
	{
		printf("len 1\n");
		pa(stacks);
		return ;
	}
	b_len = count_list(stacks->b);
	i = 0;
	counter = 0;
	median = get_median(stacks->b, len);
/*	if (b_len > 10)
	{
		//push it back to a in batches
		printf("greater ten%d\n", i);
		while (i < b_len)
		{
			if (stacks->b->data >= median)
			{
				pa(stacks);
				counter++;
			}
			else
				rb(stacks);
			i++;
		}
		print_stacks(stacks);
		printf("running qsagain\n");
		i = 0;
		quicksort(stacks, counter, 0);
		return ;
	}
*/	while (stacks->b)
		i += smart_rotate(stacks);
	while (i--)
		ra(stacks);
	return ;
}

void			quicksort(t_frame *stacks, int len, int up)
{
	int		i;
	int		median;
	int		top;


	if (len < 2)
		return ;
	top = 0;
	i = 0;
	if (!stacks->a)
		return ;
	median = get_median(stacks->a, len);
	while (i < len)
	{
		if (!up && stacks->a->data <= median)
		{
			if (stacks->a->data <= median / 2)
				pb(stacks);
			else
			{
				pb(stacks);
				rb(stacks);
			}
			top++;
		}
		else if (up)
		{
			if (stacks->a->data <= median)
				pb(stacks);
			else
			{
				pb(stacks);
				rb(stacks);
			}
			top++;
		}
		else
			ra(stacks);
		i++;
	}
	if (stacks->b)
		qs_b(stacks, top);
	quicksort(stacks, (len - top), 1);
	return ;
}

int				solver(t_frame *stacks)
{
	int		len;
	t_frame	*tmp;
	t_clist	*new;
	int		i;

	tmp = stacks;
	new = normalize(stacks, NULL, 0, 0);
	stacks->original = stacks->a;
	stacks->a = new;
	stacks->b = NULL;
	len = count_list(stacks->a);
	quicksort(stacks, len, 0);
	if (right_order(stacks))
	{
		i = 0;
		while (i < len / 2)
			i++;
		if (i < len / 2)
		{
			while (!is_sorted(stacks))
			{
				stacks->a = stacks->a->next;
				write(1, "ra\n", 3);
			}
		}
		else
		{
			while (!is_sorted(stacks))
			{
				stacks->a = stacks->a->prev;
				write(1, "rra\n", 4);
			}
		}
	}
	print_stacks(stacks);
	return (1);
}
