/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:37:02 by  jsabound         #+#    #+#             */
/*   Updated: 2023/11/01 14:32:23 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size, t_data *data)
{
	void	*s;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	s = ft_malloc((nmemb * size), data->garb_coll);
	if (!s)
		return (NULL);
	ft_bzero(s, size * nmemb);
	return (s);
}
