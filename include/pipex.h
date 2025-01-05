/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:23 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 13:59:06 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <stdio.h> // perror
# include <stdlib.h> // exit
# include <sys/types.h> // pid_t
# include <unistd.h> // fork access read write execve
# include "libft.h"
# include "env.h"

typedef struct s_data
{
	t_list	*envs;
	char	**path_dirs;
}	t_data;

typedef struct s_exec_args
{
	char	*pathname;
	char	**argv;
	char	**envp;
}	t_exec_args;

#endif 
