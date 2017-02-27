/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 09:32:17 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/27 08:54:18 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	check_main(int argc, char **argv, t_mbrot *mbrot)
{
	if (argc != 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 &&
		ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "tricorn") != 0))
	{
		ft_putstr("Wrong Argument.\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0 &&
		ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "tricorn") != 0)
	{
		mbrot->id = 1;
		init_env_mandelbrot(mbrot);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 &&
		ft_strcmp(argv[1], "julia") == 0 && ft_strcmp(argv[1], "tricorn") != 0)
	{
		mbrot->id = 2;
		init_env_julia(mbrot);
	}
	if (ft_strcmp(argv[1], "mandelbrot") != 0 &&
		ft_strcmp(argv[1], "julia") != 0 && ft_strcmp(argv[1], "tricorn") == 0)
	{
		mbrot->id = 3;
		init_env_tricorn(mbrot);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_mbrot mbrot;

	if (check_main(argc, argv, &mbrot) == 0)
		return (0);
	mbrot.mlx = mlx_init();
	mbrot.window = mlx_new_window(mbrot.mlx, WH, WH, "Fract'ol");
	mbrot.img = mlx_new_image(mbrot.mlx, WH, WH);
	mbrot.data = (int *)mlx_get_data_addr(mbrot.img, &mbrot.bpp,
		&mbrot.sizeline, &mbrot.endian);
	if (mbrot.id == 1)
		mandelbrot(&mbrot);
	if (mbrot.id == 2)
		julia(&mbrot);
	if (mbrot.id == 3)
		tricorn(&mbrot);
	mlx_put_image_to_window(mbrot.mlx, mbrot.window, mbrot.img, 0, 0);
	mlx_hook(mbrot.window, 4, (1L << 2), ft_event_zoom, &mbrot);
	mlx_hook(mbrot.window, 6, (1L << 6), ft_event_mouse_julia, &mbrot);
	mlx_hook(mbrot.window, 2, 0, ft_event, &mbrot);
	mlx_loop(mbrot.mlx);
	return (0);
}
