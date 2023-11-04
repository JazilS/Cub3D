/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:47:37 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 15:47:55 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_color_texture_utils(t_data **data, double tex_pos, double step,
		int tex_num)
{
	int	y;
	int	color;
	int	tex_y;

	y = (*data)->engine->draw_start - 1;
	while (++y <= (*data)->engine->draw_end)
	{
		tex_y = (int)tex_pos & ((*data)->engine->tex_height - 1);
		tex_pos += step;
		color = (*data)->engine->textures[tex_num][(*data)->engine->tex_height
			* tex_y + (*data)->engine->tex_x];
		if ((*data)->engine->side == 1)
			color = (color >> 1) & 8355711;
		(*data)->engine->buf[y][(*data)->x] = color;
		(*data)->engine->re_buf = 1;
	}
}
