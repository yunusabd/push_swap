/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:08:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/16 14:22:10 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	int			len;
	t_frame		*stacks;

	ac += 0;
	i = 1;
	if (!(stacks = (t_frame*)malloc(sizeof(*stacks))))
		return (1);
	stacks->b = NULL;
	parser(av, stacks);
	len = count_list(stacks->a);
	solver(stacks);
	free_stacks(stacks);
	return (0);
}
