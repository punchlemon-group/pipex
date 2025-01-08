/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:28:42 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 06:36:21 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "ft_printf.h"
# include "e_return.h"
# include "t_env.h"

int		path_dirs_init(char ***path_dirs_p, t_env *env);
void	delete_path_dirs(char **path_dirs);
void	print_path_dirs(char **path_dirs);
int		get_executable_path(char **path_dirs, char **path_p, const char *cmd);

#endif
