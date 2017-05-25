/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:16:49 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/21 21:28:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_find_param(t_all *all, char *nom)
{
	if (ft_strcmp("mandelbrot", nom) == 0)
		all->nupiece = 1;
	else if (ft_strcmp("julia", nom) == 0)
		all->nupiece = 2;
	else if (ft_strcmp("tricorn", nom) == 0)
		all->nupiece = 3;
	else if (ft_strcmp("celtic", nom) == 0)
		all->nupiece = 4;
	else if (ft_strcmp("perp_mandelbrot", nom) == 0)
		all->nupiece = 5;
	else if (ft_strcmp("perp_celtic", nom) == 0)
		all->nupiece = 6;
	else if (ft_strcmp("burning_ship", nom) == 0)
		all->nupiece = 7;
	else if (ft_strcmp("perp_burning_ship", nom) == 0)
		all->nupiece = 8;
	else if (ft_usage() == 0)
		exit(0);
	if (all->nupiece == 2)
		ft_initjulia(all);
	else
		ft_initmandelbrot(all);
}

void	ft_findpiece(t_all *all, int *i, double *tmp)
{
	if (all->nupiece == 1)
		ft_mandelbrot(all, i, tmp);
	else if (all->nupiece == 2)
		ft_julia(all, i, tmp);
	else if (all->nupiece == 3)
		ft_tricorn(all, i, tmp);
	else if (all->nupiece == 4)
		ft_celtic(all, i, tmp);
	else if (all->nupiece == 5)
		ft_perp(all, i, tmp);
	else if (all->nupiece == 7)
		ft_burn(all, i, tmp);
	else if (all->nupiece == 8)
		ft_perp_burn(all, i, tmp);
	else if (all->nupiece == 6)
		ft_perpc(all, i, tmp);
}

void	ft_dezoom(t_all *all, int x, int y)
{
	t_zoom	tmp;

	tmp.x1 = all->x1;
	tmp.y1 = all->y1;
	tmp.x = all->x1 + x * (all->x2 - all->x1) / L_WIN;
	tmp.y = all->y1 + y * (all->y2 - all->y1) / Y_WIN;
	all->x1 = tmp.x - (all->x2 - all->x1);
	all->x2 = tmp.x + (all->x2 - tmp.x1);
	all->y1 = tmp.y - (all->y2 - all->y1);
	all->y2 = tmp.y + (all->y2 - tmp.y1);
	all->x_zoom = all->x_zoom / 2;
	all->y_zoom = all->y_zoom / 2;
}

void	ft_zoom(t_all *all, int x, int y)
{
	t_zoom tmp;

	tmp.x1 = all->x1;
	tmp.y1 = all->y1;
	tmp.x = all->x1 + x * (all->x2 - all->x1) / L_WIN;
	tmp.y = all->y1 + y * (all->y2 - all->y1) / Y_WIN;
	all->x1 = tmp.x - (all->x2 - all->x1) / 4;
	all->x2 = tmp.x + (all->x2 - tmp.x1) / 4;
	all->y1 = tmp.y - (all->y2 - all->y1) / 4;
	all->y2 = tmp.y + (all->y2 - tmp.y1) / 4;
	all->x_zoom += all->x_zoom;
	all->y_zoom += all->y_zoom;
}
