/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exarg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:57:08 by retanaka          #+#    #+#             */
/*   Updated: 2025/01/06 16:29:16 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exarg.h"
#include "path.h"

void	*create_exarg_content(const char *cmd, char **path_dirs, char **envp)
{
	char	**argv;
	t_exarg	*exarg_content;

	exarg_content = malloc(sizeof(t_exarg));
	if (exarg_content == NULL)
		return (NULL);
	argv = malloc(sizeof(char *) * 2);
	if (argv == NULL)
		return (free(exarg_content), NULL);
	argv[0] = ft_strdup(cmd);
	if (argv[0] == NULL)
		return (free(exarg_content), free(argv), NULL);
	argv[1] = NULL;
	exarg_content->argv = argv;
	exarg_content->envp = envp;
	exarg_content->status = find_path(&exarg_content->pathname, cmd, path_dirs);
	return ((void *)exarg_content);
}

void	delete_exarg_content(void *void_exarg_content)
{
	t_exarg	*exarg_content;

	exarg_content = (t_exarg *)void_exarg_content;
	if (exarg_content != NULL)
	{
		if (exarg_content->argv != NULL)
		{
			free(exarg_content->argv[0]);
			free(exarg_content->argv);
		}
		if (exarg_content->status != MALLOC_FAILURE
			&& exarg_content->pathname != NULL)
			free(exarg_content->pathname);
		free(exarg_content);
	}
}

int	exarg_list_init(t_list **exarg_list_p, t_args *args, char **path_dirs)
{
	void	*void_exarg_content;
	t_list	*new;
	size_t	i;
	size_t	argv_offset;
	size_t	len;

	*exarg_list_p = NULL;
	if (args->argc < 5)
		return (write(2, "arguments is too short\n", 23), EXARG_FAILURE);
	argv_offset = 2;
	len = args->argc - 3;
	i = 0;
	while (i < len)
	{
		void_exarg_content = create_exarg_content(args->argv[argv_offset + i],
				path_dirs, args->envp);
		if (void_exarg_content == NULL)
			return (EXARG_FAILURE);
		new = ft_lstnew(void_exarg_content);
		if (new == NULL)
			return (delete_exarg_content(void_exarg_content), EXARG_FAILURE);
		ft_lstadd_back(exarg_list_p, new);
		i++;
	}
	return (EXARG_SUCCESS);
}

void	print_exarg_content(t_exarg *exarg_content)
{
	if (exarg_content != NULL)
	{
		ft_printf("pathname:%s\n", exarg_content->pathname);
	}
	else
		ft_printf("(NULL)\n");
}
