/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 21:19:02 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/21 22:17:10 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_morekeyhook3(int keycode, t_all *all)
{
	if (keycode == 87 || keycode == 23)
	{
		all->nupiece = 4;
		ft_initmandelbrot(all);
	}
	if (keycode == 88 || keycode == 22)
	{
		all->nupiece = 6;
		ft_initmandelbrot(all);
	}
	if (keycode == 89 || keycode == 26)
	{
		all->nupiece = 7;
		ft_initmandelbrot(all);
	}
	if (keycode == 91 || keycode == 28)
	{
		all->nupiece = 8;
		ft_initmandelbrot(all);
	}
	if (keycode == 7)
		all->color = 0xFFFFFF;
	if (keycode == 6)
		all->color = 0x000000;
}
