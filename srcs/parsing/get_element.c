/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:16:19 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/26 18:44:54 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_and_check_element(t_data *data)
{
	get_element(data->file, data);
	check_no(data);
	check_we(data);
	check_so(data);
	check_ea(data);
	check_virg(data->f, data);
	check_virg(data->c, data);
	check_f(data);
	check_c(data);
	return (0);
}

int	get_element(char **file, t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (file[i] && flag < 6)
	{
		while ((file[i] && file[i][0] == '\n') || (file[i]
				&& file[i][0] == '\0'))
			i++;
		get_element3(&flag, file, &i, data);
		i++;
	}
	data->pos_map = i;
	return (0);
}

void	get_element3(int *flag, char **file, int *i, t_data *data)
{
	if (!ft_strncmp(file[*i], "NO", 2) && !data->no)
	{
		if (ft_strncmp(file[*i] + (ft_strlen(file[*i]) - 4), ".xpm", 4))
			quit_error(TEXTURE_TYPE, data->garb_coll);
		data->no = ft_substr(file[*i], 3, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else if (!ft_strncmp(file[*i], "WE", 2) && !data->we)
	{
		if (ft_strncmp(file[*i] + (ft_strlen(file[*i]) - 4), ".xpm", 4))
			quit_error(TEXTURE_TYPE, data->garb_coll);
		data->we = ft_substr(file[*i], 3, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else
		get_element2(flag, file, i, data);
}

void	get_element2(int *flag, char **file, int *i, t_data *data)
{
	if (!ft_strncmp(file[*i], "SO", 2) && !data->so)
	{
		if (ft_strncmp(file[*i] + (ft_strlen(file[*i]) - 4), ".xpm", 4))
			quit_error(TEXTURE_TYPE, data->garb_coll);
		data->so = ft_substr(file[*i], 3, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else if (!ft_strncmp(file[*i], "EA", 2) && !data->ea)
	{
		if (ft_strncmp(file[*i] + (ft_strlen(file[*i]) - 4), ".xpm", 4))
			quit_error(TEXTURE_TYPE, data->garb_coll);
		data->ea = ft_substr(file[*i], 3, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else if (get_element4(flag, file, i, data))
		quit_error("Double texture", data->garb_coll);
}

int	get_element4(int *flag, char **file, int *i, t_data *data)
{
	if (!ft_strncmp(file[*i], "F", 1) && !data->f)
	{
		data->f = ft_substr(file[*i], 2, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else if (!ft_strncmp(file[*i], "C", 1) && !data->c)
	{
		data->c = ft_substr(file[*i], 2, ft_strlen(file[*i]), data->garb_coll);
		(*flag)++;
	}
	else
		return (1);
	return (0);
}
