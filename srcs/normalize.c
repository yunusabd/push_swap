/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/21 22:04:24 by yabdulha         ###   ########.fr       */
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

	if (!(stack))
		return (-1);
	arr = list_to_array(stack);
	sort_array(arr, len);
	ret = arr[len / 2];
	free(arr);
	return (ret);
}

t_clist			*normalize(t_frame *stacks, t_clist *new, int i, int j)
{
	int		*arr;
	int		*unsorted;
	int		len;

	len = count_list(stacks->a);
	if (!(arr = list_to_array(stacks->a)) ||
			(!(unsorted = list_to_array(stacks->a))))
		error_exit(stacks);
	sort_array(arr, len);
	i = len;
	while (i--)
	{
		j = 0;
		while (j < len)
		{
			if (unsorted[i] == arr[j] && (!new))
				new = create_clist(j + 1, stacks);
			else if (unsorted[i] == arr[j])
				add_to_top(&new, j + 1, stacks);
			j++;
		}
	}
	free(unsorted);
	free(arr);
	return (new);
}
