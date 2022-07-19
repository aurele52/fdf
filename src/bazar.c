/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:06:02 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/19 05:59:58 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_lens(t_fdf *fdf, char *str)
{
	int	i;
	int	mem;

	mem = 0;
	fdf->xnbr = 0;
	fdf->ynbr = 0;
	i = 0;
	if (str == 0)
		ft_exit(fdf->garbage, "ERROR");
	while (str[i])
	{
		if (str[i] == '\n')
		{
			fdf->ynbr++;
			mem = 1;
		}
		if ((str[i] <= '9' && str[i] >= '0') && (i == 0
				|| (!((str[i - 1] <= '9' && str[i - 1] >= '0')
						|| str[i - 1] == ','))) && mem == 0)
			fdf->xnbr++;
		i++;
	}
	return (str);
}

void	ft_testspace(t_fdf *fdf, char *str)
{
	int	mem;
	int	prev;
	int	i;

	i = 0;
	mem = 0;
	prev = -1;
	while (str[i])
	{
		if (str[i] == ' ')
			mem++;
		if (str[i] == '\n' && prev != -1 && prev != mem)
			ft_exit(fdf->garbage, "Error");
		else if (str[i] == '\n')
		{
			prev = mem;
			mem = 0;
		}
		i++;
	}
}

int	**ft_open(char *str, t_fdf *fdf)
{
	char	*temp;
	char	*ret;
	int		fd;

	ret = ft_strdup("", fdf->garbage);
	if (ret == 0)
		ft_exit(fdf->garbage, "ERROR");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_exit(fdf->garbage, "Error");
	while (1)
	{
		temp = get_next_line(fd, fdf->garbage);
		if (temp == 0)
		{
			ft_lens(fdf, ret);
			close(fd);
			return (ft_splitint(ret, fdf->garbage));
		}
		ret = ft_strjoin(ret, temp, fdf->garbage);
		if (ret == 0)
			ft_exit(fdf->garbage, "ERROR");
	}
	return (0);
}

int	ft_quit(t_fdf *fdf)
{
	if (fdf->image.origin != 0)
		mlx_destroy_image(fdf->mlx_ptr, fdf->image.origin);
	if (fdf->win_ptr != 0)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr != 0)
		mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	ft_exit(fdf->garbage, 0);
	return (0);
}

int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
		ft_quit(fdf);
	return (keycode);
}
