/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:20:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/06 00:17:34 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Create + add to a Circular linked list
 */

t_clist*	create_clist(int data)
{
	t_clist	*head;

	if (!(head = (t_clist*)malloc(sizeof(*head))))
		return (NULL);
	if (head)
	{
		head->prev = head;
		head->next = head;
		head->data = data;
	}
	return (head);
}

void	add_to_top(t_clist **head, int data) // THIS WORKS!!
{
	t_clist *new;

	if (!(new = (t_clist*)malloc(sizeof(*new))))
		error_exit("Error\n", 1);
	new->data = data;
	new->next = *head;
	new->prev = (*head)->prev;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
}

void	add_to_tail(t_clist *head, int data) // THIS WORKS!!
{
	t_clist *new;

	if (!(new = (t_clist*)malloc(sizeof(*new))))
		error_exit("Error\n", 1);
	new->data = data;
	new->next = head;
	new->prev = (head->next == head) ? head : head->prev;
	head->prev = new;
	new->prev->next = new;
}
