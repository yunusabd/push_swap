/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/12 22:31:04 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			qs_b(t_frame *stacks, int len);
void			quicksort(t_frame *stacks, int len);

int				count_list(t_clist *stack)
{
	t_clist	*tmp;
	int		elements;

	if (!stack)
		return (0);
	tmp = stack;
	elements = 1;
	while (tmp != stack->prev)
	{
		elements++;
		tmp = tmp->next;
	}
	return (elements);
}

void			sort_array(int *arr, int end)
{
	int	i;
	int	j;

	i = 0;
	while (i < end - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			j = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = j;
			i = 0;
		}
		else
			i++;
	}
}

static int		*list_to_array(t_clist *stack)
{
	int		*arr;
	int		i;
	t_clist	*tmp;

	if (!stack || !(arr = (int*)malloc(sizeof(*arr) * count_list(stack))))
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp != stack->prev)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	arr[i] = tmp->data;
	return (arr);
}

int				get_median(t_clist *stack, int len)
{
	int	*arr;
	int	ret;
	int	i;

	arr = list_to_array(stack);
	sort_array(arr, len);
	i = 0;
	while (arr[i])
		i++;
	ret = arr[len / 2];
	free(arr);
	return (ret);
}

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
	int	max;
	int	i;

	if (!(stacks->b) || len == 1)
	{
		pa(stacks);
		return ;
	}
	max = 0;
	median = get_median(stacks->b, len);
	while (stacks->b)
		max += smart_rotate(stacks);
	i = 0;
	while (i++ < max)
		ra(stacks);
	return ;
}

void			quicksort(t_frame *stacks, int len)
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
	while (i++ < len)
	{
		if (stacks->a->data <= median)
		{
			pb(stacks);
			top++;
		}
		else
			ra(stacks);
	}
	if (stacks->b)
		qs_b(stacks, top);
	i = 0;
	while (i++ < (len - top))
		pb(stacks);
	while (stacks->b)
		qs_b(stacks, top);
	return ;
}

int				solver(t_frame *stacks)
{
	int len;

	len = count_list(stacks->a);
	quicksort(stacks, len);
	if (right_order(stacks))
	{
		while (!is_sorted(stacks))
		{
			stacks->a = stacks->a->next;
			write(1, "ra\n", 3);
		}
	}
	display_printf(stacks, 0 , 0);
	return (1);
}
