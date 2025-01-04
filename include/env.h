/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 08:05:46 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_env
{
	char	*var;
	char	*str;
}	t_env;

typedef struct s_data
{
	t_env	*env;
}	t_data;

void	env_init_single(t_env *env, char *envp_single);
void	env_init(t_data *data, char **envp);
char	*search_env(t_env *env, char *var);
void	print_env(t_env *env);
void	delete_env(t_env *env);

#endif
