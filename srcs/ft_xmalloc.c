/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:37:06 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 10:37:32by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // perror
#include <stdlib.h> // malloc EXIT_FAILURE

void	*ft_xmalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
	{
		perror("pipex: ft_xmalloc");
		exit(EXIT_FAILURE);
	}
	return (result);
}
