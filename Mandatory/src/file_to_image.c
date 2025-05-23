/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:15 by jcheel-n          #+#    #+#             */
/*   Updated: 2025/05/13 12:04:26 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	append_image_error(char *str, void *img, const char *name)
{
	if (!img)
		ft_strlcat(str, name, 256);
}

void	error_image(t_map *map)
{
	char	str[256];

	str[0] = '\0';
	ft_strlcat(str, "Erreur de permission pour: ", 256);
	append_image_error(str, map->img.collectible, "collectible ");
	append_image_error(str, map->img.empty, "empty ");
	append_image_error(str, map->img.enemy, "enemy ");
	append_image_error(str, map->img.exit, "exit ");
	append_image_error(str, map->img.wall, "wall ");
	append_image_error(str, map->img.player_down1, "player_down1 ");
	append_image_error(str, map->img.player_down2, "player_down2 ");
	append_image_error(str, map->img.player_left1, "player_left1 ");
	append_image_error(str, map->img.player_left2, "player_left2 ");
	append_image_error(str, map->img.player_right1, "player_right1 ");
	append_image_error(str, map->img.player_right2, "player_right2 ");
	append_image_error(str, map->img.player_up1, "player_up1 ");
	append_image_error(str, map->img.player_up2, "player_up2 ");
	if (ft_strncmp(str, "Erreur de permission pour: ", 256) != 0)
		ft_close_error(map, str);
}

void	file_to_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx, "Resources/empty.xpm", &a,
			&a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "Resources/wall.xpm", &a,
			&a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "Resources/door.xpm", &a,
			&a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx, "Resources/nico.xpm",
			&a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx, "Resources/enemy.xpm", &a,
			&a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right-1-40.xpm", &a, &a);
	map->img.player_right2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right-2-40.xpm", &a, &a);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up-1-40.xpm", &a, &a);
	map->img.player_up2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up-2-40.xpm", &a, &a);
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down-1-40.xpm", &a, &a);
	map->img.player_down2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down-2-40.xpm", &a, &a);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left-1-40.xpm", &a, &a);
	map->img.player_left2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left-2-40.xpm", &a, &a);
	error_image(map);
}
