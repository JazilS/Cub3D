/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:30:35 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 06:25:50 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exec(t_data *data)
{
	data->engine = ft_malloc(sizeof(t_engine), data->garb_coll);
	init_engine(data->engine);
	get_player_pos(data->map, data);
	data->engine->mlx = mlx_init();
	if (!data->engine->mlx)
		quit_error(MLX_ERROR, data->garb_coll);
	data->engine->win = mlx_new_window(data->engine->mlx, WIDTH, HEIGHT,
			"Cub3D");
	if (!data->engine->win)
		quit_error(MLX_ERROR, data->garb_coll);
	set_images(data);
	mlx_loop_hook(data->engine->mlx, &main_loop, &data);
	mlx_hook(data->engine->win, 17, 0, mlx_loop_end, data->engine->mlx);
	mlx_hook(data->engine->win, 2, (1L << 0), key_press, &data);
	mlx_loop(data->engine->mlx);
	return (0);
}

int	init_engine(t_engine *engine)
{
	engine->pos_x = 0;
	engine->pos_y = 0;
	engine->map_x = 0;
	engine->map_y = 0;
	engine->dir_x = 0;
	engine->dir_y = 0;
	engine->delta_distx = 0;
	engine->delta_disty = 0;
	engine->side_distx = 0;
	engine->side_disty = 0;
	engine->perp_wall_dist = 0;
	engine->plane_x = 0;
	engine->plane_y = 0;
	engine->ray_dirx = 0;
	engine->ray_diry = 0;
	engine->wall_x = 0;
	engine->move_speed = 0.099;
	engine->rot_speed = 0.09;
	engine->side = 0;
	engine->tex_x = 0;
	engine->tex_width = 64;
	engine->tex_height = 64;
	return (0);
}

int	main_loop(t_data **data)
{
	calcul(data);
	draw(*data);
	return (0);
}

int	malloc_texture2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		data->engine->textures[i] = ft_malloc(sizeof(int)
				* (64 * 64), data->garb_coll);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (64 * 64))
			data->engine->textures[i][j] = 0;
	}
	return (1);
}

int	malloc_textures(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			data->engine->buf[i][j] = 0;
	}
	data->engine->textures = ft_malloc(sizeof(int *) * 4, data->garb_coll);
	if (!data->engine->textures)
		return (0);
	if (!malloc_texture2(data))
		return (0);
	return (1);
}
