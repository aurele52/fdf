/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdroite2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:00:57 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/18 21:31:26 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenhamthreesix(t_fdf *fdf, t_coord one, t_coord two)
{
	int	e;
	int	dy;
	int	dx;

	dx = two.x - one.x;
	dy = two.y - one.y;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (1)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.x++;
		if (one.x == two.x)
			break ;
		e = e + dy;
		if (e < 0)
		{
			one.y--;
			e = e + dx;
		}
	}
}

void	ft_bresenhamfourfive(t_fdf *fdf, t_coord one, t_coord two)
{
	int	e;
	int	dy;
	int	dx;

	dx = two.x - one.x;
	dy = two.y - one.y;
	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (1)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.x++;
		if (one.x == two.x)
			break ;
		e = e - dy;
		if (e < 0)
		{
			one.y++;
			e = e + dx;
		}
	}
}

void	ft_bresenhamtwoseven(t_fdf *fdf, t_coord one, t_coord two)
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
		one.y--;
		if (one.y == two.y)
			break ;
		e = e + dx;
		if (e > 0)
		{
			one.x++;
			e = e + dy;
		}
	}
}

void	ft_bresenham(t_fdf *fdf, t_coord one, t_coord two)
{
	int	dx;
	int	dy;

	if (two.x - one.x < 0)
		ft_swapcoord(&one, &two);
	dx = two.x - one.x;
	dy = two.y - one.y;
	if (dy != 0)
	{
		if (dy > 0)
		{
			if (dx >= dy)
				ft_bresenhamfourfive(fdf, one, two);
			else
				ft_bresenhamoneeight(fdf, one, two);
		}
		else
		{
			if (dx >= -dy)
				ft_bresenhamthreesix(fdf, one, two);
			else
				ft_bresenhamtwoseven(fdf, one, two);
		}
	}
	ft_printpixelimg(fdf, ft_makecoord1(fdf, two.x, two.y, two.color));
}

void	ft_printdroite(t_fdf *fdf, t_coord one, t_coord two)
{
	if (one.x == two .x)
		ft_printsamex(fdf, one, two);
	else if (one.y == two.y)
		ft_printsamey(fdf, one, two);
	else if (ft_abs(one.x - two.x) == ft_abs(one.y - two.y))
		ft_printdiag(fdf, one, two);
	else
		ft_bresenham(fdf, one, two);
}
