#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

typedef struct	s_cord
{
	int x;
	int y;
}				t_cord;


typedef struct	s_point
{
	double a;
	double b;
	double c;
	int color;
}				t_point;

typedef struct	s_bres
{
	int			abs;
	int			ord;
	int			dx;
	int			dy;
	int			stepx;
	int			stepy;
	int			e;
	int			i;
	t_point		beg;
	t_point		end;
}				t_bres;

typedef struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	t_cord	start;
	t_cord	t;
	t_point	**tab;
	t_point	**copy;
	int		p;
	int color;
	int color1;
	int z;
}				t_mlx;				

void    draw_line(t_point p1, t_point p2, t_mlx *m, int color);
void alt(t_mlx *m);
#endif
