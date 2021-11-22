/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:00:43 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 16:06:29 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void		up_fract(t_fract *vars, int x, int y);

static void		remake_fract(t_fract *f, float x, float y, float zoom);

static void	remake_fract(t_fract *f, float x, float y, float zoom)
{
	f->x = -1;
	f->y = -1;
	f->x1 = 0;
	f->y1 = 0;
	if (zoom != 0)
	{
		f->t = f->t * zoom;
		f->a += (x - f->a) - (x - f->a) * zoom;
		f->b += (y - f->b) - (y - f->b) * zoom;
	}
	f->p = 0;
	f->pc = 0;
	f->perx = 0;
	f->itert = 35;
	f->i = 0;
}

static void	up_fract(t_fract *vars, int x, int y)
{
	vars->x = -1;
	vars->f = (((float)x - vars->a) / 2) / vars->t;
	vars->c = (((float)y - vars->b) / 2) / vars->t;
}

int	ft_mouse_hook(int keycode, int x, int y, t_fract *vars)
{
	if (keycode == 4)
		remake_fract(vars, x, y, 1.1);
	else if (keycode == 5)
		remake_fract(vars, x, y, 0.9);
	else if (keycode == 3)
	{
		vars->x = -1;
		if (vars->s < 200)
			vars->s = vars->s + 50;
		else
			vars->s = 2;
	}
	else if (keycode == 1 && vars->frct == 2)
		up_fract(vars, x, y);
	make_fract(vars);
	return (0);
}
