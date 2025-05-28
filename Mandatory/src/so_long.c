/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wassim <wassim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:54:44 by wassim            #+#    #+#             */
/*   Updated: 2025/05/28 02:54:46 by wassim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map_initializer(&map, av);
		map_checker(&map);
		map.mlx = mlx_init();
		if (!map.mlx)
			exit(EXIT_FAILURE);
		map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL, map.y * IMG_PXL,
				WND_NAME);
		file_to_image(&map);
		map_printer(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
	write(2, "\033[1;31m🛑ERROR:", 18);
	write(2, "Usage: ./so_long mapfile\n\033[0m", 30);
	exit(EXIT_FAILURE);
}
