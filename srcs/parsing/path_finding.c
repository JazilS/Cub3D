/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:46:28 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/26 18:37:26 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	flood_recursively_to_border(char **map, int x, int y, t_data *data)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	if (map[y][x] == ' ')
		quit_error("There is space in map.", data->garb_coll);
	map[y][x] = '2';
	if (x == 0 || y == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (flood_recursively_to_border(map, x + 1, y, data))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y, data))
		return (1);
	if (flood_recursively_to_border(map, x, y + 1, data))
		return (1);
	if (flood_recursively_to_border(map, x, y - 1, data))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y + 1, data))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y - 1, data))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y - 1, data))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y + 1, data))
		return (1);
	return (0);
}

char	**create_copie(char **map, t_data *data)
{
	int		i;
	char	**temp;

	i = 0;
	while (map[i])
		i++;
	temp = ft_malloc(sizeof(temp) * (i + 1), data->garb_coll);
	i = 0;
	while (map[i])
	{
		temp[i] = ft_strdup(map[i], data);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	path_finding(char **map, t_data *data)
{
	int		i;
	int		j;
	char	**map_copie;

	(void)map;
	fill_map(data->map, data);
	map_copie = data->map_path;
	i = -1;
	while (map_copie[++i])
	{
		j = -1;
		while (map_copie[i][++j])
		{
			if (map_copie[i][j] == 'N' || map_copie[i][j] == 'S'
				|| map_copie[i][j] == 'W' || map_copie[i][j] == 'E')
			{
				if (flood_recursively_to_border(map_copie, j, i, data))
					quit_error("Invalid border.", data->garb_coll);
				return (0);
			}
		}
	}
	return (0);
}
