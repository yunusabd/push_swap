/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:10:31 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/07 01:14:17 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	jt(uint8_t jump_index, t_frame *stacks)
{
	static void		(*pf[])(t_frame *stacks) = {rrr, rra, rrb, rr, ra, rb, ss,
		sa, sb, pa, pb};

	pf[jump_index](stacks);
}
