/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:55:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/18 01:35:37 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

// rrr, rra, rrb, rr, ra, rb, ss, sa, sb, pa, pb

#define ABS(X) (X < 0) ? -X : X

#define RRR 0
#define RRA 1
#define RRB 2
#define RR 3
#define RA 4
#define RB 5
#define SS 6
#define SA 7
#define SB 8
#define PA 9
#define PB 10


typedef struct	s_clist
{
	int				data;
	char			c;
	struct s_clist	*next;
	struct s_clist	*prev;
}				t_clist;

typedef	struct	s_moves
{
	int				move : 8;
	struct s_moves	*next;
	struct s_moves	*prev;
}				t_moves;

typedef struct	s_frame
{
	t_clist	*a;
	t_clist	*b;
	t_moves	*moves;
}				t_frame;

typedef struct	s_rotate
{
	int		*operation;
	int		len;
	int		rotate;
	int		max;
	int		min;
	int		maxdist;
	int		mindist;
	int		flag : 1;
	t_clist	*minptr;
	t_clist	*maxptr;
}				t_rotate;

t_clist		*normalize(t_frame *stacks, t_clist *new, int i, int j);
t_clist		*create_clist(int data, t_frame *stacks);
void		add_before(t_clist *element, int data, t_frame *stacks);
void		add_after(t_clist *element, int data, t_frame *stacks);
void		add_to_top(t_clist **head, int data, t_frame *stacks);
void		add_to_tail(t_clist *head, int data, t_frame *stacks);
void		remove_head(t_clist **head);
void		print_stacks(t_frame *stacks);
void		get_input(t_frame *stacks);
int			is_sorted(t_frame *stacks);
void		jt(uint8_t jump_index, t_frame *stacks);
int			count_list(t_clist *stack);

int			get_median(t_clist *stack, int len);
int			count_list(t_clist *stack);

void		display_printf(t_frame *frame, int a_flag, int b_flag);
int			right_order(t_clist *stack);
int			solver(t_frame *stacks);
int			get_min(t_clist *stack);

void		error_exit(t_frame *stacks);
void		free_stacks(t_frame *stacks);
void		remove_element(t_clist **head, t_clist *element);
void		remove_first_element(t_clist *head);
void		remove_last_element(t_clist *head);

void		create_moves(t_frame *stacks, int moves);
void		add_list(t_frame *stacks, int moves);
void		delete_move(t_frame *stacks, t_moves *move);
int			optimizer(t_frame *stacks, t_moves *moves);

void		parser(char **av, t_frame *stacks);
int			check_duplicate(t_clist *head);

void		sa(t_frame *stacks);
void		sb(t_frame *stacks);
void		ss(t_frame *stacks);

void		pb(t_frame *stacks);
void		pa(t_frame *stacks);

void		ra(t_frame *stacks);
void		rb(t_frame *stacks);
void		rr(t_frame *stacks);

void		rra(t_frame *stacks);
void		rrb(t_frame *stacks);
void		rrr(t_frame *stacks);

#endif
