/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:15:27 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/21 21:25:00 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_initjulia(t_all *all)
{
	all->c_r = 0.285;
	all->c_i = 0.01;
	all->setc_r = 0;
	all->setc_i = 0;
	all->x1 = -1;
	all->x2 = 1;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->x_image = L_WIN;
	all->y_image = Y_WIN;
	all->iterations_max = 100;
	all->x_zoom = all->x_image / (all->x2 - all->x1);
	all->y_zoom = all->y_image / (all->y2 - all->y1);
}

void		ft_julia(t_all *all, int *i, double *tmp)
{
	all->z_r = all->x / all->x_zoom + all->x1 + all->setc_r;
	all->z_i = all->y / all->y_zoom + all->y1 + all->setc_i;
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

void		ft_perp_burn(t_all *all, int *i, double *tmp)
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
		all->z_i = 2 * fabs(all->z_i) * *tmp + all->c_i;
		(*i)++;
	}
}

void		ft_burn(t_all *all, int *i, double *tmp)
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
		all->z_i = 2 * fabs(all->z_i * *tmp) + all->c_i;
		(*i)++;
	}
}

void		ft_tricorn(t_all *all, int *i, double *tmp)
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
		all->z_i = -2 * all->z_i * *tmp + all->c_i;
		(*i)++;
	}
}
