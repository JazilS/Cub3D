/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:42:26 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 08:08:05 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*s;
// 	size_t	i;

// 	i = 0;
// 	if (size != 0 && count > SIZE_MAX / size)
// 		return (NULL);
// 	s = malloc(count * size);
// 	if (!s)
// 		return (NULL);
// 	while (i < count * size)
// 	{
// 		s[i] = 0;
// 		i++;
// 	}
// 	return (s);
// }

char	*ft_strjoin(char *s1, char *s2, t_data *list)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1, list);
	str = ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1),
			list->garb_coll);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
