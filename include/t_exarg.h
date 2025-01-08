/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exarg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 03:54:19 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 04:55:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXARG_H
# define T_EXARG_H
# include "e_return.h"

typedef struct s_exarg
{
	int		result;
	char	*path;
	char	**argv;
	char	**envp;
}	t_exarg;

#endif
