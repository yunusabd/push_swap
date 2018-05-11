/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/11 17:57:23 by yabdulha         ###   ########.fr       */
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

	arr = (int*)malloc(sizeof(*arr) * count_list(stack));
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
		if (ret->data < tmp->data)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

/*
** Check min, count distance to head to rotate and reverse rotate.
** Same for max. Execute smaller value.
*/
/*
t_rotate		*smart_rotate(t_clist *stack)
{
	int			minpos;
	int			maxpos;
	t_rotate	*info;
	t_clist		*tmp;

	if (!stack)
		return (NULL);
	info = (t_rotate*)malloc(sizeof(*info));
	counter = 0;
	info->minptr = get_min_ptr(stack);
	info->maxptr = get_max_ptr(stack);
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp == minptr)
			minpos = counter;
		else if (tmp == maxptr)
			maxpos = counter;
		tmp = tmp->next;
		counter++;
	}
	len = count_list(stack);
	if (minpos < maxpos)
	{
		if (len - minpos < len - maxpos)
	}

	return (info);
}
*/

void			qs_b(t_frame *stacks, int len)
{
	int	i;
	int	top;
	int	median;
	int	max;

	if (!(stacks->b) || len == 1)
	{
		pa(stacks);
		return ;
	}
	top = 0;
	max = 0;
	median = get_median(stacks->b, len);
	while (stacks->b)
	{
		if (stacks->b->next == stacks->b)
		{
			pa(stacks);
			ra(stacks);
			top++;
			max++;
		}
		else if (stacks->b->data == get_max(stacks->b))
		{
			pa(stacks);
			top++;
		}
		else if (stacks->b->data == get_min(stacks->b))
		{
			pa(stacks);
			ra(stacks);
			top++;
			max++;
		}
		else
			rb(stacks);
	}
	i = 0;
	while (i < max)
	{
		rra(stacks);
		i++;
	}
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
	median = get_median(stacks->a, len);
	while (i < len)
	{
		if (stacks->a->data <= median)
		{
			pb(stacks);
			top++;
		}
		else
			ra(stacks);
		i++;
	}
	if (stacks->b)
		qs_b(stacks, top);
	i = 0;
	while (i < top)
	{
		ra(stacks);
		i++;
	}
	i = 0;
	while (i < (len - top))
	{
		pb(stacks);
		i++;
	}
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
			stacks->a = stacks->a->next;
	}
	return (1);
}
