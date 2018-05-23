/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:55:42 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/23 17:37:42 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If the first character is '-', check if it is an options argument and set
** the flags accordingly. Return 0 if there's not a character after the dash.
*/

int	options(char *s, t_frame *stacks)
{
	int	i;

	if (s[0] != '-')
		return (0);
	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isalpha(s[(i)]))
			return (0);
		if (s[i] == 'v')
			stacks->flags |= VISUALIZER;
		if (s[i] == 'h' || s[i] == 'u')
			stacks->flags |= USAGE;
		if (s[i] == 'n')
			stacks->flags |= HIDE;
		if (s[i] == 's')
			stacks->flags |= SLOW;
		if (s[i] == 'm')
			stacks->flags |= MOVES;
		if (s[i] == 'c')
			stacks->flags |= COLORS;
		i++;
	}
	return (1);
}
