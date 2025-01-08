/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:35:21 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 03:36:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H
# include "libft.h"
# include "exarg.h"

typedef struct s_data
{
	t_args	args;
	t_list	*env_list;
	char	**path_dirs;
	t_list	*exarg_list;
	int		i_fd;
	int		o_fd;
}	t_data;

#endif
