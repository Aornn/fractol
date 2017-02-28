/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 12:30:24 by rqueverd         ###   ########.fr       */
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

static void	calc_delta_val(int keycode, t_mbrot *mbrot)
{
	if (keycode == 69)
		mbrot->delta *= 1.15;
	if (keycode == 78)
		mbrot->delta /= 1.15;
}

int			ft_event(int keycode, t_mbrot *mbrot)
{
	exit_n_reset(keycode, mbrot);
	if (mbrot->id == 2)
	{
		if (keycode == 37 && mbrot->lock == 0)
			mbrot->lock = 1;
		if (keycode == 32 && mbrot->lock == 1)
			mbrot->lock = 0;
	}
	calc_delta_val(keycode, mbrot);
	if (keycode == 18)
		init_env_mandelbrot(mbrot);
	if (keycode == 19)
		init_env_julia(mbrot);
	if (keycode == 20)
		init_env_tricorn(mbrot);
	if (keycode == 124 && mbrot->lock == 1)
		mbrot->x1 += mbrot->delta;
	if (keycode == 123 && mbrot->lock == 1)
		mbrot->x1 -= mbrot->delta;
	if (keycode == 126 && mbrot->lock == 1)
		mbrot->y1 += mbrot->delta;
	if (keycode == 125 && mbrot->lock == 1)
		mbrot->y1 -= mbrot->delta;
	draw_by_id(mbrot);
	return (0);
}
