/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoudene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:16:03 by smoudene          #+#    #+#             */
/*   Updated: 2020/02/27 21:28:26 by smoudene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/get_next_line.h"
#include "includes/fdf.h"

int		len_col(char *line)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			while (line[i] == ' ' || line[i] == '\t')
				i++;
		}
		if (line[i])
		{
			c += 1;
			while (line[i] != ' ' && line[i] != '\t' && line[i])
				i++;
		}
	}
	return (c);
}

t_point 	**ft_stock(char *av, t_cord t)
{
	char		**tmp;
	t_point		**cor;
	int i;
	int	j;
	char *line;
	int	fd;

	fd = open(av, O_RDONLY);
	cor = malloc(sizeof(t_point*) * t.y);
	/*protect*/
	i = 0;
	while (i < t.y)
	{
		j = 0;
		get_next_line(fd, &line);
		/*free*/
		tmp = ft_split_whitespaces(line);
		cor[i] = malloc(sizeof(t_point) * t.x);
		while (tmp[j])
		{
			cor[i][j].a = i * 20;
			cor[i][j].b = j * 20;
			cor[i][j].c = ft_atoi(tmp[j]);
			j++;
		}
		i++;
	}
	close(fd);
	return (cor);
}

t_cord	check_line_col(char *av)
{
	t_cord	res;
	t_cord	err;
	int fd;
	char *line;

	res.x = 0;
	res.y = 0;
	err.x = -1;
	err.y = -1;
	fd = open(av, O_RDONLY);
	if ((get_next_line(fd , &line)) == -1)
		return (err);
	res.y += 1;
	res.x = len_col(line);
	ft_strdel(&line);
	while (get_next_line(fd,&line))
	{
		if (res.x  > len_col(line))
		{
			ft_strdel(&line);
			return (err);
		}
		ft_strdel(&line);
		res.y += 1;
	}
	close(fd);
	return (res);
}


static void iso(double *x, double *y, int z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point		**ft_stock_iso(t_point **par, t_cord t)
{
	t_point		**tab;
	int			i;
	int			j;

	i = 0;
	while (i < t.y)
	{
		j = 0;
		tab[i] = malloc(sizeof(t_point) * t.x);
		while (j < t.x)
		{
			tab[i][j].a = par[i][j].a;
			tab[i][j].b = par[i][j].b;
			tab[i][j].c = par[i][j].c;
			iso(&tab[i][j].b, &tab[i][j].a, (int)tab[i][j].c);
			j++;
		}
		i++;
	}
	return (tab);	
}

void	draw(t_point **tab, t_cord t, t_mlx *m)
{
	int color;
	int i;
	int j;

	i = 0;
	while (i < t.y)
	{
		j = 0;
		while (j < t.x)
		{
			if (i + 1  < t.y)
			{
				if (tab[i][j].c || tab[i+1][j].c)
					color = m->color;
				else
					color = m->color1;
				draw_line(tab[i][j], tab[i + 1][j], m, color);	
			}
			if (j + 1  < t.x)
			{
				if (tab[i][j].c || tab[i][j + 1].c)
					color = m->color;
				else
					color = m->color1;
				draw_line(tab[i][j], tab[i][j + 1], m, color);
			}
			j++;
		}
		i++;
	}
}

int key_press(int key, t_mlx *m)
{
	if (key == 53)
		exit(1);
	if (key == 34)
	{
		if (m->p == 0)
		{
			m->p = 1;
			mlx_clear_window(m->mlx_ptr, m->win_ptr);
			draw(m->copy, m->t, m);
		}
		else
		{
			m->p = 0;
			mlx_clear_window(m->mlx_ptr, m->win_ptr);
			draw(m->tab, m->t, m);
		}
	}
	if (key == 124)
	{
		m->start.x += 30;
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}
	if (key == 123)
	{
		m->start.x -= 30;
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}
	if (key == 126)
	{
		m->start.y -= 30;
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}
	if (key == 125)
	{
		m->start.y += 30;
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}
	if (key == 49)
	{
		m->color *= 0xff * 203;
		m->color1 *=  203;
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}

	if (key == 69)
	{
		mlx_clear_window(m->mlx_ptr, m->win_ptr);
		m->z = 1;
		alt(m);
		if (m->p == 0)
			draw(m->tab, m->t, m);
		else
			draw(m->copy, m->t, m);
	}
	if (key == 78)
	{
		 mlx_clear_window(m->mlx_ptr, m->win_ptr);
		 alt(m);
		  m->z = -1;
		   if (m->p == 0)
			        draw(m->tab, m->t, m);
		    else
				     draw(m->copy, m->t, m);

	}
	return (1);
}

void alt(t_mlx *m)
{
	int         i;
	int         j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			m->copy[i][j].a -= m->copy[i][j].c * m->z;
			j++;
		}
		i++;
	}

}

int main(int ac, char **av)
{
	char 	*line;
	t_point	**tab;
	t_cord	t;
	t_mlx	m;

	if (ac == 2)
	{
		m.t = check_line_col(av[1]);
		if (t.x != -1 && t.y != -1)
		{
			m.p = 0;
			m.z = 0;
			m.color = 0x00ff00;
			m.color1 = 0xffffff;
			m.start.x = 200;
			m.start.y = 200;
			m.tab = ft_stock(av[1], m.t);
			m.copy = ft_stock_iso(m.tab, m.t);
			m.mlx_ptr = mlx_init();
			m.win_ptr = mlx_new_window(m.mlx_ptr, 1000, 1000, av[1]);
			draw(m.tab, m.t, &m);
			mlx_hook(m.win_ptr, 2, 0, key_press, &m);
			mlx_loop(m.mlx_ptr);
		}
		else
			printf("ERROR\n");
	}
}
