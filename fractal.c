/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:57:56 by gmalka            #+#    #+#             */
/*   Updated: 2021/11/22 15:55:02 by gmalka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void		find_fractal_name(t_fract *var);

static void		init_fract(t_fract *f);

static int		ft_close(int keycode, t_fract *vars);

static int		ft_strncmp(char *str, char *chm);

static void	init_fract(t_fract *f)
{
	f->data.mlx = mlx_init();
	f->data.win = mlx_new_window(f->data.mlx, 1920, 1080, "HELLO!1");
	f->data.img = mlx_new_image(f->data.mlx, 1920, 1080);
	f->data.addr = mlx_get_data_addr(f->data.img, &(f->data.bits_per_pixel),
			&(f->data.line_length), &(f->data.endian));
	f->s = 2;
	f->color1 = 0x000000;
	f->color2 = 1;
	f->x = -1;
	f->y = -1;
	f->x1 = 0;
	f->y1 = 0;
	f->a = 960;
	f->b = 540;
	f->f = -1.5;
	f->c = -1;
	f->p = 0;
	f->t = 300;
	f->pc = 0;
	f->perx = 0;
	f->lft = 0;
	f->up = 0;
	f->itert = 35;
	f->i = 0;
}

static int	ft_close(int keycode, t_fract *vars)
{
	exit(0);
	vars++;
	return (keycode);
}

static int	ft_strncmp(char *str, char *chm)
{
	int		i;

	i = 0;
	while (str[i] && str[i] == chm[i])
		i++;
	if (str[i] == chm[i])
		return (1);
	return (0);
}

static void	find_fractal_name(t_fract *var)
{
	if (ft_strncmp(var->data.name, "Mandelbrot"))
		var->frct = 1;
	else if (ft_strncmp(var->data.name, "Julia"))
		var->frct = 2;
	else if (ft_strncmp(var->data.name, "Borningship"))
		var->frct = 3;
	make_fract(var);
	mlx_loop(var->data.mlx);
}

int	main(int argc, char *argv[])
{
	t_fract	fract;

	if (argc == 2)
	{
		init_fract(&fract);
		mlx_key_hook(fract.data.win, key_hook, &fract);
		mlx_hook(fract.data.win, 17, (1L << 0), ft_close, &fract);
		mlx_mouse_hook(fract.data.win, ft_mouse_hook, &fract);
		fract.data.name = argv[1];
		find_fractal_name(&fract);
	}
	else
		write(1, "Incorrect number of arguments!\n", 31);
}
