/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 10:14:06 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		init_env_tricorn(t_mbrot *mbrot)
{
	mbrot->x1 = -2.10;
	mbrot->y1 = -1.2;
	mbrot->x2 = 0.6;
	mbrot->y2 = 1.2;
	mbrot->itemax = 200;
	mbrot->image_x = WH;
	mbrot->image_y = WH;
	mbrot->y = 0;
	mbrot->delta = 0.1;
	mbrot->zoom_x = mbrot->image_x / (mbrot->x2 - mbrot->x1) / 1.1;
	mbrot->zoom_y = mbrot->image_y / (mbrot->y2 - mbrot->y1) / 1.1;
	mbrot->id = 3;
	mbrot->lock = 1;
}

static void	init_const_t(t_mbrot *mbrot)
{
	mbrot->cr = mbrot->x / mbrot->zoom_x + mbrot->x1;
	mbrot->ci = mbrot->y / mbrot->zoom_y + mbrot->y1;
	mbrot->i = 0;
	mbrot->zr = 0;
	mbrot->zi = 0;
}

void		tricorn(t_mbrot *mbrot)
{
	mbrot->x = 0;
	while (mbrot->x < mbrot->image_x)
	{
		mbrot->y = 0;
		while (mbrot->y < mbrot->image_y)
		{
			init_const_t(mbrot);
			while (mbrot->zr * mbrot->zr + mbrot->zi * mbrot->zi < 4 &&
				mbrot->i < mbrot->itemax)
			{
				mbrot->tmp = mbrot->zr;
				mbrot->zr = mbrot->zr * mbrot->zr - mbrot->zi
				* mbrot->zi + mbrot->cr;
				mbrot->zi = -2 * mbrot->zi * mbrot->tmp + mbrot->ci;
				mbrot->i++;
			}
			if (mbrot->i != mbrot->itemax)
				mlx_put_pixel_image(mbrot->x, mbrot->y, mbrot,
					(0x01FEDC * mbrot->i + 499 / 10) / 50);
			mbrot->y++;
		}
		mbrot->x++;
	}
}
