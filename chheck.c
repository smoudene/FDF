/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chheck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoudene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:46:20 by smoudene          #+#    #+#             */
/*   Updated: 2019/11/28 14:50:10 by smoudene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check(int fd)
{
	int i;
	int j;
	int cp;
	int *t = NULL;
	char *line;


	i = 0;
	while (get_next_line(fd,&line) == 1)
	{
		cp = 0;
		while (*line)
			cp++;
		t[i] = cp;
		i++;
	}
	j = 1;
	while (t[j] < i + 1)
	{
		if (t[0] < t[j])
			return (-1);
		j++;
	}
	return (1);
}

int main()
{
	int fd;
	char *line;
    
	line = NULL;
	fd = open("file" ,O_RDONLY);

	printf("%d",check(fd));
}

