/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:16:42 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/07 22:08:24 by sagouasm         ###   ########.fr       */
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

// int i = 0;
// while (data.file[i])
// {
// 	printf("%s\n", data.file[i]);
// 	i++;
// }
// i = 0;
// while (data.map[i])
// {
// 	printf("%s\n", data.map[i]);
// 	i++;
// }
// printf("nb = %d\n", data.nb_column);
// i = 0;
// while (data.map_path[i])
// {
// 	printf("%s\n", data.map_path[i]);
// 	i++;
// }
// printf("%c\n", data.map[i - 1][5]);
// path_finding(data.map, &data);
// get_and_check_element(&data);
// printf("NO = %s\n", data.no);
// printf("WE = %s\n", data.we);
// printf("SO = %s\n", data.so);
// printf("EA = %s\n", data.ea);
// printf("F = %s\n", data.f);
// printf("C = %s\n", data.c);