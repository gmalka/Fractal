/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:13:21 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 16:13:06 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	else_printf(t_fract *f, int number);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	else_printf(t_fract *f, int number)
{
	f->i = -1;
	while (++(f->i) < f->itert && ((f->x1 * f->x1) + (f->y1 * f->y1)) < 4)
	{
		f->perx = (f->x1 * f->x1) - (f->y1 * f->y1) + f->f;
		if (number == 1)
			f->y1 = 2 * f->x1 * f->y1 + f->c;
		else
			f->y1 = 2 * fabsf(f->x1 * f->y1) + f->c;
		f->x1 = f->perx;
	}
	if (f->i == f->itert)
		my_mlx_pixel_put(&f->data, f->x, f->y, 0x000000);
	else if (f->i > 1 && f->i < f->itert)
		my_mlx_pixel_put(&f->data, f->x, f->y, (f->i * f->s) << f->color2);
	else
		my_mlx_pixel_put(&f->data, f->x, f->y, 0x000000);
}

void	borningship(t_fract *f)
{
	while (++(f->x) < 1920)
	{
		f->y = -1;
		while (++(f->y) < 1080)
		{
			f->f = (f->x - f->a) / (f->t) + f->lft;
			f->c = (f->y - f->b) / (f->t) + f->up;
			f->x1 = f->f;
			f->y1 = f->c;
			else_printf(f, 2);
		}
	}
	mlx_put_image_to_window(f->data.mlx, f->data.win, f->data.img, 0, 0);
}

void	julia(t_fract *f)
{
	while (++(f->x) < 1920)
	{
		f->y = -1;
		while (++(f->y) < 1080)
		{
			f->x1 = (f->x - f->a) / (f->t) + f->lft;
			f->y1 = (f->y - f->b) / (f->t) + f->up;
			f->i = -1;
			while (++(f->i) < f->itert && ((f->x1 * f->x1)
					+ (f->y1 * f->y1)) < 4)
			{
				f->perx = (f->x1 * f->x1) - (f->y1 * f->y1) + f->f;
				f->y1 = 2 * f->x1 * f->y1 + f->c;
				f->x1 = f->perx;
			}
			if (f->i == f->itert)
				my_mlx_pixel_put(&f->data, f->x, f->y, f->color1);
			else if (f->i > 1 && f->i < f->itert)
				my_mlx_pixel_put(&f->data, f->x, f->y,
					(f->i * f->s) << f->color2);
			else
				my_mlx_pixel_put(&f->data, f->x, f->y, 0x000000);
		}
	}
	mlx_put_image_to_window(f->data.mlx, f->data.win, f->data.img, 0, 0);
}

void	manderbrot(t_fract *f)
{
	while (++(f->x) < 1920)
	{
		f->y = -1;
		while (++(f->y) < 1080)
		{
			f->f = (f->x - f->a) / (f->t) + f->lft;
			f->c = (f->y - f->b) / (f->t) + f->up;
			f->x1 = f->f;
			f->y1 = f->c;
			f->p = sqrt((f->x1 - 0.25) * (f->x1 - 0.25) + (f->y1 * f->y1));
			f->pc = 0.5 - (cos(atan2(f->y1, f->x1 - 0.25)) / 2);
			if (f->p <= f->pc)
				my_mlx_pixel_put(&f->data, f->x, f->y, 0x000000);
			else
				else_printf(f, 1);
		}
	}
	mlx_put_image_to_window(f->data.mlx, f->data.win, f->data.img, 0, 0);
}
