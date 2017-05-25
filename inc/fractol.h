/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:19:06 by dhervy            #+#    #+#             */
/*   Updated: 2017/04/02 20:57:29 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# define X_WIN 1300
# define L_WIN 1000
# define Y_WIN 800

typedef struct	s_zoom
{
	double		x1;
	double		y1;
	double		x;
	double		y;
}				t_zoom;

typedef struct	s_all
{
	double		setc_r;
	double		setc_i;
	int			param;
	int			coll;
	int			color;
	int			nupiece;
	void		*mlx;
	void		*win;
	void		*img;
	int			*getaddr;
	int			endian;
	int			sizeline;
	int			btp;
	size_t		x;
	double		x1;
	double		x2;
	size_t		y;
	double		y1;
	double		y2;
	double		x_zoom;
	double		y_zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	size_t		x_image;
	size_t		y_image;
	size_t		iterations_max;
	size_t		multipl_iteration;
}				t_all;

void			ft_zoom(t_all *all, int x, int y);
void			ft_dezoom(t_all *all, int x, int y);
void			ft_morekeyhook(int keycode, t_all *all);
void			ft_putwinstr(t_all *toto);
void			ft_findpiece(t_all *all, int *i, double *tmp);
int				ft_usage(void);
void			ft_find_param(t_all *all, char *nom);
void			ft_perp_burn(t_all *all, int *i, double *tmp);
void			ft_burn(t_all *all, int *i, double *tmp);
void			ft_perpc(t_all *all, int *i, double *tmp);
void			ft_perp(t_all *all, int *i, double *tmp);
void			ft_celtic(t_all *all, int *i, double *tmp);
void			ft_tricorn(t_all *all, int *i, double *tmp);
void			ft_mandelbar(t_all *all, int *i, double *tmp);
void			ft_celtic(t_all *all, int *i, double *tmp);
int				ft_loop(t_all *all);
void			ft_initmandelbrot(t_all *all);
void			ft_initjulia(t_all *all);
void			ft_julia(t_all *all, int *i, double *tmp);
void			ft_mandelbrot(t_all *all, int *i, double *tmp);
int				ft_keyhook(int keycode, t_all *all);
int				ft_mouse(int x, int y, t_all *all);
int				ft_mousehook(int mikeymouse, int x, int y, t_all *all);
void			ft_init(t_all *all);
void			ft_initmlx(t_all *all);
void			ft_putpixel(t_all *all);
void			ft_printmenu(t_all *all);
void			ft_morekeyhook3(int keycode, t_all *all);

#endif
