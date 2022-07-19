/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdroite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:59:29 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/18 21:34:28 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_printsamey(t_fdf *fdf, t_coord one, t_coord two)
{	
	if (two.x > one.x)
		ft_swap(&one.x, &two.x);
	while (one.x >= two.x)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.x--;
	}
}

void	ft_printdiagonefour(t_fdf *fdf, t_coord one, t_coord two)
{
	while (one.x != two.x)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.x++;
		one.y++;
	}
	ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
}

void	ft_printdiagtwothree(t_fdf *fdf, t_coord one, t_coord two)
{
	while (one.x != two.x)
	{
		ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
		one.x++;
		one.y--;
	}
	ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
}

void	ft_printdiag(t_fdf *fdf, t_coord one, t_coord two)
{
	if (one.x - two.x == one.y - two.y)
	{
		if (two.x < one.x && two.y < one.y)
			ft_swapcoord(&one, &two);
		ft_printdiagonefour(fdf, one, two);
	}
	else
	{
		if (one.x > two.x)
			ft_swapcoord(&one, &two);
		ft_printdiagtwothree(fdf, one, two);
	}
}

void	ft_printsamex(t_fdf *fdf, t_coord one, t_coord two)
{
	if (one.x == two.x)
	{
		if (two.y > one.y)
			ft_swap(&one.y, &two.y);
		while (one.y >= two.y)
		{
			ft_printpixelimg(fdf, ft_makecoord1(fdf, one.x, one.y, one.color));
			one.y--;
		}
	}
}
