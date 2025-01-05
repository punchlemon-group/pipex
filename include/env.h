/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 06:45:22 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"
# include "ft_printf.h"

typedef struct s_env
{
	char	*var;
	char	*str;
}	t_env;

t_env	*create_env(char *envp_single);
t_env	*search_envs(t_list *envs, char *var);
int		envs_init(t_list **envsp, char **envp);
void	print_env(t_env *env);
void	delete_env(void *env);

#endif
