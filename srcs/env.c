/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:12:27 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 16:27:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	*create_env_content(char *envp_single)
{
	size_t	src_len;
	size_t	var_len;
	char	*equal_ptr;
	t_env	*env_content;

	env_content = malloc(sizeof(t_env));
	if (env_content == NULL)
		return (NULL);
	src_len = ft_strlen(envp_single);
	equal_ptr = ft_strchr(envp_single, '=');
	if (!equal_ptr)
		var_len = src_len;
	else
		var_len = equal_ptr - envp_single;
	env_content->var = ft_substr(envp_single, 0, var_len);
	if (env_content->var == NULL)
		return (free(env_content), NULL);
	env_content->str = ft_substr(equal_ptr, 1, src_len);
	if (env_content->str == NULL)
		return (free(env_content->var), free(env_content), NULL);
	return ((void *)env_content);
}

void	delete_env_content(void *void_env_content)
{
	t_env	*env_content;

	env_content = (t_env *)void_env_content;
	if (env_content != NULL)
	{
		if (env_content->var != NULL)
			free(env_content->var);
		if (env_content->str != NULL)
			free(env_content->str);
		free(env_content);
	}
}

int	env_list_init(t_list **env_list_p, char **envp)
{
	void	*void_env_content;
	t_list	*new;
	size_t	i;

	*env_list_p = NULL;
	i = 0;
	while (envp[i])
	{
		void_env_content = create_env_content(envp[i]);
		if (void_env_content == NULL)
			return (ENV_FAILURE);
		new = ft_lstnew(void_env_content);
		if (new == NULL)
			return (delete_env_content(void_env_content), ENV_FAILURE);
		ft_lstadd_back(env_list_p, new);
		i++;
	}
	return (ENV_SUCCESS);
}

t_env	*search_env_list(t_list *env_list, char *var)
{
	t_env	*env_content;

	while (env_list != NULL)
	{
		env_content = (t_env *)env_list->content;
		if (ft_strncmp(env_content->var, var, ft_strlen(var)) == 0)
			return (env_content);
		env_list = env_list->next;
	}
	return (NULL);
}

void	print_env_content(t_env *env_content)
{
	if (env_content != NULL)
	{
		ft_printf("var:%s", env_content->var);
		ft_printf(", str:%s\n", env_content->str);
	}
	else
		ft_printf("(NULL)\n");
}
