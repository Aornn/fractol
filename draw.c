/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 08:31:43 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mlx_put_pixel_image(int x, int y, t_mbrot *env, int color)
{
	int pos;

	pos = (y * WH) + x;
	env->data[pos] = color;
}
