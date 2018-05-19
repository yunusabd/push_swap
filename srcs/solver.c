/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/19 15:07:29 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			split_a(t_frame *stacks, int len);
void			quicksort(t_frame *stacks, int len);

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

void			do_rotate_a(int nb, t_frame *stacks)
{
	while (nb != 0)
	{
		//index_compare(stacks);
		(nb < 0) ? jt(1, stacks) : jt(4, stacks);
		nb += (nb < 0) ? 1 : -1;
	}
}

/*
 ** Returns the number of moves from current position to nb.
 */

int				get_dist(t_clist *stack, int nb)
{
	int		i;
	t_clist	*tmp;
	t_clist	*tmp2;

	i = 0;
	tmp = stack;
	tmp2 = stack;
	while (tmp != stack->prev)
	{
		if (tmp->data == nb)
			return (i);
		else if (tmp2->data == nb)
			return ((-i));
		i++;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return (-1);
}

void			go_shortest_b(t_frame *stacks, int nb)
{
	int		distance;

	if (!stacks->b)
		return ;
	distance = get_dist(stacks->b, nb);
	do_rotate(distance, stacks);
}	

void			smart_rotate(t_frame *stacks)
{
	t_rotate	*info;

	if (!stacks->a)
		return ;
	info = parse_info(stacks->b);
	if ((ABS(info->maxdist)) - 2 <= (ABS(info->mindist)))
	{
		if ((ABS(get_dist(stacks->b, info->max - 1))) < (ABS(info->maxdist)))
		{
			go_shortest_b(stacks, info->max - 1);
			pa(stacks);
			go_shortest_b(stacks, info->max);
			pa(stacks);
			sa(stacks);
		}
		else
		{
			go_shortest_b(stacks, info->max);
			pa(stacks);
		}
	}
	else
	{
		if ((ABS(get_dist(stacks->b, info->min + 1))) < (ABS(info->mindist)))
		{
			go_shortest_b(stacks, info->min + 1);
			pa(stacks);
			go_shortest_b(stacks, info->min);
			pa(stacks);
			ra(stacks);
			ra(stacks);
		}
		else
		{
			go_shortest_b(stacks, info->min);
			pa(stacks);
			ra(stacks);
		}
	}
	free(info);
}

void			sort_back_a(t_frame *stacks, int len)
{
	int	median;
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	median = get_median(stacks->a, len);
	while (i++ < len)
	{
		if (stacks->a->data <= median)
		{
			pb(stacks);
		}
		else
		{
			pb(stacks);
			rb(stacks);
			tmp++;
		}
	}
	while (tmp--)
		rrb(stacks);
}

void			sort_back(t_frame *stacks, int len)
{
	int	median;
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	median = get_median(stacks->b, len / 2);
	while (i++ < len)
	{
		if (stacks->b->data >= median)
		{
			pa(stacks);
			tmp++;
		}
		else
			rb(stacks);
	}
//	split_a(stacks, tmp);
	sort_back_a(stacks, tmp);
}

void			split_a(t_frame *stacks, int len)
{
	int	median;
	int	i;
	int	counter;
	int	flag;

	if (!(stacks->a))
		return ;
	if (len == 2 && (count_list(stacks->a) == 2))
	{
		(stacks->a->data > stacks->a->next->data) ? sa(stacks) : 0;
		while ((stacks->b))
			smart_rotate(stacks);
		return ;
	}
	if (len == 2)
		return ;
	i = 0;
	counter = 0;
	median = get_median(stacks->a, len);
	flag = 0;
	while (i++ < len)
	{
		if (stacks->a->data < median)
		{
			while (flag > 0)
			{
				rb(stacks);
				flag--;
			}
			if (stacks->a->data < median / 2)
				flag++;
			pb(stacks);
			counter++;
		}
		else
		{
			if (stacks->b && stacks->moves->prev->move != PB &&
					stacks->b->data < median / 2)
				flag++;
			else if (stacks->b && stacks->moves->prev->move != PB
					&& stacks->b->data > median / 2 &&
					stacks->b->next->data < median / 2)
			{
				sb(stacks);
				flag++;
			}
			if (flag > 0)
			{
				rr(stacks);
				flag--;
			}
			else
				ra(stacks);
		}
	}
	if (counter > 20)
		sort_back(stacks, counter);
	split_a(stacks, len - counter);
	return ;
}

void			quicksort(t_frame *stacks, int len)
{
	split_a(stacks, len);
	return ;
}

int				solver(t_frame *stacks)
{
	int		len;
	t_clist	*tmp;
	t_clist	*new;
	int		i;

	new = normalize(stacks, NULL, 0, 0);
	stacks->a = new;
	stacks->b = NULL;
	len = count_list(stacks->a);
	quicksort(stacks, len);
	tmp = stacks->a;
	if (right_order(stacks->a))
	{
		i = 0;
		while (i++ < len / 2 && tmp->data != 1)
			tmp = tmp->next;
		while (!is_sorted(stacks))
			jt((i < len / 2) ? 4 : 1, stacks);
	}
	//print_stacks(stacks);
	return (1);
}
