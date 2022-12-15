/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:43:52 by artvan-d          #+#    #+#             */
/*   Updated: 2022/11/17 14:42:47 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_data *data)
/* will cause the different actions of the valid key presses
** will cause you to win if you reached the exit */
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		ft_move(data, 'y', UP);
	else if (keycode == A)
		ft_move(data, 'x', LEFT);
	else if (keycode == D)
		ft_move(data, 'x', RIGHT);
	else if (keycode == S)
		ft_move(data, 'y', DOWN);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_win(data);
	return (0);
}
