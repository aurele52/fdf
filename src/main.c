/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:07:03 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/19 04:40:19 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_inittruefdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (fdf->mlx_ptr == 0)
		ft_exit(fdf->garbage, "Error");
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->xsize, fdf->ysize, "fdf");
	if (fdf->win_ptr == 0)
		ft_quit(fdf);
	fdf->image.origin = mlx_new_image(fdf->mlx_ptr, fdf->xsize, fdf->ysize);
	if (fdf->image.origin == 0)
		ft_quit(fdf);
	fdf->image.imgaddress = mlx_get_data_addr(fdf->image.origin,
			&fdf->image.bits_per_pixel,
			&fdf->image.size_line, &fdf->image.endian);
}

void	ft_initfdf(t_fdf *fdf)
{
	fdf->win_ptr = 0;
	fdf->mlx_ptr = 0;
	fdf->xsize = 1400;
	fdf->ysize = 700;
	fdf->xnbr = 0;
	fdf->ynbr = 0;
	fdf->image.origin = 0;
	fdf->coord1.x = 0;
	fdf->coord1.y = 0;
	fdf->coord1.color = 0;
	fdf->coord2.x = 0;
	fdf->coord2.y = 0;
	fdf->coord2.color = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		**tab;

	fdf.garbage = ft_setpos(0);
	if (fdf.garbage == 0)
		ft_exit(0, "Error");
	ft_initfdf(&fdf);
	tab = 0;
	if (argc != 2)
		ft_exit(fdf.garbage, "Error");
	tab = ft_open(argv[1], &fdf);
	if (tab == 0)
		ft_exit(fdf.garbage, "Error");
	ft_inittruefdf(&fdf);
	ft_printfirst(&fdf, tab, -1);
	mlx_hook(fdf.win_ptr, 17, 0, ft_quit, &fdf);
	mlx_key_hook(fdf.win_ptr, &ft_key_hook, &fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image.origin, 0, 0);
	mlx_loop(fdf.mlx_ptr);
}
