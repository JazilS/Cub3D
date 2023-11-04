/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:49:05 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/01 14:33:32 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdlib.h>
#include "../includes/cub3d.h"

char	*ft_strdup(const char *s, t_data *data)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_malloc(sizeof(char) * ft_strlen(s) + 1, data->garb_coll);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
