/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:29:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2025/04/29 14:32:42 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.collectible);
	mlx_destroy_image(map->mlx, map->img.empty);
	mlx_destroy_image(map->mlx, map->img.enemy);
	mlx_destroy_image(map->mlx, map->img.exit);
	mlx_destroy_image(map->mlx, map->img.wall);
	mlx_destroy_image(map->mlx, map->img.player_down1);
	mlx_destroy_image(map->mlx, map->img.player_down2);
	mlx_destroy_image(map->mlx, map->img.player_left1);
	mlx_destroy_image(map->mlx, map->img.player_left2);
	mlx_destroy_image(map->mlx, map->img.player_right1);
	mlx_destroy_image(map->mlx, map->img.player_right2);
	mlx_destroy_image(map->mlx, map->img.player_up1);
	mlx_destroy_image(map->mlx, map->img.player_up2);
	mlx_destroy_window(map->mlx, map->wnd);
	mlx_destroy_display(map->mlx);
	ft_free_array(map->array, map->y);
	free(map->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd, map->x / 2 * IMG_PXL, map->y / 2
		* IMG_PXL, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}
