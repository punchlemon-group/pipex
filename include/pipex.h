/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:23 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 10:53:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h> // perror
# include <fcntl.h> // open
# include <stdlib.h> // exit
# include <sys/types.h> // pid_t
# include <sys/wait.h> // waitpid
# include <unistd.h> // fork access read write execve
# include <errno.h> // errno
# include "libft.h"
# include "ft_dprintf.h"
# include "pipex_end.h"
# include "t_data.h"
# include "e_return.h"

void	preprocess(t_data *data, int argc, const char **argv, char **envp);

#endif 
