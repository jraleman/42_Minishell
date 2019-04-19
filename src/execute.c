/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:28:30 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/22 17:28:31 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Execute process.
*/

static int	execute_ps(char *ex, char **args, char **env, char *name)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(ex, args, env) == -1 \
			? ft_error(1, name, "permission denied") : 0;
	else if (pid < 0)
		ft_error(1, name, "failed to fork");
	else
		wait(&pid);
	return (1);
}

/*
** Check for command error.
*/

static void	check_error(char *p, char *arg)
{
	int i;
	int slash;

	i = -1;
	slash = 0;
	while (arg[++i])
		if (arg[i] == '/')
			slash += 1;
	if (slash > 0 && !p)
		write(1, "no such file or directory\n", ft_strlen( "no such file or directory\n"));
	else if (!p)
		write(1, "command not found\n", ft_strlen( "command not found\n"));
	return ;
}

/*
** Find a command.
*/

static void	find_cmd(char **args, char **env)
{
	char	**p;
	char	*path;
	int		i;

	i = -1;
	p = ft_strtok(ft_find_env("$PATH", env), ":");
	path = ft_strnew(PATH_MAX);
	while (p[++i])
	{
		ft_strclr(path);
		ft_strcat(path, p[i]);
		(args[0][0] != '/') ? ft_strcat(path, "/") : 0;
		ft_strcat(path, args[0]);
		if (access(path, F_OK) != -1)
		{
			execute_ps(path, args, env, "minishell");
			break ;
		}
	}
	check_error(p[i], args[0]);
	i = -1;
	while (p[++i])
		free(p[i]);
	free(path);
	free(p);
}

/*
** Execute a command.
*/

char		**execute(char **args, char **env)
{
	int		i;

	i = -1;
	if (!args || !*args || !**args)
		return (env);
	while (++i < BLT_NUM)
		if (!ft_strcmp(args[0], blt_str(i)))
			return ((*blt_func(i))(args, env));
	if (access(args[0], F_OK) != -1)
		execute_ps(args[0], args, env, "minishell");
	else
		find_cmd(args, env);
	return (env);
}
