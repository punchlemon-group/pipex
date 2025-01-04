/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:12:27 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/05 08:05:26 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_init_single(t_env *env, char *envp_single)
{
	size_t	src_len;
	size_t	var_len;
	char	*equal_ptr;

	src_len = ft_strlen(envp_single);
	equal_ptr = ft_strchr(envp_single, '=');
	if (!equal_ptr)
	{
		env->var = ft_substr(envp_single, 0, src_len);
		env->str = NULL;
	}
	else
	{
		var_len = equal_ptr - envp_single;
		env->var = ft_substr(envp_single, 0, var_len);
		env->str = ft_substr(envp_single, var_len + 1, src_len - var_len - 1);
	}
}

void	env_init(t_data *data, char **envp)
{
	size_t	env_len;
	// t_env	*env;
	size_t	i;

	env_len = 0;
	while (envp[env_len])
		env_len++;
	data->env = malloc(sizeof(t_env) * (env_len + 1));
	if (!data->env)
		return ((void)0);
	i = 0;
	while (i < env_len + 1)
	{
		data->env[i].var = NULL;
		data->env[i++].str = NULL;
	}
	i = 0;
	while (i < env_len)
	{
		env_init_single(&(data->env[i]), envp[i]);
		if (!data->env[i].var || !data->env[i].str)
			return (delete_env(data->env), data->env = NULL, (void)0);
		i++;
	}
}

char	*search_env(t_env *env, char *var)
{
	int	i;
	
	i = 0;
	while (env[i].var)
	{
		if (ft_strncmp(env[i].var, var, 4) == 0)
			return (env[i].str);
		i++;
	}
	return (NULL);
}

void	print_env(t_env *env)
{
	size_t	i;

	i = 0;
	while (env[i].var)
	{
		ft_printf("var:%s", env[i].var);
		ft_printf(", str:%s\n", env[i].str);
		i++;
	}
}

void	delete_env(t_env *env)
{
	size_t	i;

	i = 0;
	while (env[i].var)
	{
		free(env[i].var);
		free(env[i].str);
	}
	free(env);
}
