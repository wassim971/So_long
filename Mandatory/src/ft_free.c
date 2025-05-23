/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:00:54 by jcheel-n          #+#    #+#             */
/*   Updated: 2025/05/19 12:42:18 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_free_array(char **ret, int i)
{
	int	x;

	x = 0;
	while (i - 1 >= x)
		free(ret[x++]);
	free(ret);
	return (0);
}

int	ft_free_array2(char **ret, int i)
{
	int	x;

	x = 0;
	while (i - 1 >= x && ret[x] != NULL)
		free(ret[x++]);
	free(ret);
	return (0);
}

void	ft_exit_free(t_map *map)
{
	if (map->array)
		free(map->array);
	if (map->copy)
		free(map->copy);
	if (map->file)
		free(map->file);
	if (map->line)
		free(map->file);
	exit(EXIT_FAILURE);
}
