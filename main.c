/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/24 16:35:17 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stdio.h>

int main (int argc, char **argv)
{	
	if (argc != 2 || (ft_atoi(argv[1]) != 1 && ft_atoi(argv[1]) != 2 && ft_atoi(argv[1]) != 3))
	{	
		ft_putstr("Wrong Argument.\n");
		return (0);
	}
	t_mbrot mbrot;
	mbrot.mlx = mlx_init();
	mbrot.window = mlx_new_window(mbrot.mlx, WH, WH, "Fract'ol");
	mbrot.img = mlx_new_image(mbrot.mlx, WH, WH);
	mbrot.data = (int *)mlx_get_data_addr(mbrot.img, &mbrot.bpp, &mbrot.sizeline, &mbrot.endian);
	if (ft_atoi(argv[1]) == 1)
	{
		init_env_mandelbrot(&mbrot);
		mandelbrot(&mbrot);
	}
	if (ft_atoi(argv[1]) == 2)
	{
		init_env_julia(&mbrot);
		julia(&mbrot);
	}
	if (ft_atoi(argv[1]) == 3)
	{
		init_env_tricorn(&mbrot);
		tricorn(&mbrot);
	}
	mlx_put_image_to_window(mbrot.mlx, mbrot.window, mbrot.img, 0, 0);
	if (mbrot.id == 1)
		mlx_hook(mbrot.window, 4,(1L<<2), ft_event_zoom,&mbrot);
	mlx_hook(mbrot.window, 6, (1L<<6), ft_event_mouse_julia, &mbrot);
	mlx_hook(mbrot.window, 2, 0, ft_event, &mbrot);
	mlx_loop(mbrot.mlx);
	return (0);
}