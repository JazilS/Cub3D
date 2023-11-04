/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:49:52 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 05:48:48 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_map(char **map, t_data *data)
{
	int	len;

	data->map_path = create_copie(map, data);
	len = get_len(map);
	data->map_path = get_map_path(map, len, data);
	data->map_game = get_map_game(create_copie(data->map_path, data));
	return (0);
}

char	**get_map_game(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map);
}

char	*final_map(char *str, int len, t_data *data)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_malloc(sizeof(temp) * len, data->garb_coll);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	while (i < len)
	{
		temp[i] = '0';
		i++;
	}
	temp[i] = '\0';
	i = 0;
	while (temp[i] && i < len)
	{
		if (temp[i] == ' ')
			temp[i] = '0';
		i++;
	}
	return (temp);
}

char	**get_map_path(char **map, int len, t_data *data)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_malloc(sizeof(temp) * (data->nb_column + 2), data->garb_coll);
	while (map[i])
	{
		temp[i] = final_map(map[i], len, data);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	get_len(char **map)
{
	int	len;
	int	i;
	int	res;

	res = 0;
	i = 0;
	len = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		while (map[i][len - 1] == ' ')
			len--;
		if (len > res)
			res = len;
		i++;
	}
	return (res);
}
