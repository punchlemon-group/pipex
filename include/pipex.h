/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:23 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/04 23:39:56 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <stdio.h> // perror
# include <stdlib.h> // exit
# include <sys/types.h> // pid_t
# include <unistd.h> // fork access read write
# include "libft.h"

typedef struct s_env
{
	char			*var;
	char			*str;
}	t_env;

typedef struct s_path
{
	char			*path;
	struct s_path	*next;
}	t_path;

typedef struct s_data
{
	t_list	*envs;
	t_list	*paths;
}	t_data;

#endif 
