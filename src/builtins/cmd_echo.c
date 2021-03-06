/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:08:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/05/17 17:08:36 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Get the enviroment variable content.
*/

static char	*get_eval(char **env, char *arg)
{
	int		i;
	char	*eval;

	i = 0;
	eval = NULL;
	while (env && env[++i])
		if (!ft_strncmp(env[i], (arg + 1), ft_strlen(arg) - 1))
			eval = ft_strrchr(env[i], '=') + 1;
	return (eval);
}

/*
** Print (echo) a passed argument.
*/

static char	*echo_arg(char **env, char *arg, int last)
{
	char	*str;

	if ((str = ((arg && arg[0] == '$') ? get_eval(env, arg) : arg)))
		ft_putstr(str);
	ft_putchar(!last ? ' ' : '\n');
	return (str);
}

/*
** Builtin echo command implementation.
*/

char		**cmd_echo(char **args, char **env, char *name)
{
	int		i;

	i = 0;
	if (*args && args[1])
		while (args[++i])
			echo_arg(env, args[i], (args[i + 1] ? 0 : 1));
	return (env);
	(void)name;
}
