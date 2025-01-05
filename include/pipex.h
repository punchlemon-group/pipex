/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:23 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 06:45:27 by retanaka         ###   ########.fr       */
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
# include "env.h"

typedef struct s_data
{
	t_list	*envs;
	char	**paths;
}	t_data;

#endif 
