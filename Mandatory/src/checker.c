/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wassim <wassim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:53:12 by wassim            #+#    #+#             */
/*   Updated: 2025/05/28 02:53:14 by wassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	checker_file(t_map *map)
{
	size_t	len;

	len = ft_strlen(map->filename);
	if (map->filename[len - 1] != 'r')
		error_filename();
	if (map->filename[len - 2] != 'e')
		error_filename();
	if (map->filename[len - 3] != 'b')
		error_filename();
	if (map->filename[len - 4] != '.')
		error_filename();
	if (!ft_strnstr(map->filename, ".ber", ft_strlen(map->filename)))
		error_filename();
}

static void	checker_params(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				error_map_elements(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e != 1 || map->p != 1)
		error_map_elements(map);
}

static void	checker_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->array[0][x] == '1' && map->array[1][x])
		x++;
	if (map->array[1][x] != '\0')
		error_wall(map);
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' || map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (map->array[map->y - 1][x] == '1')
		x++;
	if (map->array[map->y - 1][x] != '\0')
		error_wall(map);
}

void	checker_size(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			error_size(map);
		y++;
	}
	map->x = max;
}

void	map_checker(t_map *map)
{
	checker_file(map);
	map_array(map);
	checker_size(map);
	checker_wall(map);
	checker_params(map);
	check_valid_path(map);
	ft_free_array(map->copy, map->y);
}
