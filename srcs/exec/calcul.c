/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:09:32 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 08:45:21 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_dda(t_data *data, int *step_x, int *step_y)
{
	data->engine->delta_distx = fabs(1 / data->engine->ray_dirx);
	data->engine->delta_disty = fabs(1 / data->engine->ray_diry);
	if (data->engine->ray_dirx < 0)
	{
		*step_x = -1;
		data->engine->side_distx = (data->engine->pos_x - data->engine->map_x)
			* data->engine->delta_distx;
	}
	else
	{
		*step_x = 1;
		data->engine->side_distx = (data->engine->map_x + 1.0
				- data->engine->pos_x) * data->engine->delta_distx;
	}
	return (init_dda_2(data, step_y));
}

void	init_dda_2(t_data *data, int *step_y)
{
	if (data->engine->ray_diry < 0)
	{
		*step_y = -1;
		data->engine->side_disty = (data->engine->pos_y - data->engine->map_y)
			* data->engine->delta_disty;
	}
	else
	{
		*step_y = 1;
		data->engine->side_disty = (data->engine->map_y + 1.0
				- data->engine->pos_y) * data->engine->delta_disty;
	}
}

void	dda(t_data *data, int step_x, int step_y)
{
	while (data->engine->map_x >= 0 && data->engine->map_y >= 0)
	{
		if (data->engine->side_distx < data->engine->side_disty)
		{
			data->engine->side_distx += data->engine->delta_distx;
			data->engine->map_x += step_x;
			data->engine->side = 0;
		}
		else
		{
			data->engine->side_disty += data->engine->delta_disty;
			data->engine->map_y += step_y;
			data->engine->side = 1;
		}
		if (data->map_game[data->engine->map_x][data->engine->map_y]
			&& data->map_game[data->engine->map_x][data->engine->map_y] > '0'
			&& data->map_game[data->engine->map_x][data->engine->map_y] != '*')
			break ;
	}
}

void	calcul(t_data **data)
{
	int	step_x;
	int	step_y;

	(*data)->x = -1;
	while (++(*data)->x < WIDTH)
	{
		(*data)->engine->map_x = (int)(*data)->engine->pos_x;
		(*data)->engine->map_y = (int)(*data)->engine->pos_y;
		(*data)->engine->ray_dirx = (*data)->engine->dir_x
			+ ((*data)->engine->plane_x
				* ((double)(2 * (*data)->x / (double)WIDTH - 1)));
			(*data)->engine->ray_diry = (*data)->engine->dir_y
			+ ((*data)->engine->plane_y
				* ((double)(2 * (*data)->x / (double)WIDTH - 1)));
		init_dda((*data), &step_x, &step_y);
		dda((*data), step_x, step_y);
		draw_utils((*data), step_x, step_y);
		draw_color_texture((*data), (*data)->x, get_num_tex((*data)),
			(double)(1.0 * (*data)->engine->tex_height
				/ (*data)->engine->line_height));
	}
}
