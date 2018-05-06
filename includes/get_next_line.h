/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:56:18 by yabdulha          #+#    #+#             */
/*   Updated: 2018/05/06 23:43:23 by yabdulha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# define FD_ELEM ((t_fd*)current->content)
# include <unistd.h>
# include "./libft.h"

typedef	struct	s_fd
{
	int		fide;
	char	*rest;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
