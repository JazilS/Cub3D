/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:16:42 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/19 04:04:28 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data = ft_memset(data, 0, sizeof(t_data));
	data->garb_coll = malloc(sizeof(t_list **));
	if (!data->garb_coll)
		return ;
	*(data->garb_coll) = NULL;
	data->ea = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->f = NULL;
	data->c = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data);
	check(av[1], ac, &data);
	get_file(&data);
	get_and_check_element(&data);
	get_and_check_map(&data);
	path_finding(data.map, &data);
	exec(&data);
	return (ft_destroy_mlx(&data), clear(data), 0);
}
