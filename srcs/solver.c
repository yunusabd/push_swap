/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/07 22:42:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	arr[i] = tmp->data;
	return (arr);
}

int				get_median(t_clist *stack, int len)
{
	int	*arr;

	arr = list_to_array(stack);
	sort_array(arr, len);
	return (arr[len / 2]);
}

void			quicksort(t_frame *stacks, int len, int i)
{
	int		top_half_len;
	int		median;

	printf("depth: %d, len: %d\n", i, len);
	i++;
	if (len == 1)
		return ;
	median = get_median(stacks->a, len);
	top_half_len = 0;
	i = 0;
	while (i < len)
	{
		if (stacks->a->data >= median)
		{
			pb(stacks);
			top_half_len++;
		}
		else
			ra(stacks);
		i++;
	}
	i = 0;
	while (i < len - top_half_len)
	{
		rra(stacks);
		i++;
	}
	i = 0;
	while (i < top_half_len)
	{
		pa(stacks);
		i++;
	}
	printf("\n-------1------\n");
	print_stacks(stacks);
	printf("\n-------2------\n");
	quicksort(stacks, top_half_len, i);
	i = 0;
	while (i < top_half_len)
	{
		printf("\nrra\n");
		ra(stacks);
		i++;
	}
	print_stacks(stacks);
	quicksort(stacks, len - top_half_len, i);
}

int				solver(t_frame *stacks)
{
	quicksort(stacks, count_list(stacks->a), 0);
	return (1);
}
