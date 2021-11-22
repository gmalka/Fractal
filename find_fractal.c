/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:57:41 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 15:14:48 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	make_fract(t_fract *vars)
{
	if (vars->frct == 1)
		manderbrot(vars);
	else if (vars->frct == 2)
		julia(vars);
	else if (vars->frct == 3)
		borningship(vars);
	else
	{
		write(1, "       Name Error\n\nUser one of provided names:\
				\n  Mandelbrot\n  Julia\n  Borningship\n\n  GoodLuck;)\n", 100);
		exit(0);
	}
}
