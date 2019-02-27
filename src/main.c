/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:22:32 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/25 10:22:33 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

# define FT_STDIN		(0)
# define EXIT_OK		(0)
# define EXIT_FAIL		(1)

/*
** Read user input.
*/

static int	read_input(char **line)
{
	ssize_t	buffer;

	buffer = 0;
	getline(&line, &bufsize, FT_STDIN);
	return (line && ret != -1 ? EXIT_OK : EXIT_FAIL);
}

/*
** Shell looping function.
*/

int			sh_loop(void)
{
	int		ret;
	int		loop;
	char	**line;
	char	**args;

	ret = EXIT_OK;
	loop = 1;
	while (loop)
	{
		printf("🍍 ");
		if ((ret = read_input(&line)))
			break ;
		free(line);
		// free(args);
	}
	return (ret);
}

// -----------------------------------------------------------------------------

/*
** Print usage message.
*/

static int	print_usage(char *bin)
{
	printf("usage: %s [option]\n", bin);
	return ;
}

/*
** Main program function
*/

int			main(int argc, char *argv[])
{
	int		ret;

	ret = EXIT_OK;
	if (argc == 1)
		ret = sh_loop();
	else if (argc == 2)
		ret = sh_loop(argv[1]);
	else if (argc > 2)
		print_usage(argv[0]);
	return (ret);
}