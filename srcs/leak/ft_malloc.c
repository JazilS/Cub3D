/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:25:42 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/24 16:30:25 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_malloc(unsigned int size, t_list **garb_coll)
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
		quit_error(MALLOC_ERROR, garb_coll);
	ft_lstadd_back(garb_coll, ft_lstnew(pointer));
	return (pointer);
}

void	clear(t_data data)
{
	ft_lstclear(data.garb_coll, free);
}

void	ft_destroy_mlx(t_data *data)
{
	mlx_destroy_image(data->engine->mlx, data->engine->img.img);
	mlx_destroy_window(data->engine->mlx, data->engine->win);
	mlx_destroy_display(data->engine->mlx);
	free(data->engine->mlx);
}

void	ft_destroy(t_data *data)
{
	mlx_destroy_image(data->engine->mlx, data->engine->img.img);
	mlx_destroy_display(data->engine->mlx);
	free(data->engine->mlx);
}
