/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:12:27 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 05:26:32 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*create_env(char *envp_single)
{
	size_t	src_len;
	size_t	var_len;
	char	*equal_ptr;
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	src_len = ft_strlen(envp_single);
	equal_ptr = ft_strchr(envp_single, '=');
	if (!equal_ptr)
		var_len = src_len;
	else
		var_len = equal_ptr - envp_single;
	env->var = ft_substr(envp_single, 0, var_len);
	if (!env->var)
		return (free(env), NULL);
	env->str = ft_substr(equal_ptr, 1, src_len);
	if (!env->str)
		return (free(env->var), free(env), NULL);
	return (env);
}

int	envs_init(t_data *data, char **envp)
{
	void	*content;
	t_list	*new;
	size_t	i;

	data->envs = NULL;
	i = 0;
	while (envp[i])
	{
		content = (void *)create_env(envp[i]);
		if (!content)
			return (1);
		new = ft_lstnew(content);
		if (!new)
			return (delete_env(content), 1);
		ft_lstadd_back(&data->envs, new);
		i++;
	}
	return (0);
}

t_env	*search_envs(t_list *envs, char *var)
{
	while (envs != NULL)
	{
		if (ft_strncmp(((t_env *)envs->content)->var, var, ft_strlen(var)) == 0)
			return ((t_env *)envs->content);
		envs = envs->next;
	}
	return (NULL);
}

void	print_env(t_env *env)
{
	if (env)
	{
		ft_printf("var:%s", env->var);
		ft_printf(", str:%s\n", env->str);
	}
	else
		ft_printf("(NULL)\n");
}

void	delete_env(void *env)
{
	free(((t_env *)env)->var);
	free(((t_env *)env)->str);
}
