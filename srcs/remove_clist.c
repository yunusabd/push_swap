/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_clist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:35:17 by aschukin          #+#    #+#             */
/*   Updated: 2018/05/25 00:57:40 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_element(t_clist **head, t_clist *element)
{
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		element->prev->next = element->next;
		element->next->prev = element->prev;
		free(element);
	}
}

void	remove_head(t_clist **head)
{
	t_clist	*tmp;

	if (!(*head))
		return ;
	tmp = (*head)->next;
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		free(*head);
		*head = tmp;
	}
}
