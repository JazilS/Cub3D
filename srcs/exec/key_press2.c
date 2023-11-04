/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:15:59 by jsabound          #+#    #+#             */
/*   Updated: 2023/10/31 18:09:07 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	up(t_data **data)
{
	if (((*data)->engine->pos_x + (*data)->engine->dir_x
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[((int)((*data)->engine->pos_x
				+ ((*data)->engine->dir_x
					* (*data)->engine->move_speed)))]
						[(int)((*data)->engine->pos_y)])
		(*data)->engine->pos_x += (*data)->engine->dir_x
			* (*data)->engine->move_speed;
	if (((*data)->engine->pos_y + (*data)->engine->dir_y
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x)]
					[((int)((*data)->engine->pos_y
					+ ((*data)->engine->dir_y * (*data)->engine->move_speed)))])
		(*data)->engine->pos_y += (*data)->engine->dir_y
			* (*data)->engine->move_speed;
}

void	down(t_data **data)
{
	if (((*data)->engine->pos_x - (*data)->engine->dir_x
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x
			- (*data)->engine->dir_x
			* (*data)->engine->move_speed)][(int)((*data)->engine->pos_y)])
		(*data)->engine->pos_x -= (*data)->engine->dir_x
			* (*data)->engine->move_speed;
	if (((*data)->engine->pos_y - (*data)->engine->dir_y
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x)]
					[(int)((*data)->engine->pos_y
					- (*data)->engine->dir_y * (*data)->engine->move_speed)])
		(*data)->engine->pos_y -= (*data)->engine->dir_y
			* (*data)->engine->move_speed;
}

void	left(t_data **data)
{
	if (((*data)->engine->pos_x - (*data)->engine->dir_y
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x
			- (*data)->engine->dir_y
			* (*data)->engine->move_speed)][(int)((*data)->engine->pos_y)])
		(*data)->engine->pos_x -= (*data)->engine->dir_y
			* (*data)->engine->move_speed;
	if (((*data)->engine->pos_y + (*data)->engine->dir_x
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x)]
					[(int)((*data)->engine->pos_y
					+ (*data)->engine->dir_x * (*data)->engine->move_speed)])
		(*data)->engine->pos_y += (*data)->engine->dir_x
			* (*data)->engine->move_speed;
}

void	right(t_data **data)
{
	if (((*data)->engine->pos_x + (*data)->engine->dir_y
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x
			+ (*data)->engine->dir_y
			* (*data)->engine->move_speed)][(int)((*data)->engine->pos_y)])
		(*data)->engine->pos_x += (*data)->engine->dir_y
			* (*data)->engine->move_speed;
	if (((*data)->engine->pos_y - (*data)->engine->dir_x
			* (*data)->engine->move_speed) > 0
		&& '1' != (*data)->map_game[(int)((*data)->engine->pos_x)]
					[(int)((*data)->engine->pos_y
					- (*data)->engine->dir_x * (*data)->engine->move_speed)])
		(*data)->engine->pos_y -= (*data)->engine->dir_x
			* (*data)->engine->move_speed;
}
