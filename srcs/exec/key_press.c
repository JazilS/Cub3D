/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:10 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 06:28:04 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_data **data)
{
	if (key == 119)
		up(data);
	if (key == 115)
		down(data);
	if (key == 65307)
		mlx_loop_end((*data)->engine->mlx);
	if (key == 100)
		right(data);
	if (key == 97)
		left(data);
	return (key_press_move_camera_right(key, data));
}

int	key_press_move_camera_right(int key, t_data **data)
{
	double	tmp;

	if (key == 65363)
	{
		tmp = (*data)->engine->dir_x;
		(*data)->engine->dir_x = (*data)->engine->dir_x
			* cos(-(*data)->engine->rot_speed) - (*data)->engine->dir_y
			* sin(-(*data)->engine->rot_speed);
		(*data)->engine->dir_y = tmp * sin(-(*data)->engine->rot_speed)
			+ (*data)->engine->dir_y * cos(-(*data)->engine->rot_speed);
		tmp = (*data)->engine->plane_x;
		(*data)->engine->plane_x = (*data)->engine->plane_x
			* cos(-(*data)->engine->rot_speed) - (*data)->engine->plane_y
			* sin(-(*data)->engine->rot_speed);
		(*data)->engine->plane_y = tmp * sin(-(*data)->engine->rot_speed)
			+ (*data)->engine->plane_y * cos(-(*data)->engine->rot_speed);
	}
	return (key_press_move_camera_left(key, data));
}

int	key_press_move_camera_left(int key, t_data **data)
{
	double	tmp;

	if (key == 65361)
	{
		tmp = (*data)->engine->dir_x;
		(*data)->engine->dir_x = (*data)->engine->dir_x
			* cos((*data)->engine->rot_speed)
			- (*data)->engine->dir_y * sin((*data)->engine->rot_speed);
		(*data)->engine->dir_y = tmp * sin((*data)->engine->rot_speed)
			+ (*data)->engine->dir_y * cos((*data)->engine->rot_speed);
		tmp = (*data)->engine->plane_x;
		(*data)->engine->plane_x = (*data)->engine->plane_x
			* cos((*data)->engine->rot_speed) - (*data)->engine->plane_y
			* sin((*data)->engine->rot_speed);
		(*data)->engine->plane_y = tmp * sin((*data)->engine->rot_speed)
			+ (*data)->engine->plane_y * cos((*data)->engine->rot_speed);
	}
	return (0);
}
