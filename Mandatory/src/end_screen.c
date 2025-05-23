/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:29:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2025/05/03 13:49:50 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_destroy_player_imgs(t_map *map)
{
	if (map->img.player_down1)
		mlx_destroy_image(map->mlx, map->img.player_down1);
	if (map->img.player_down2)
		mlx_destroy_image(map->mlx, map->img.player_down2);
	if (map->img.player_left1)
		mlx_destroy_image(map->mlx, map->img.player_left1);
	if (map->img.player_left2)
		mlx_destroy_image(map->mlx, map->img.player_left2);
	if (map->img.player_right1)
		mlx_destroy_image(map->mlx, map->img.player_right1);
	if (map->img.player_right2)
		mlx_destroy_image(map->mlx, map->img.player_right2);
	if (map->img.player_up1)
		mlx_destroy_image(map->mlx, map->img.player_up1);
	if (map->img.player_up2)
		mlx_destroy_image(map->mlx, map->img.player_up2);
}

int	ft_close_error(t_map *map, const char *msg)
{
	if (msg)
		write(2, msg, strlen(msg));
	if (map->img.collectible)
		mlx_destroy_image(map->mlx, map->img.collectible);
	if (map->img.empty)
		mlx_destroy_image(map->mlx, map->img.empty);
	if (map->img.enemy)
		mlx_destroy_image(map->mlx, map->img.enemy);
	if (map->img.exit)
		mlx_destroy_image(map->mlx, map->img.exit);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	ft_destroy_player_imgs(map);
	if (map->wnd)
		mlx_destroy_window(map->mlx, map->wnd);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	ft_free_array(map->array, map->y);
	free(map->mlx);
	exit(EXIT_FAILURE);
	return (1);
}

int	ft_close(t_map *map)
{
	if (map->img.collectible)
		mlx_destroy_image(map->mlx, map->img.collectible);
	if (map->img.empty)
		mlx_destroy_image(map->mlx, map->img.empty);
	if (map->img.enemy)
		mlx_destroy_image(map->mlx, map->img.enemy);
	if (map->img.exit)
		mlx_destroy_image(map->mlx, map->img.exit);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	ft_destroy_player_imgs(map);
	if (map->wnd)
		mlx_destroy_window(map->mlx, map->wnd);
	if (map->mlx)
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
