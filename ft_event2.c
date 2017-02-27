/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 09:09:00 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	exit_n_reset(int keycode, t_mbrot *mbrot)
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
}

int			ft_event(int keycode, t_mbrot *mbrot)
{
	exit_n_reset(keycode, mbrot);
	if (keycode == 18)
		init_env_mandelbrot(mbrot);
	if (keycode == 19)
		init_env_julia(mbrot);
	if (keycode == 20)
		init_env_tricorn(mbrot);
	if (keycode == 124)
		mbrot->x1 += mbrot->delta / 1.1;
	if (keycode == 123)
		mbrot->x1 -= mbrot->delta / 1.1;
	if (keycode == 126)
		mbrot->y1 += mbrot->delta / 1.1;
	if (keycode == 125)
		mbrot->y1 -= mbrot->delta / 1.1;
	draw_by_id(mbrot);
	mlx_put_image_to_window(mbrot->mlx, mbrot->window, mbrot->img, 0, 0);
	return (0);
}
