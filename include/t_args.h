/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_args.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:37:27 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 03:38:03 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARGS_H
# define T_ARGS_H

typedef struct s_args
{
	int			argc;
	const char	**argv;
	char		**envp;
}	t_args;

#endif
