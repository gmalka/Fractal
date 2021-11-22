/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:59:56 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 16:14:50 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractal.h"

static void		make_minus(t_fract *vars);

static void		make_plus(t_fract *vars);

static void		move_to(t_fract *f, float lr, float up);

static void	move_to(t_fract *f, float lr, float up)
{
	f->x = -1;
	if (lr)
		f->lft += (lr / f->t);
	if (up)
		f->up += (up / f->t);
}

static void	make_plus(t_fract *vars)
{
	vars->x = -1;
	vars->color1 = vars->color1 + (1 << vars->color2);
	if (vars->color1 >= 0xffffffff)
		vars->color1 = 0x00000000;
	vars->color2 = vars->color2 + 1;
	if (vars->color2 > 24)
		vars->color2 = 1;
}

static void	make_minus(t_fract *vars)
{
	vars->x = -1;
	vars->color1 = vars->color1 - (1 << vars->color2);
	if (vars->color1 >= 0xffffffff)
		vars->color1 = 0x00000000;
	vars->color2 = vars->color2 - 1;
	if (vars->color2 <= 0)
		vars->color2 = 24;
}

int	key_hook(int keycode, t_fract *vars)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 123)
		move_to(vars, 10, 0);
	else if (keycode == 124)
		move_to(vars, -10, 0);
	else if (keycode == 125)
		move_to(vars, 0, -8);
	else if (keycode == 126)
		move_to(vars, 0, 8);
	else if (keycode == 69)
		make_plus(vars);
	else if (keycode == 78)
		make_minus(vars);
	make_fract(vars);
	return (0);
}
