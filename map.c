/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:44:00 by artvan-d          #+#    #+#             */
/*   Updated: 2022/12/15 15:15:17 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_data *data, char **argv)
/* will find the window size and check for some errors */
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r' &&
	argv[1][ft_strlen(argv[1]) - 2] != 'e'
	&& argv[1][ft_strlen(argv[1]) - 3] != 'b' &&
	argv[1][ft_strlen(argv[1]) - 4] != '.')
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}

void	ft_create_map(t_data *data)
/* will fill the map with the corresponding images */
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_object(data, "./textures/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_object(data, "./textures/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_object(data, "./textures/exit.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
