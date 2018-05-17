/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:26:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/17 17:28:48 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_input(t_frame *stacks)
{
	char		*line;
	static char	*commands[] = {"rrr", "rra", "rrb", "rr", "ra", "rb", "ss",
		"sa", "sb", "pa", "pb", NULL};
	int			i;

	line = NULL;
	while (get_next_line(0, &line) != 0)
	{
		i = 0;
		while (commands[i] != NULL)
		{
			if (0 == ft_strcmp(line, commands[i]))
			{
				jt(i, stacks);
				print_stacks(stacks);
				break ;
			}
			i++;
		}
		if (commands[i] == NULL)
		{
			free(line);
			error_exit(stacks);
		}
		free(line);
	}
	free(line);
}
