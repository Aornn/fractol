/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 12:13:33 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	draw_by_id(t_mbrot *mbrot)
{
	mlx_destroy_image(mbrot->mlx, mbrot->img);
	mlx_clear_window(mbrot->mlx, mbrot->window);
	mbrot->img = mlx_new_image(mbrot->mlx, 800, 800);
	mbrot->data = (int *)mlx_get_data_addr(mbrot->img, &mbrot->bpp,
	&mbrot->sizeline, &mbrot->endian);
	if (mbrot->id == 1)
		mandelbrot(mbrot);
	if (mbrot->id == 2)
		julia(mbrot);
	if (mbrot->id == 3)
		tricorn(mbrot);
	mlx_put_image_to_window(mbrot->mlx, mbrot->window, mbrot->img, 0, 0);
}

int		ft_event_zoom(int button, int x, int y, t_mbrot *mbrot)
{
	double tmpx;
	double tmpy;

	tmpx = mbrot->zoom_x;
	tmpy = mbrot->zoom_y;
	if (button == 5 && mbrot->lock == 1)
	{
		mbrot->zoom_y *= 1.1;
		mbrot->zoom_x *= 1.1;
		mbrot->delta /= 1.15;
		if (mbrot->id == 1)
			mbrot->itemax *= 1.05;
	}
	if (button == 4 && (mbrot->zoom_y > 20 && mbrot->zoom_x > 18) &&
		mbrot->lock == 1)
	{
		mbrot->zoom_y /= 1.1;
		mbrot->zoom_x /= 1.1;
		if (mbrot->id == 1)
			mbrot->delta *= 1.1;
	}
	mbrot->x1 += x / tmpx - (x / mbrot->zoom_x);
	mbrot->y1 += y / tmpy - (y / mbrot->zoom_y);
	draw_by_id(mbrot);
	return (0);
}

int		ft_event_mouse_julia(int x, int y, t_mbrot *mbrot)
{
	if (mbrot->id == 2 && mbrot->lock == 0)
	{
		if ((x < 800 && y < 800) && (x >= 0 && y >= 0))
		{
			mbrot->cr = x * 0.002256;
			mlx_destroy_image(mbrot->mlx, mbrot->img);
			mlx_clear_window(mbrot->mlx, mbrot->window);
			mbrot->img = mlx_new_image(mbrot->mlx, 800, 800);
			mbrot->data = (int *)mlx_get_data_addr(mbrot->img, &mbrot->bpp,
				&mbrot->sizeline, &mbrot->endian);
			mbrot->ci = y * 0.002 * 1.005;
			julia(mbrot);
			mlx_put_image_to_window(mbrot->mlx, mbrot->window,
				mbrot->img, 0, 0);
		}
	}
	return (0);
}
