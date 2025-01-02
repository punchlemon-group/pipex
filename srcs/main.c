/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:30 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/02 11:40:34 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // open
#include <stdio.h> // perror
#include <stdlib.h> // exit
#include <sys/types.h> // pid_t
#include <unistd.h> // fork

int	main(int argc, char *argv[])
{
	int		fd;
	pid_t	pid;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror(argv[1]), EXIT_FAILURE);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), EXIT_FAILURE);
		close(fd);
	}
	return (EXIT_SUCCESS);
}
