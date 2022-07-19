/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdroite3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:02:08 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/18 21:34:41 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*ft_makecoord1(t_fdf *fdf, int x, int y, int color)
{
	fdf->coord1.x = x;
	fdf->coord1.y = y;
	fdf->coord1.color = color;
	return (&fdf->coord1);
}

t_coord	*ft_makecoord2(t_fdf *fdf, int x, int y, int color)
{
	fdf->coord2.x = x;
	fdf->coord2.y = y;
	fdf->coord2.color = color;
	return (&fdf->coord2);
}

void	ft_swapcoord(t_coord *a, t_coord *b)
{
	t_coord	mem;

	mem = *a;
	*a = *b;
	*b = mem;
}

void	ft_swap(int *a, int *b)
{
	int	mem;

	mem = *a;
	*a = *b;
	*b = mem;
}

void	ft_bresenhamoneeight(t_fdf *fdf, t_coord one, t_coord two)
{
	int	e;
	int	dy;
	int	dx;

	dx = two.x - one.x;
	dy = two.y - one.y;
	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (1)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.y++;
		if (one.y == two.y)
			break ;
		e = e - dx;
		if (e < 0)
		{
			one.x++;
			e = e + dy;
		}
	}
}
