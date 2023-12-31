/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:56 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/24 18:19:19 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_images(t_data *data)
{
	t_imag	img;

	if (!malloc_textures(data))
		quit_error("Failed to set images", data->garb_coll);
	if (!set_main_img(data))
		quit_error("Failed to create image", data->garb_coll);
	if (!load_image(data, data->engine->textures[0], data->so,
			&img))
		quit_error("Failed to set images", data->garb_coll);
	if (!load_image(data, data->engine->textures[1], data->no,
			&img))
		quit_error("Failed to set images", data->garb_coll);
	if (!load_image(data, data->engine->textures[2], data->we,
			&img))
		quit_error("Failed to set images", data->garb_coll);
	if (!load_image(data, data->engine->textures[3], data->ea,
			&img))
		quit_error("Failed to set images", data->garb_coll);
	return (1);
}

int	set_main_img(t_data *data)
{
	data->engine->img.img = mlx_new_image(data->engine->mlx, WIDTH, HEIGHT);
	if (!data->engine->img.img)
		return (0);
	data->engine->img.data = (int *)mlx_get_data_addr(data->engine->img.img,
			&data->engine->img.bpp, &data->engine->img.size_l,
			&data->engine->img.endian);
	return (1);
}

int	load_image(t_data *data, int *texture, char *path, t_imag *img)
{
	int	x;
	int	y;

	y = -1;
	img->img = mlx_xpm_file_to_image(data->engine->mlx, path, &img->img_width,
			&img->img_height);
	if (img->img)
		img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
				&img->endian);
	if (!img->img || img->img_height != 64 || img->img_width != 64
		|| !img->data)
	{
		mlx_destroy_image(data->engine->mlx, img->img);
		return (ft_destroy(data), 0);
	}
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(data->engine->mlx, img->img);
	return (1);
}
