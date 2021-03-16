/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoudene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:18:49 by smoudene          #+#    #+#             */
/*   Updated: 2020/02/26 14:35:01 by smoudene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);
int		read_line(char **tab, char **line);

#endif
