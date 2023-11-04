/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:57:49 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 14:25:13 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file_name(char *file)
{
	int	i;

	i = ft_strlen(file);
	i--;
	if (file[i + 1] || file[i] != 'b' || file[i - 1] != 'u'
		|| file[i - 2] != 'c' || file[i - 3] != '.')
		return (1);
	return (0);
}

int	check_nb_arg(int ac)
{
	if (ac > 2)
		return (1);
	else if (ac < 2)
		return (1);
	return (0);
}

int	check_file_exist(char *file, t_data *data)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	data->fd = fd;
	return (0);
}

int	check_is_directory(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}
