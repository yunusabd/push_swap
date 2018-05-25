/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:46:49 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/25 00:57:05 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_color(int m)
{
	if (m == 1)
		return ("\e\033[0;36m");
	else if (m == 2)
		return ("\e\033[0;36m");
	else if (m == 3)
		return ("\e\033[0;34m");
	else if (m == 4)
		return ("\e\033[0;34m");
	else if (m == 5)
		return ("\e\033[0;32m");
	else if (m == 7)
		return ("\e\033[0;32m");
	else if (m == 8)
		return ("\e\033[0;32m");
	else if (m == 9)
		return ("\e\033[0;31m");
	else if (m == 10)
		return ("\e\033[0;31m");
	return ("");
}
