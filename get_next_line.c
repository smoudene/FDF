/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoudene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:18:39 by smoudene          #+#    #+#             */
/*   Updated: 2020/02/26 14:34:27 by smoudene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static	void	new_line(char **tab, char *temp)
{
	char	*str;

	str = ft_strdup(temp);
	ft_strdel(tab);
	*tab = str;
}

int				read_line(char **tab, char **line)
{
	char	*temp;

	if (ft_strlen(*tab) == 0)
		return (0);
	else
	{
		if ((temp = ft_strchr(*tab, '\n')) != NULL)
		{
			*temp = '\0';
			*line = ft_strdup(*tab);
			new_line(tab, temp + 1);
			return (1);
		}
		else
		{
			*line = *tab;
			*tab = NULL;
			return (1);
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	static	char	*tab[200000];
	int				r;

	if (fd < 0 || fd > 200000 || !line)
		return (-1);
	if (tab[fd] == NULL)
		tab[fd] = ft_strnew(0);
	while (((temp = ft_strchr(tab[fd], '\n')) == NULL) &&
			((r = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[r] = '\0';
		temp = tab[fd];
		tab[fd] = ft_strjoin(tab[fd], buf);
		ft_strdel(&temp);
	}
	if (r == 0)
		return (read_line(&tab[fd], line));
	if (r == -1)
		return (-1);
	*temp = '\0';
	*line = ft_strdup(tab[fd]);
	new_line(&tab[fd], temp + 1);
	return (1);
}
