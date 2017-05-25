/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:55:49 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/25 11:23:11 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initmlx(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, X_WIN, Y_WIN, "fract'ol");
	all->img = mlx_new_image(all->mlx, X_WIN, Y_WIN);
	all->getaddr = (int*)mlx_get_data_addr(all->img, &all->btp, \
			&all->sizeline, &all->endian);
	mlx_hook(all->win, 6, (1L << 6), ft_mouse, all);
	mlx_hook(all->win, 2, (1L << 0), ft_keyhook, all);
	mlx_mouse_hook(all->win, ft_mousehook, all);
	mlx_loop_hook(all->mlx, ft_loop, all);
	mlx_loop(all->mlx);
}

int		ft_loop(t_all *all)
{
	mlx_destroy_image(all->mlx, all->img);
	all->img = mlx_new_image(all->mlx, X_WIN, Y_WIN);
	ft_putpixel(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	ft_printmenu(all);
	return (0);
}

void	ft_putpixel(t_all *all)
{
	int			i;
	double		tmp;

	tmp = 0;
	all->x = -1;
	while (++all->x < all->x_image)
	{
		all->y = -1;
		while (++all->y < all->y_image)
		{
			ft_findpiece(all, &i, &tmp);
			if (i != all->iterations_max)
				all->getaddr[all->x + all->y * X_WIN] = \
												i * (0x8402C7 + all->coll);
			else
				all->getaddr[all->x + all->y * X_WIN] = all->color;
		}
	}
}

int		ft_usage(void)
{
	ft_putstr("usage: ./fractol <filename>\n");
	ft_putstr("filename :       julia\n");
	ft_putstr("                 tricorn\n");
	ft_putstr("                 mandelbrot\n");
	ft_putstr("                 perp_mandelbrot\n");
	ft_putstr("                 celtic\n");
	ft_putstr("                 perp_celtic\n");
	ft_putstr("                 burning_ship\n");
	ft_putstr("                 perp_burning_ship\n");
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	if (ac != 2 && ft_usage() == 0)
		return (0);
	ft_find_param(&all, av[1]);
	all.param = 0;
	all.multipl_iteration = 10;
	all.coll = 15000;
	all.color = 0x000000;
	ft_initmlx(&all);
	return (0);
}
