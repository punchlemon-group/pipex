/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 04:38:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "pipex.h"

t_env	*create_env(char *envp_single);
int		envs_init(t_data *data, char **envp);
t_list	*search_envs(t_list *envs, char *var);
void	print_env(t_env *env);
void	delete_env(void *env);

#endif
