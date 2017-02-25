/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:44:01 by rqueverd          #+#    #+#             */
/*   Updated: 2017/02/24 16:35:40 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
//# include "cuda_call.h"
# define WH 800
/*
typedef struct	s_model
{
	void		*mlx;
	void		*window;
	void		*img;
	int			*data;
	int			bpp;
  	int			sizeline;
  	int			endian;
}				t_model;
*/
typedef struct	s_mbrot
{
	void		*mlx;
	void		*window;
	void		*img;
	int			*data;
	int			color;
	int			bpp;
  	int			sizeline;
  	int			endian;
  	float		DELTA;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			itemax;
	float		x;
	float		y;
	float		image_x;
	float		image_y;
	float		zoom_x;
	float		zoom_y;
	float		cr;
	float		ci;
	float		zr;
	float		zi;
	float		i;
	float		tmp;
	int			id;
}				t_mbrot;

int				ft_event_zoom(int button, int x, int y, t_mbrot *mbrot);
int				ft_event_mouse_julia(int x, int y,t_mbrot *mbrot);
int				ft_event_julia(int keycode,t_mbrot *mbrot);
int				ft_event(int keycode,t_mbrot *mbrot);
void			mlx_put_pixel_image(int x, int y, t_mbrot *env, int color);
void			mandelbrot(t_mbrot *mbrot);
void			init_env_mandelbrot(t_mbrot *mbrot);
void			init_env_julia(t_mbrot *mbrot);
void			mandelbrot(t_mbrot *mbrot);
void			julia(t_mbrot *mbrot);
void			init_env_tricorn(t_mbrot *mbrot);
void			tricorn(t_mbrot *mbrot);
#endif