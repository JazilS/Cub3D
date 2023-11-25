/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:05:10 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/25 19:06:03 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int key_move(t_data *data)
{
	if (data->forward == 1)
		up(&data);
	if (data->back == 1)
		down(&data);
	if (data->right == 1)
		right(&data);
	if (data->left == 1)
		left(&data);
	if (data->move_cam_right == 1)
		key_press_move_camera_right(65363, &data);
	if (data->move_cam_left == 1)
		key_press_move_camera_left(65361, &data);
	return (0);	
}

int	key_press(int key, t_data **data)
{
	if (key == 119)
		(*data)->forward = 1;
	if (key == 115)
		(*data)->back = 1;
	if (key == 65307)
		mlx_loop_end((*data)->engine->mlx);
	if (key == 100)
		(*data)->right = 1;
	if (key == 97)
		(*data)->left = 1;
	if (key == 65363)
		(*data)->move_cam_right = 1;
	if (key == 65361)
		(*data)->move_cam_left = 1;
	return (0);
}

int	key_release(int key, t_data **data)
{
	if (key == 119)
		(*data)->forward = 0;
	if (key == 115)
		(*data)->back = 0;
	if (key == 65307)
		mlx_loop_end((*data)->engine->mlx);
	if (key == 100)
		(*data)->right = 0;
	if (key == 97)
		(*data)->left = 0;
	if (key == 65363)
		(*data)->move_cam_right = 0;
	if (key == 65361)
		(*data)->move_cam_left = 0;
	return (0);
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
		return (1);
	}
	return (0);
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
		return (1);
	}
	return (0);
}