/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/24 19:02:55 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stdio.h>

int ft_event(int keycode,t_mbrot *mbrot)
{
	if (keycode == 53)
	{
		ft_putstr("Exit succes.\n");
		mlx_clear_window(mbrot->mlx, mbrot->window);
		exit(1);
	}
	if (keycode == 15)
	{
		ft_putstr("Reset.\n");
		if (mbrot->id == 1)
			init_env_mandelbrot(mbrot);
		else if (mbrot->id == 2)
			init_env_julia(mbrot);
		else if (mbrot->id == 3)
			init_env_tricorn(mbrot);
	}
	if (keycode == 18)
		init_env_mandelbrot(mbrot);
	if (keycode == 19)
		init_env_julia(mbrot);
	if (keycode == 20)
		init_env_tricorn(mbrot);
	if (keycode == 124)
		mbrot->x1 += mbrot->DELTA / 1.1;
	if (keycode == 123)
		mbrot->x1 -= mbrot->DELTA / 1.1;
	if (keycode == 126)
		mbrot->y1 += mbrot->DELTA / 1.1;
	if (keycode == 125)
		mbrot->y1 -= mbrot->DELTA / 1.1;
	mlx_destroy_image(mbrot->mlx, mbrot->img);
	mlx_clear_window (mbrot->mlx, mbrot->window);
	mbrot->img = mlx_new_image(mbrot->mlx, 800, 800);
	mbrot->data = (int *)mlx_get_data_addr(mbrot->img, &mbrot->bpp, &mbrot->sizeline, &mbrot->endian);
	if (mbrot->id == 1)
		mandelbrot(mbrot);
	else if (mbrot->id == 2)
		julia(mbrot);
	else if (mbrot->id == 3)
		tricorn(mbrot);
	mlx_put_image_to_window(mbrot->mlx, mbrot->window, mbrot->img, 0, 0);
	return (0);
}

int ft_event_zoom(int button, int x, int y, t_mbrot *mbrot)
{
	float tmp_x = mbrot->x1 + x * (mbrot->x2 - mbrot->x1) / 800;
	float tmp_y = mbrot->y1 + y * (mbrot->y2 - mbrot->y1) / 800;
	float tmp_x2 = mbrot->x1;
	float tmp_y2 = mbrot->y1;
	if (button != 4 && button != 5)
		return (0);
	if (button == 5)
	{
		mbrot->zoom_y *= 1.005;
		mbrot->zoom_x *= 1.005;
		mbrot->x1 = tmp_x - (mbrot->x2 - mbrot->x1) / 4;
		mbrot->x2 = tmp_x + (mbrot->x2 - tmp_x2) / 4;
		mbrot->y1 = tmp_y - (mbrot->y2 - mbrot->y1) / 4;
		mbrot->y2 = tmp_y + (mbrot->y2 - tmp_y2) / 4;
	}
	if (button == 4)
	{
		mbrot->zoom_y /= 1.05;
		mbrot->zoom_x /= 1.05;
		mbrot->x1 = tmp_x - (mbrot->x2 - mbrot->x1);
		mbrot->x2 = tmp_x + (mbrot->x2 - tmp_x2);
		mbrot->y1 = tmp_y - (mbrot->y2 - mbrot->y1);
		mbrot->y2 = tmp_y + (mbrot->y2 - tmp_y2);
	}
	mlx_destroy_image(mbrot->mlx, mbrot->img);
	mlx_clear_window (mbrot->mlx, mbrot->window);
	mbrot->img = mlx_new_image(mbrot->mlx, 800, 800);
	mbrot->data = (int *)mlx_get_data_addr(mbrot->img, &mbrot->bpp, &mbrot->sizeline, &mbrot->endian);
	mandelbrot(mbrot); //CHANGER CETTE LIGNE EN FCT DE L'ID
	mlx_put_image_to_window(mbrot->mlx, mbrot->window, mbrot->img, 0, 0);
	return(0);
}

int ft_event_mouse_julia(int x, int y,t_mbrot *mbrot)
{	
	if (mbrot->id == 2)
	{
		if ((x < 800 && y < 800) && (x >= 0 && y >= 0))
		{
			mbrot->cr = x * 0.002256;
			mlx_destroy_image(mbrot->mlx, mbrot->img);
			mlx_clear_window (mbrot->mlx, mbrot->window);
			mbrot->img = mlx_new_image(mbrot->mlx, 800, 800);
			mbrot->data = (int *)mlx_get_data_addr(mbrot->img, &mbrot->bpp, &mbrot->sizeline, &mbrot->endian);
			mbrot->ci = y * 0.002 * 1.005;
			julia(mbrot);
			mlx_put_image_to_window(mbrot->mlx, mbrot->window, mbrot->img, 0, 0);
		}
	}
	return (0);
}
