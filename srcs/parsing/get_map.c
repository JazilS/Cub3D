/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:36:05 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/25 18:32:30 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_and_check_map(t_data *data)
{
	get_map(data);
	check_valid_char(data->map, data);
	check_start(data->map, data);
	check_empty_line(data->map, data);
	return (0);
}

int	get_map(t_data *data)
{
	int	i;

	i = data->pos_map;
	while ((data->file[i] && data->file[i][0] == '\n') || (data->file[i]
			&& data->file[i][0] == '\0'))
		i++;
	if (!data->file[i])
		quit_error("Empty Map.", data->garb_coll);
	data->map = data->file + i;
	i = 0;
	while (data->map[i])
		i++;
	data->nb_column = i - 1;
	return (0);
}

int	check_empty_line(char **map, t_data *data)
{
	int	i;

	(void)data;
	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n' || map[i][0] == '\0')
			quit_error(EMPTY_LINE, data->garb_coll);
		i++;
	}
	return (0);
}

int	check_valid_char(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	(void)data;
	flag = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ')
				quit_error(INVALID_CHAR, data->garb_coll);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_start(char **map, t_data *data)
{
	int	i;
	int	j;
	int	flag;

	(void)data;
	flag = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				flag++;
			j++;
		}
		j = 0;
		i++;
	}
	if (flag > 1)
		quit_error(MUCH_NB_CHAR, data->garb_coll);
	else if (flag < 1)
		quit_error(FEW_NB_CHAR, data->garb_coll);
	return (0);
}
