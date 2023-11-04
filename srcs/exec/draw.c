/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:13:58 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 15:47:53 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	mlx_destroy_image(data->engine->mlx, data->engine->img.img);
	data->engine->img.img = mlx_new_image(data->engine->mlx, WIDTH, HEIGHT);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			data->engine->img.data[y * WIDTH + x] = data->engine->buf[y][x];
	}
	mlx_put_image_to_window(data->engine->mlx, data->engine->win,
		data->engine->img.img, 0, 0);
}

void	draw_utils(t_data *data, int step_x, int step_y)
{
	if (data->engine->side == 0)
		data->engine->perp_wall_dist = (data->engine->map_x
				- data->engine->pos_x + (1 - step_x) / 2)
			/ data->engine->ray_dirx;
	else
		data->engine->perp_wall_dist = (data->engine->map_y
				- data->engine->pos_y + (1 - step_y) / 2)
			/ data->engine->ray_diry;
	data->engine->line_height = (int)(HEIGHT / data->engine->perp_wall_dist);
	data->engine->draw_start = -data->engine->line_height / 2 + HEIGHT / 2;
	if (data->engine->draw_start < 0)
		data->engine->draw_start = 0;
	data->engine->draw_end = data->engine->line_height / 2 + HEIGHT / 2;
	draw_utils2(data);
}

void	draw_utils2(t_data *data)
{
	if (data->engine->draw_end >= HEIGHT)
		data->engine->draw_end = HEIGHT - 1;
	if (data->engine->side == 0)
		data->engine->wall_x = data->engine->pos_y
			+ data->engine->perp_wall_dist * data->engine->ray_diry;
	else
		data->engine->wall_x = data->engine->pos_x
			+ data->engine->perp_wall_dist * data->engine->ray_dirx;
	data->engine->wall_x -= floor(data->engine->wall_x);
	data->engine->tex_x = (int)(data->engine->wall_x
			* (double)data->engine->tex_width);
	if (data->engine->side == 0 && data->engine->ray_dirx > 0)
		data->engine->tex_x = data->engine->tex_width - data->engine->tex_x - 1;
	if (data->engine->side == 1 && data->engine->ray_diry < 0)
		data->engine->tex_x = data->engine->tex_width - data->engine->tex_x - 1;
}

int	get_num_tex(t_data *data)
{
	int	tex_num;

	tex_num = 0;
	if (data->engine->side == 0 && data->engine->map_x
		- data->engine->pos_x >= 0)
		tex_num = 0;
	else if (data->engine->side == 0 && data->engine->map_x
		- data->engine->pos_x < 0)
		tex_num = 1;
	else if (data->engine->side == 1 && data->engine->map_y
		- data->engine->pos_y < 0)
		tex_num = 2;
	else if (data->engine->side == 1 && data->engine->map_y
		- data->engine->pos_y >= 0)
		tex_num = 3;
	return (tex_num);
}

void	draw_color_texture(t_data *data, int x, int tex_num, double step)
{
	double	tex_pos;
	int		tmp;

	tmp = -1;
	tex_pos = (data->engine->draw_start - HEIGHT / 2 + data->engine->line_height
			/ 2) * step;
	while (++tmp < data->engine->draw_start)
		data->engine->buf[tmp][x] = data->rgb_c;
	tmp = data->engine->draw_end - 1;
	while (++tmp < HEIGHT)
		data->engine->buf[tmp][x] = data->rgb_f;
	draw_color_texture_utils(&data, tex_pos, step, tex_num);
}
