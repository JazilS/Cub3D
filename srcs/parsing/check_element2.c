/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:49:48 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 14:52:38 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_no(t_data *data)
{
	int	fd;

	fd = open(data->no, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		quit_error(INVALID_ELEMENT, data->garb_coll);
	}
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		quit_error(INVALID_ELEMENT, data->garb_coll);
	}
	return (0);
}

int	check_we(t_data *data)
{
	int	fd;

	fd = open(data->we, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		quit_error(INVALID_ELEMENT, data->garb_coll);
	}
	close(fd);
	fd = open(data->no, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		quit_error(INVALID_ELEMENT, data->garb_coll);
	}
	return (0);
}
