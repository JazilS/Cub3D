/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 05:38:30 by sagouasm          #+#    #+#             */
/*   Updated: 2023/11/04 07:13:56 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// 1er while = Verification premiere ligne
// 2eme while = Verification colonne de gauche
int	check_borders(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)data;
	while (map[i][j])
	{
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			i++;
		if (map[i][j++] != '1')
			quit_error(MAP_OPEN, data->garb_coll);
		i = 0;
	}
	j = 0;
	i = 1;
	while (map[i])
	{
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j++;
		if (map[i++][j] != '1')
			quit_error(MAP_OPEN, data->garb_coll);
		j = 0;
	}
	return (0);
}

// Verification ligne du bas
int	check_borders_suite(char **map, t_data *data)
{
	int	i;
	int	j;
	int	x;

	(void)data;
	i = data->nb_column;
	x = i;
	j = 0;
	while (map[i][j])
	{
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			i--;
		if (map[i][j] != '1')
			quit_error(MAP_OPEN, data->garb_coll);
		i = x;
		j++;
	}
	return (0);
}

//colonne de droite
int	check_borders_suite2(char **map, t_data *data)
{
	int	i;
	int	j;

	(void)data;
	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j--;
		if (map[i][j] != '1')
			quit_error(MAP_OPEN, data->garb_coll);
		i++;
		j = ft_strlen(map[i]) - 1;
	}
	return (0);
}
