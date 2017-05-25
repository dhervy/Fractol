/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:14:37 by dhervy            #+#    #+#             */
/*   Updated: 2016/10/25 11:26:55 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_stringput(t_all *all, int y, int color, char *str)
{
	mlx_string_put(all->mlx, all->win, L_WIN + 5, y, color, str);
}

void	ft_printmenu3(t_all *all)
{
	if (all->nupiece == 3)
		ft_stringput(all, 400, 0xB9121B, "4. Tricorn");
	else
		ft_stringput(all, 400, 0x00DC3B, "4. Tricorn");
	if (all->nupiece == 4)
		ft_stringput(all, 420, 0xB9121B, "5. Celtic");
	else
		ft_stringput(all, 420, 0x00DC3B, "5. Celtic");
	if (all->nupiece == 6)
		ft_stringput(all, 440, 0xB9121B, "6. Perp_Celtic");
	else
		ft_stringput(all, 440, 0x00DC3B, "6. Perp_Celtic");
	if (all->nupiece == 7)
		ft_stringput(all, 460, 0xB9121B, "7. Burning_Ship");
	else
		ft_stringput(all, 460, 0x00DC3B, "7. Burning_Ship");
	if (all->nupiece == 8)
		ft_stringput(all, 480, 0xB9121B, "8. Perp_Burning_Ship");
	else
		ft_stringput(all, 480, 0x00DC3B, "8. Perp_Burning_Ship");
}

void	ft_printmenu2(t_all *all)
{
	if (all->nupiece == 2)
	{
		ft_stringput(all, 280, 0x00DC3B, "Param : E");
		if (all->param == 0)
			mlx_string_put(all->mlx, all->win, L_WIN + 150, 280, 0xB9121B, \
					"Desactiver");
		else
			mlx_string_put(all->mlx, all->win, L_WIN + 150, 280, 0x00DC3B, \
					"Activer");
	}
	mlx_string_put(all->mlx, all->win, L_WIN + 120, 320, 0x00DC3B, "Maps");
	mlx_string_put(all->mlx, all->win, L_WIN + 120, 321, 0x00DC3B, "____");
	if (all->nupiece == 2)
		ft_stringput(all, 340, 0xB9121B, "1. Julia");
	else
		ft_stringput(all, 340, 0x00DC3B, "1. Julia");
	if (all->nupiece == 1)
		ft_stringput(all, 360, 0xB9121B, "2. Mandelbrot");
	else
		ft_stringput(all, 360, 0x00DC3B, "2. Mandelbrot");
	if (all->nupiece == 5)
		ft_stringput(all, 380, 0xB9121B, "3. Perp_Mandelbrot");
	else
		ft_stringput(all, 380, 0x00DC3B, "3. Perp_Mandelbrot");
	ft_printmenu3(all);
}

void	ft_printmenu(t_all *all)
{
	char	*tmp;

	mlx_string_put(all->mlx, all->win, L_WIN + 100, 10, 0x00DC3B, "COMMANDE");
	mlx_string_put(all->mlx, all->win, L_WIN + 100, 11, 0x00DC3B, "________");
	ft_stringput(all, 40, 0x00DC3B, "ZOOM : click L or SCROLL");
	ft_stringput(all, 60, 0x00DC3B, "DEZOOM : click R or SCROLL");
	ft_stringput(all, 80, 0x00DC3B, "Iteration : + / -");
	ft_stringput(all, 100, 0x00DC3B, "Color : Q / W");
	ft_stringput(all, 120, 0x00DC3B, "Fond color : Z / X");
	ft_stringput(all, 140, 0x00DC3B, "Move : arrows");
	ft_stringput(all, 160, 0x00DC3B, "Reset : R");
	ft_stringput(all, 200, 0x00DC3B, "____________________________");
	ft_stringput(all, 240, 0x00DC3B, "Iteration :");
	tmp = ft_itoa(all->iterations_max);
	mlx_string_put(all->mlx, all->win, L_WIN + 150, 240, 0x00DC3B, tmp);
	free(tmp);
	ft_stringput(all, 260, 0x00DC3B, "Multipl Iteration : N / M");
	tmp = ft_itoa(all->multipl_iteration);
	mlx_string_put(all->mlx, all->win, L_WIN + 270, 260, 0x00DC3B, tmp);
	free(tmp);
	ft_printmenu2(all);
}
