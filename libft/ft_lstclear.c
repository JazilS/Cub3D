/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagouasm <sagouasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:04:04 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/04 06:37:42 by sagouasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*tmp;

	i = *lst;
	while (i != NULL )
	{
		tmp = i;
		i = tmp->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
	free(lst);
}
