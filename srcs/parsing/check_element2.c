/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:48 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/26 18:40:55 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_no(t_data *data)
{
	int	fd;

	fd = open(data->no, O_RDONLY);
	if (fd == -1)
		quit_error("Invalid NO", data->garb_coll);
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
		quit_error("NO is a directory", data->garb_coll);
	return (0);
}

int	check_we(t_data *data)
{
	int	fd;

	fd = open(data->we, O_RDONLY);
	if (fd == -1)
		quit_error("Invalid WE", data->garb_coll);
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
		quit_error("WE is a directory", data->garb_coll);
	return (0);
}

int	check_so(t_data *data)
{
	int	fd;

	fd = open(data->so, O_RDONLY);
	if (fd == -1)
		quit_error("Invalid SO", data->garb_coll);
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
		quit_error("SO is a directory", data->garb_coll);
	return (0);
}

int	check_ea(t_data *data)
{
	int	fd;

	fd = open(data->ea, O_RDONLY);
	if (fd == -1)
		quit_error("Invalid EA", data->garb_coll);
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
		quit_error("EA is a directory", data->garb_coll);
	return (0);
}
