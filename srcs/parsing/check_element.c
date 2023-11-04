/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:19:29 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 14:15:47 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_so(t_data *data)
{
	int	fd;

	fd = open(data->so, O_RDONLY);
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

int	check_ea(t_data *data)
{
	int	fd;

	fd = open(data->ea, O_RDONLY);
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

int	check_virg(char *f, t_data *data)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		quit_error(INVALID_ELEMENT, data->garb_coll);
	return (0);
}

int	check_f(t_data *data)
{
	int		tab[3];
	char	**temp;

	temp = ft_split(data->f, ',');
	tab[0] = ft_atoi(temp[0]);
	tab[1] = ft_atoi(temp[1]);
	tab[2] = ft_atoi(temp[2]);
	if (tab[0] > 255 || tab[1] > 255 || tab[2] > 255 || tab[0] < 0 || tab[1] < 0
		|| tab[2] < 0)
		quit_error(INVALID_ELEMENT, data->garb_coll);
	data->rgb_f = 65536 * tab[0] + 256 * tab[1] + tab[2];
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	return (0);
}

int	check_c(t_data *data)
{
	int		tab[3];
	char	**temp;

	temp = ft_split(data->c, ',');
	tab[0] = ft_atoi(temp[0]);
	tab[1] = ft_atoi(temp[1]);
	tab[2] = ft_atoi(temp[2]);
	if (tab[0] > 255 || tab[1] > 255 || tab[2] > 255 || tab[0] < 0 || tab[1] < 0
		|| tab[2] < 0)
		quit_error(INVALID_ELEMENT, data->garb_coll);
	data->rgb_c = 65536 * tab[0] + 256 * tab[1] + tab[2];
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	return (0);
}
