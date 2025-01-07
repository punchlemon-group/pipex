/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exarg.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:50:36 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/07 06:29:27 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXARG_H
# define EXARG_H
# define EXARG_FAILURE -1
# define EXARG_SUCCESS 0
# define PERMISSION_DENIED_STATUS 126
# define COMMAND_NOT_FOUND_STATUS 127
# include "libft.h"
# include "ft_printf.h"

enum
{
	MALLOC_FAILURE = 0,
	COMMAND_NOT_FOUND,
	PERMISSION_DENIED,
	EXECUTABLE,
};

typedef struct s_args
{
	int			argc;
	const char	**argv;
	char		**envp;
}	t_args;

typedef struct s_exarg
{
	int		status;
	char	*path;
	char	**argv;
	char	**envp;
}	t_exarg;

void	*create_exarg_content(const char *cmd, char **path_dirs, char **envp);
void	delete_exarg_content(void *void_exarg_content);
int		exarg_list_init(t_list **exarg_list_p, t_args *args, char **path_dirs,
			int *i);
void	print_exarg_content(t_exarg *exarg_content);

#endif
