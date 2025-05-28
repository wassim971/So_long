/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wassim <wassim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 02:54:01 by wassim            #+#    #+#             */
/*   Updated: 2025/05/28 02:54:03 by wassim           ###   ########.fr       */
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
