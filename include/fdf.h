/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:22:31 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/19 04:50:26 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../include/libft.h"
# define ZLIMITE 0.1

typedef struct s_coord
{
	int	x;
	int	y;
	int	color;
}	t_coord;

typedef struct s_imginfo
{
	void	*origin;
	char	*imgaddress;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_imginfo;

typedef struct s_fdf
{
	t_imginfo	image;
	t_pos		*garbage;
	void		*win_ptr;
	void		*mlx_ptr;
	int			xmove;
	int			ymove;
	int			xsize;
	int			ysize;
	int			ynbr;
	int			zmax;
	int			zmin;
	int			xnbr;
	t_coord		coord1;
	t_coord		coord2;
}	t_fdf;

char	*ft_lens(t_fdf *fdf, char *str);
void	ft_printsamey(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printdiagonefour(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printdiagtwothree(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printdiag(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printsamex(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printdroite(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printfirst(t_fdf *fdf, int **tab, int y);
void	ft_swapcoord(t_coord *a, t_coord *b);
void	ft_swap(int *a, int *b);
void	ft_bresenhamoneeight(t_fdf *fdf, t_coord one, t_coord two);
void	ft_printpixelimg(t_fdf *fdf, t_coord *print);
void	ft_testspace(t_fdf *fdf, char *str);
int		ft_a(t_fdf *fdf);
int		**ft_open(char *str, t_fdf *fdf);
int		ft_quit(t_fdf *fdf);
int		ft_key_hook(int keycode, t_fdf *fdf);
t_coord	*ft_iso(t_fdf *fdf, t_coord *a, int z);
t_coord	*ft_makecoord2(t_fdf *fdf, int x, int y, int color);
t_coord	*ft_makecoord1(t_fdf *fdf, int x, int y, int color);

#endif
