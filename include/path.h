/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:28:42 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 06:08:16 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# define PATH_FAILURE -1
# define PATH_SUCCESS 0
# include "libft.h"
# include "ft_printf.h"

int		path_dirs_init(char ***path_dirs_p, char *str);
void	delete_path_dirs(char **path_dirs);
int		find_path(char **pathname_p, const char *cmd, char **path_dirs);
// void	print_path_dirs(char **path_dirs);

#endif
