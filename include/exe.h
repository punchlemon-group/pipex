/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:50:36 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 06:55:38 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXE_H
# define EXE_H
# define EXE_FAILURE -1
# define EXE_SUCCESS 0
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
	char	*pathname;
	char	**argv;
	char	**envp;
}	t_exarg;

void	*create_exarg_content(const char *cmd, char **path_dirs, char **envp);
void	delete_exarg_content(void *void_exarg_content);
int		exarg_list_init(t_list **exarg_list_p, t_args *args, char **path_dirs);
void	print_exarg_content(t_exarg *exarg_content);

#endif
