/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:55:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/06 01:24:37 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <limits.h>


typedef struct	s_clist
{
	int				data;
	char			c;
	struct s_clist	*next;
	struct s_clist	*prev;
}				t_clist;

typedef struct	s_frame
{
	t_clist	*a;
	t_clist	*b;
}				t_frame;

/*
** Create, add to, and remove from Circular List
*/

t_clist*	create_clist(int data);
void		add_before(t_clist *element, int data);
void		add_after(t_clist *element, int data);
void		add_to_top(t_clist **head, int data);
void		add_to_tail(t_clist *head, int data);
void		remove_head(t_clist **head);


void		remove_element(t_clist **head, t_clist *element);
void		remove_first_element(t_clist *head);
void		remove_last_element(t_clist *head);

void		parser(char **av, t_frame *stacks);
int			check_duplicate(t_clist *head);
void		sa(t_frame *stacks);
void		pb(t_frame *stacks);
#endif
