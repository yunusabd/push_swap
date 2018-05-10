/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:53:10 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/10 20:46:49 by yabdulha         ###   ########.fr       */
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

void			upper(t_frame *stacks, int len)
{
	int		i;
	int		median;
	int		top;


	if (len < 2)
		return ;
	top = 0;
	printf("len: %d\n", len);
	i = 0;
	
	median = get_median(stacks->a, len);
	printf("median %d\n", median);
	while (i < len)
	{
		printf("stacks->a->data: %d ", stacks->a->data);
		if (stacks->a->data > median)
		{
			printf("push to b");
			pb(stacks);
			top++;
		}
		else
		{
			printf("rotate a");
			ra(stacks);
		}
		printf("\n");
		i++;
	}
	printf("after pushing to b\n");
	display_printf(stacks, 0, 0);
	while (stacks->b)
		qs_b(stacks, top);
	i = 0;
	printf("\n-------------\n");
	display_printf(stacks, 0, 0);
	printf("\n-------------\n");
	while (i < top)
	{
		ra(stacks);
		i++;
	}
	display_printf(stacks, 0, 0);
	return ;
	printf("median %d, top: %d\n", median, top);
	return ;

}

void			qs_b(t_frame *stacks, int len)
{
	int	i;
	int	top;
	int	median;

	if (len == 1)
	{
		pa(stacks);
		return ;
	}
	i = 0;
	top = 0;
	median = get_median(stacks->b, len);
	while (i < len)
	{
		printf("stacks->b->data: %d ", stacks->b->data);
		if (stacks->b->data >= median)
		{
			printf("push to a");
			pa(stacks);
			top++;
		}
		else
		{
			printf("rotate b");
			rb(stacks);
		}
			printf("\n");
		i++;
	}
	if (stacks->b)
		qs_b(stacks, len - top);
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
	printf("len: %d\n", len);
	i = 0;
	
	median = get_median(stacks->a, len);
	printf("median %d\n", median);
	while (i < len)
	{
		printf("stacks->a->data: %d ", stacks->a->data);
		if (stacks->a->data <= median)
		{
			printf("push to b");
			pb(stacks);
			top++;
		}
		else
		{
			printf("rotate a");
			ra(stacks);
		}
		printf("\n");
		i++;
	}
	printf("after pushing to b\n");
	display_printf(stacks, 0, 0);
	while (stacks->b)
		qs_b(stacks, top);
	i = 0;
	printf("\n-------------\n");
	display_printf(stacks, 0, 0);
	printf("\n-------------\n");
	while (i < top)
	{
		ra(stacks);
		i++;
	}
	display_printf(stacks, 0, 0);
	upper(stacks, len - top);
	return ;
	printf("median %d, top: %d\n", median, top);
	return ;
}

int				solver(t_frame *stacks)
{
	int len;

	len = count_list(stacks->a);
	printf("Right order: %d\n", right_order(stacks));
//	while (!is_sorted(stacks))
//		quicksort(stacks, len);
	return (1);
}
