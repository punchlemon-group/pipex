/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 05:28:42 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 08:21:17 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "ft_printf.h"

typedef struct s_path
{
	char	*path;
}	t_path;

int		paths_init(char ***paths, char *str);
void	print_paths(char **paths);
char	*find_path(char *cmd, char **paths);

#endif
