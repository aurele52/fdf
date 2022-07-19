/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:20:39 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/19 04:38:25 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printpixelimg(t_fdf *fdf, t_coord *print)
{
	int		pos;
	char	*pixel;

	if (print->x < 0 || print->y < 0
		|| print->y > fdf->ysize || print->x > fdf->xsize)
		return ;
	pos = (print->y * fdf->image.size_line
			+ print->x * (fdf->image.bits_per_pixel / 8));
	pixel = fdf->image.imgaddress + pos;
	*(int *)pixel = print->color;
}

t_coord	*ft_iso(t_fdf *fdf, t_coord *a, int z)
{
	int	memx;
	int	memy;

	(void)fdf;
	memx = a->x;
	memy = a->y;
	a->x = memx - memy + 700;
	a->y = (memx + memy) / 2 + 200 - (z * ZLIMITE);
	return (a);
}

int	ft_a(t_fdf *fdf)
{
	int	a;

	if (fdf->xnbr > fdf->ynbr)
		a = (fdf->xsize / fdf->xnbr) / 2;
	else
		a = (fdf->ysize / fdf->ynbr) / 2;
	return (a);
}

void	ft_printfirst(t_fdf *fdf, int **tab, int y)
{
	int	x;
	int	a;

	a = ft_a(fdf);
	while (++y != fdf->ynbr)
	{
		x = -1;
		while (++x != fdf->xnbr)
		{
			if (x + 1 != fdf->xnbr)
				ft_printdroite(fdf, *(ft_iso(fdf, ft_makecoord1(fdf,
								x * a, y * a, 123233 + tab[y][x] * 10),
							tab[y][x] * a)), *(ft_iso(fdf, ft_makecoord2(
								fdf, (x + 1) * a, y * a,
								123233 + tab[y][x] * 10),
							tab[y][x + 1] * a)));
			if (y + 1 != fdf->ynbr)
				ft_printdroite(fdf, *(ft_iso(fdf, ft_makecoord1(fdf,
								x * a, y * a, 123233 + tab[y][x] * 10),
							tab[y][x] * a)), *(ft_iso(fdf, ft_makecoord2(
								fdf, x * a, (y + 1) * a,
								123233 + tab[y][x] * 10),
							tab[y + 1][x] * a)));
		}
	}
}
