/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:26:09 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/27 16:55:16 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_move(t_frame *s, char *line)
{
	int			i;
	static char	*commands[] = {"rrr", "rra", "rrb", "rr", "ra", "rb", "ss",
		"sa", "sb", "pa", "pb", NULL};

	i = 0;
	while (commands[i] != NULL)
	{
		if (0 == ft_strcmp(line, commands[i]))
		{
			jt(i, s);
			(s->flags & VISUALIZER) ? init_vis(s, commands[i], i) : 0;
			break ;
		}
		i++;
	}
	free(line);
	if (commands[i] == NULL)
		error_exit(s);
}

void		get_input(t_frame *s)
{
	char		*line;

	line = NULL;
	(s->flags & VISUALIZER) ? init_vis(s, "\033[32;5mSTART\033[0m", 0) : 0;
	if (get_next_line(0, &line) == 0)
	{
		free(line);
		return ;
	}
	else
		execute_move(s, line);
	while (get_next_line(0, &line) != 0)
		execute_move(s, line);
	free(line);
}
