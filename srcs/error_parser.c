/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 22:04:32 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/05 22:08:08 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

/*
** Traverse through the list and check if a number occurs twice.
*/

int			check_duplicate(t_clist *head)
{
	t_clist *tmp1;
	t_clist	*tmp2;

	tmp1 = head;
	while (tmp1 != NULL && tmp1->next != head)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL && tmp2 != head)
		{
			if (tmp2->data == tmp1->data)
			{
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

/*
** Check if the input string only contains '+', '-', ' ' or digits.
*/

int			check_content(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else if (str[i] == '+' && ft_isdigit(str[i + 1]) &&
				(i == 0 || str[i - 1] == ' '))
			i++;
		else
			error_exit("Error\n", 1);
	}
	return (1);
}

/*
** If the number has more than 11 digits, it can't fit into an int -> error.
*/

static int	check_numlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '-' ||
				str[i] == '+' || ft_isdigit(str[i])))
	{
		i++;
		if (i > 11)
			error_exit("Error\n", 1);
	}
	return (i);
}

t_clist		*fill_stack(const char *str, t_clist *a)
{
	long	tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		j = check_numlen(str + i);
		if (str[i] == '\0')
			break ;
		tmp = ft_atoi_long(str + i);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_exit("Error\n", 1);
		if (!a)
			a = create_clist(tmp);
		else
			add_to_tail(a, tmp);
		i += j;
	}
	return (a);
}

void		parser(char **av, t_frame *stacks)
{
	int			i;

	stacks->a = NULL;
	i = 1;
	while (av[i])
	{
		check_content(av[i]);
		stacks->a = fill_stack(av[i], stacks->a);
		i++;
	}
}
