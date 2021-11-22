/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:02:47 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 15:53:14 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "mlx.h"

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fract {
	struct s_data			data;
	unsigned long int		color1;
	unsigned long int		color2;
	int						s;
	int						x;
	int						y;
	int						frct;
	float					lft;
	float					up;
	float					x1;
	float					y1;
	float					a;
	float					b;
	float					f;
	float					c;
	float					p;
	float					t;
	float					pc;
	float					perx;
	int						itert;
	int						i;
}							t_fract;

void	manderbrot(t_fract *f);

void	julia(t_fract *f);

void	borningship(t_fract *f);

void	make_fract(t_fract *vars);

int		ft_mouse_hook(int keycode, int x, int y, t_fract *vars);

int		key_hook(int keycode, t_fract *vars);

void	julia(t_fract *f);

int		create_trgb(int t, int r, int g, int b);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
