/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/24 18:56:39 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void mlx_put_pixel_image(int x, int y, t_mbrot *env, int color)
{
	int pos;

	pos = (y * WH) + x;
	env->data[pos] = color;
}
/*
static float	*ft_init_mult_int(t_model *para, float *mult_int)
{
	mult_int[1] = ft_abs(para->x2 - para->x1);
	mult_int[2] = para->x1 < para->x2 ? 1 : -1;
	mult_int[3] = -ft_abs(para->y2 - para->y1);
	mult_int[4] = para->y1 < para->y2 ? 1 : -1;
	mult_int[5] = mult_int[1] + mult_int[3];
	return (mult_int);
}

void		ft_stroke(t_model *para)
{
	float *mult_int;

	mult_int = malloc(6 * sizeof(float));
	mult_int = ft_init_mult_int(para, mult_int);
	while (1)
	{
		mlx_put_pixel_image(para->x1,para->y1, para, 0xFFFFFF);
		mult_int[0] = 2 * mult_int[5];
		if (mult_int[0] >= mult_int[3])
		{
			if (para->x1 == para->x2)
				break ;
			mult_int[5] += mult_int[3];
			para->x1 += mult_int[2];
		}
		if (mult_int[0] <= mult_int[1])
		{
			if (para->y1 == para->y2)
				break ;
			mult_int[5] += mult_int[1];
			para->y1 += mult_int[4];
		}
	}
}
*/