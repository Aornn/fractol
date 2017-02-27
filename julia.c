/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 08:34:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stdio.h>

void		init_env_julia(t_mbrot *mbrot)
{
	mbrot->x1 = -1;
	mbrot->x2 = 1;
	mbrot->y1 = -1.2;
	mbrot->y2 = 1.2;
	mbrot->itemax = 200;
	mbrot->delta = 0.1;
	mbrot->image_x = WH;
	mbrot->image_y = WH;
	mbrot->zoom_x = mbrot->image_x / (mbrot->x2 - mbrot->x1);
	mbrot->zoom_y = mbrot->image_y / (mbrot->y2 - mbrot->y1);
	mbrot->cr = -0.41;
	mbrot->ci = 0.6;
	mbrot->id = 2;
}

static void	init_const_j(t_mbrot *mbrot)
{
	mbrot->zr = mbrot->x / mbrot->zoom_x + mbrot->x1;
	mbrot->zi = mbrot->y / mbrot->zoom_y + mbrot->y1;
	mbrot->i = 0;
}

void		julia(t_mbrot *mbrot)
{
	mbrot->x = 0;
	while (mbrot->x < mbrot->image_x)
	{
		mbrot->y = 0;
		while (mbrot->y < mbrot->image_y)
		{
			init_const_j(mbrot);
			while (mbrot->zr * mbrot->zr + mbrot->zi * mbrot->zi < 4 &&
				mbrot->i < mbrot->itemax)
			{
				mbrot->tmp = mbrot->zr;
				mbrot->zr = mbrot->zr * mbrot->zr - mbrot->zi
				* mbrot->zi + mbrot->cr;
				mbrot->zi = 2 * mbrot->zi * mbrot->tmp + mbrot->ci;
				mbrot->i++;
			}
			if (mbrot->i != mbrot->itemax)
				mlx_put_pixel_image(mbrot->x, mbrot->y, mbrot,
					(0x01FEDC * mbrot->i + 499 / 10) / mbrot->itemax * 10);
			mbrot->y++;
		}
		mbrot->x++;
	}
}
