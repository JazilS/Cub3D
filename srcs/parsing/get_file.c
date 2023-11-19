/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:17:53 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/19 16:48:12 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*realloc_map(void *ptr, size_t ptrsize, size_t newsize, t_data *data)
{
	void	*newptr;

	if (ptr == NULL)
		return (ft_calloc(newsize, 1, data));
	if (newsize == 0)
		return (NULL);
	if (newsize <= ptrsize)
		return (ptr);
	newptr = ft_calloc(newsize, 1, data);
	if (newptr == NULL)
		return (NULL);
	ft_memcpy(newptr, ptr, ptrsize);
	return (newptr);
}

int	ft_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_count_space(char *line)
{
	int	i;

	i = 0;
	while (ft_space(line[i]))
		i++;
	return (i);
}

int	get_file(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = ft_strdup("", data);
		line = get_next_line(data->fd, data);
		if (!line)
			break ;
		if (i == 0 && (size_t)ft_count_space(line) == ft_strlen(line))
			continue ;
		if (*(line + ft_count_space(line)) == '\0' && i == 0)
			continue ;
		data->file = realloc_map(data->file,
				sizeof(char *) * (i + 1), sizeof(char *) * (i + 2), data);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		data->file[i++] = line;
		data->file[i] = NULL;
	}
	if (i == 0)
		quit_error("Map not valid", data->garb_coll);
	return (close(data->fd), 0);
}
