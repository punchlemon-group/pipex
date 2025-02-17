/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/08 05:03:36 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "libft.h"
# include "ft_printf.h"
# include "e_return.h"
# include "t_env.h"

void	*create_env_content(char *envp_single);
t_env	*search_env_list(t_list *envs, char *var);
int		env_list_init(t_list **envsp, char **envp);
void	print_env_content(t_env *env_content);
void	delete_env_content(void *void_env_content);

#endif
