/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:07:09 by audreyer          #+#    #+#             */
/*   Updated: 2022/07/10 11:35:26 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(t_pos *garbage, char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	if (garbage != 0)
		ft_posclear(garbage, 1);
	exit(1);
}
