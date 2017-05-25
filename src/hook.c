/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:02:36 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/25 11:28:27 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_morekeyhook2(int keycode, t_all *all)
{
	if (keycode == 83 || keycode == 18)
	{
		all->nupiece = 2;
		ft_initjulia(all);
	}
	if (keycode == 84 || keycode == 19)
	{
		all->nupiece = 1;
		ft_initmandelbrot(all);
	}
	if (keycode == 85 || keycode == 20)
	{
		all->nupiece = 5;
		ft_initmandelbrot(all);
	}
	if (keycode == 86 || keycode == 21)
	{
		all->nupiece = 3;
		ft_initmandelbrot(all);
	}
	ft_morekeyhook3(keycode, all);
}

void	ft_morekeyhook(int keycode, t_all *all)
{
	if (keycode == 15)
	{
		if (all->nupiece != 2)
			ft_initmandelbrot(all);
		else
			ft_initjulia(all);
	}
	if (keycode == 13)
	{
		all->coll -= 7654;
	}
	if (keycode == 12)
	{
		all->coll += 3467;
	}
	if (keycode == 27)
		all->iterations_max -= all->multipl_iteration;
	if (keycode == 24)
		all->iterations_max += all->multipl_iteration;
	if (keycode == 45)
		all->multipl_iteration -= 10;
	if (keycode == 46)
		all->multipl_iteration += 10;
	ft_morekeyhook2(keycode, all);
}

int		ft_keyhook(int keycode, t_all *all)
{
	if (keycode == 14 && all->nupiece == 2)
	{
		if (all->param == 0)
			all->param = 1;
		else
			all->param = 0;
	}
	if (keycode == 53)
		exit(0);
	if (keycode == 125)
		all->setc_i += 0.01;
	if (keycode == 126)
		all->setc_i -= 0.01;
	if (keycode == 123)
		all->setc_r -= 0.01;
	if (keycode == 124)
		all->setc_r += 0.01;
	ft_morekeyhook(keycode, all);
	return (0);
}

int		ft_mouse(int x, int y, t_all *all)
{
	if (x > 0 && y > 0 && x <= X_WIN && y <= Y_WIN && all->param == 1)
	{
		all->c_r = (float)(x + 500 - X_WIN) / 400;
		all->c_i = (float)(y + 420 - Y_WIN) / 400;
	}
	return (1);
}

int		ft_mousehook(int keymouse, int x, int y, t_all *all)
{
	if ((keymouse == 2 || keymouse == 4) && all->x_zoom > 250 && y > 0)
		ft_dezoom(all, x, y);
	if ((keymouse == 1 || keymouse == 5) && y > 0)
		ft_zoom(all, x, y);
	return (0);
}
