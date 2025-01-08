/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exarg.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:50:36 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 05:04:37 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXARG_H
# define EXARG_H
# define PERMISSION_DENIED_STATUS 126
# define COMMAND_NOT_FOUND_STATUS 127
# include "libft.h"
# include "ft_printf.h"
# include "path.h"
# include "t_args.h"
# include "t_exarg.h"

void	*create_exarg_content(const char *cmd, char **path_dirs, char **envp);
void	delete_exarg_content(void *void_exarg_content);
int		exarg_list_init(t_list **exarg_list_p, t_args *args, char **path_dirs,
			int *i);
void	print_exarg_content(t_exarg *exarg_content);

#endif
