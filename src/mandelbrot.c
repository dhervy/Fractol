/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:16:07 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/21 21:29:57 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_initmandelbrot(t_all *all)
{
	all->setc_r = 0;
	all->setc_i = 0;
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.1;
	all->y2 = 1.2;
	all->x_image = L_WIN;
	all->y_image = Y_WIN;
	all->iterations_max = 50;
	all->x_zoom = 350;
	all->y_zoom = 350;
}

void		ft_mandelbrot(t_all *all, int *i, double *tmp)
{
	all->c_r = all->x / all->x_zoom + all->x1 + all->setc_r;
	all->c_i = all->y / all->y_zoom + all->y1 + all->setc_i;
	all->z_r = 0;
	all->z_i = 0;
	*i = 0;
	while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && \
			*i < all->iterations_max)
	{
		*tmp = all->z_r;
		all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
		all->z_i = 2 * all->z_i * *tmp + all->c_i;
		(*i)++;
	}
}

void		ft_perpc(t_all *all, int *i, double *tmp)
{
	all->c_r = all->x / all->x_zoom + all->x1 + all->setc_r;
	all->c_i = all->y / all->y_zoom + all->y1 + all->setc_i;
	all->z_r = 0;
	all->z_i = 0;
	*i = 0;
	while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && \
			*i < all->iterations_max)
	{
		*tmp = all->z_r;
		all->z_r = fabs(all->z_r * all->z_r - all->z_i * all->z_i) + all->c_r;
		all->z_i = -2 * all->z_i * fabs(*tmp) + all->c_i;
		(*i)++;
	}
}

void		ft_perp(t_all *all, int *i, double *tmp)
{
	all->c_r = all->x / all->x_zoom + all->x1 + all->setc_r;
	all->c_i = all->y / all->y_zoom + all->y1 + all->setc_i;
	all->z_r = 0;
	all->z_i = 0;
	*i = 0;
	while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && \
			*i < all->iterations_max)
	{
		*tmp = all->z_r;
		all->z_r = fabs(all->z_r * all->z_r) - all->z_i * all->z_i + all->c_r;
		all->z_i = -2 * all->z_i * fabs(*tmp) + all->c_i;
		(*i)++;
	}
}

void		ft_celtic(t_all *all, int *i, double *tmp)
{
	all->c_r = all->x / all->x_zoom + all->x1 + all->setc_r;
	all->c_i = all->y / all->y_zoom + all->y1 + all->setc_i;
	all->z_r = 0;
	all->z_i = 0;
	*i = 0;
	while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && \
			*i < all->iterations_max)
	{
		*tmp = all->z_r;
		all->z_r = fabs(all->z_r * all->z_r - all->z_i * all->z_i) + all->c_r;
		all->z_i = -2 * all->z_i * *tmp + all->c_i;
		(*i)++;
	}
}
