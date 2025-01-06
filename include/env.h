/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:13:11 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 06:30:03 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# define ENV_FAILURE -1
# define ENV_SUCCESS 0
# include "libft.h"
# include "ft_printf.h"

typedef struct s_env
{
	char	*var;
	char	*str;
}	t_env;

void	*create_env_content(char *envp_single);
t_env	*search_env_list(t_list *envs, char *var);
int		env_list_init(t_list **envsp, char **envp);
void	print_env_content(t_env *env_content);
void	delete_env_content(void *void_env_content);

#endif
