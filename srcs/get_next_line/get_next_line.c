/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:44:25 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 06:09:19 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

typedef struct s_temp
{
	long	len;
	char	*temp;
	int		fd;
}			t_temp;

char	*ft_delete(char *temp, t_data *list)
{
	int		i;
	int		j;
	char	*str;

	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	str = NULL;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i])
	{
		str = ft_malloc(sizeof(char) * (ft_strlen(temp) - i + 1),
				list->garb_coll);
		if (!str)
			return (NULL);
		if (temp[i] == '\n')
			i++;
		while (temp[i] != '\0')
			str[j++] = temp[i++];
		str[j] = '\0';
	}
	return (str);
}

char	*ft_res(char *gnl, t_data *list)
{
	char	*res;
	int		i;
	int		j;

	if (!gnl || !*gnl)
		return (NULL);
	i = 0;
	while (gnl[i] && gnl[i] != '\n')
		i++;
	if (gnl[i] == '\n')
		i++;
	res = ft_malloc(sizeof(char) * (i + 1), list->garb_coll);
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = gnl[j];
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_write(t_temp s_temp, char *gnl, int fd, t_data *list)
{
	if (BUFFER_SIZE < 0)
		return (NULL);
	s_temp.len = read(fd, s_temp.temp, BUFFER_SIZE);
	if (s_temp.len < 0)
		return (NULL);
	s_temp.temp[s_temp.len] = '\0';
	gnl = ft_strjoin(gnl, s_temp.temp, list);
	return (gnl);
}

char	*get_next_line(int fd, t_data *list)
{
	static char	*gnl;
	char		*res;
	t_temp		s_temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_temp.temp = ft_malloc(sizeof(char) * (BUFFER_SIZE + 1), list->garb_coll);
	s_temp.len = 1;
	while (s_temp.len && !ft_strchr(gnl, '\n'))
	{
		gnl = ft_write(s_temp, gnl, fd, list);
		if (!gnl || BUFFER_SIZE > (int)ft_strlen(s_temp.temp))
			break ;
	}
	res = ft_res(gnl, list);
	gnl = ft_delete(gnl, list);
	return (res);
}

/*int main(void)
 {
 	int fd;
 	char	*str;

 	fd = open("get_next_line.h", O_RDONLY);
 	str = get_next_line(fd);
 	while(str != NULL)
 	{
 		printf("%s", str);
 		free(str);
 		str = get_next_line(fd);
 	}
 	close(fd);
 }
*/