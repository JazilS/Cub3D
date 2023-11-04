/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:53:15 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 06:26:34 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_south_or_north(char c, t_data *data)
{
	if (c == 'S')
	{
		data->engine->dir_x = 0.99;
		data->engine->plane_x = 0;
		data->engine->dir_y = 0;
		data->engine->plane_y = -0.6;
	}
	else if (c == 'N')
	{
		data->engine->dir_x = -0.99;
		data->engine->plane_x = 0;
		data->engine->dir_y = 0;
		data->engine->plane_y = 0.6;
	}
}

static void	set_west_or_east(char c, t_data *data)
{
	if (c == 'W')
	{
		data->engine->dir_x = 0;
		data->engine->plane_x = -0.6;
		data->engine->dir_y = -0.99;
		data->engine->plane_y = 0;
	}
	else if (c == 'E')
	{
		data->engine->dir_x = 0;
		data->engine->plane_x = 0.6;
		data->engine->dir_y = 0.99;
		data->engine->plane_y = 0;
	}
}

int	get_player_pos(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->engine->pos_x = i + 0.5;
				data->engine->pos_y = j + 0.5;
				if (map[i][j] == 'S' || map[i][j] == 'N')
					set_south_or_north(map[i][j], data);
				if (map[i][j] == 'W' || map[i][j] == 'E')
					set_west_or_east(map[i][j], data);
				map[i][j] = 0;
				break ;
			}
		}
	}
	return (1);
}
