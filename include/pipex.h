/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:23 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/07 05:57:08 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h> // open
# include <stdio.h> // perror
# include <stdlib.h> // exit
# include <sys/types.h> // pid_t
# include <sys/wait.h> // waitpid
# include <unistd.h> // fork access read write execve
# include "libft.h"
# include "env.h"
# include "path.h"
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
