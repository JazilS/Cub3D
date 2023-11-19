/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:17:15 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/19 04:05:46 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len,
		t_list **garb_coll)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || !s || !len || len < 1)
	{
		str = ft_malloc(sizeof(char), garb_coll);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s))
		i = ft_strlen(s) + 1;
	if (len < ft_strlen(s))
		i = len + 1;
	if (len == ft_strlen(s))
		i = ft_strlen(s) - start + 1;
	str = ft_malloc(sizeof(char) * i, garb_coll);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], i);
	return (str);
}
