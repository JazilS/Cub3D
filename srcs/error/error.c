/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:25:22 by jsabound          #+#    #+#             */
/*   Updated: 2023/11/24 16:04:36 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	quit_error(char *msg, t_list **garb_coll)
{
	print_error(msg);
	ft_lstclear(garb_coll, free);
	exit(1);
}

void	quit_error_no_free(char *msg)
{
	print_error(msg);
	exit(1);
}

void	little_free(t_data *data)
{
	if (data && data->garb_coll)
		free(data->garb_coll);
}

void	check(char *file, int ac, t_data *data)
{
	if (check_nb_arg(ac))
	{
		little_free(data);
		if (check_nb_arg(ac) == 1)
			quit_error_no_free(TOO_MUCH_ARG_ERROR);
		if (check_nb_arg(ac) == 2)
			quit_error_no_free(TOO_FEW_ARG_ERROR);
	}
	if (check_file_name(file))
	{
		little_free(data);
		quit_error_no_free(INCORRECT_FILE_NAME_ERROR);
	}
	if (check_file_exist(file, data))
	{
		little_free(data);
		quit_error_no_free(FILE_NOT_EXIST_ERROR);
	}
	if (check_is_directory(file))
	{
		little_free(data);
		close(data->fd);
		quit_error_no_free(FILE_IS_DIR_ERROR);
	}
}
