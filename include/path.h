/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:28:42 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 14:00:00 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "ft_printf.h"

int		path_dirs_init(char ***path_dirs_p, char *str);
void	delete_path_dirs(char **path_dirs);
void	print_path_dirs(char **path_dirs);
char	*find_path(const char *cmd, char **path_dirs);

#endif
