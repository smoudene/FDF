/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoudene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:28:46 by smoudene          #+#    #+#             */
/*   Updated: 2020/02/26 17:01:10 by smoudene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "includes/get_next_line.h"
#include "includes/fdf.h"


void	part1(t_bres v, t_mlx *m, int color)
{
	int		inc1;
	int		inc2;
	v.e = (2 * v.dy) - v.dx;
	v.i = -1;
	inc1 = 2 * (v.dy - v.dx);
	inc2 = 2 * (v.dy);
	while (++v.i < v.dx)
	{
		if (v.e >= 0)
		{
			v.e = v.e + inc1;
			v.ord += v.stepy;
		}
		else
			v.e = v.e + inc2;
		v.abs += v.stepx;
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, v.ord + m->start.x, v.abs + m->start.y, color);
	}
}
void	part2(t_bres v, t_mlx *m, int color)
{
	int		inc1;
	int		inc2;
	v.e = (2 * v.dx) - v.dy;
	v.i = -1;
	inc1 = 2 * (v.dx - v.dy);
	inc2 = 2 * (v.dx);
	while (++v.i < v.dy)
	{
		if (v.e >= 0)
		{
			v.e = v.e + inc1;
			v.abs += v.stepx;
		}
		else
			v.e = v.e + inc2;
		v.ord += v.stepy;
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, v.ord + m->start.x, v.abs + m->start.y, color);
		//data[(int)v.ord * WI + (int)v.abs] = color;
	}
}
void	draw_line(t_point p1, t_point p2, t_mlx *m, int color)
{
	t_bres	v;
	v.abs = p1.a;
	v.ord = p1.b;
	v.dx = p2.a - p1.a;
	v.dy = p2.b - p1.b;
	v.stepx = (v.dx > 0) ? 1 : -1;
	v.stepy = (v.dy > 0) ? 1 : -1;
	v.dx = abs(v.dx);
	v.dy = abs(v.dy);
	//f->data[(int)v.ord * WI + (int)v.abs] = 0xff;
	mlx_pixel_put(m->mlx_ptr, m->win_ptr, v.ord + m->start.x, v.abs + m->start.y, color);
	if (v.dx > v.dy)
		part1(v, m, color);
	else
		part2(v, m, color);
}
