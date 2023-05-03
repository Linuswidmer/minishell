/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:20:46 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/05/03 09:43:43 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	min_sub(t_ast *ast, t_dict *dict, t_builtins *build)
{
	pid_t	pid;
	int 	fdout;
	int 	status;
	int		exit;
	
	pid = fork();
	if (pid == -1)
		return (998);
	if (!pid)
		return (min_exit_handler(min_executer(ast->node.sub->down, dict, build, 0)));
	waitpid(-1, &status, 0);
	
	if (WEXITSTATUS(status) == 256 )
        exit = 1000;
    else
        exit = WEXITSTATUS(status) + 1000;
	return (exit);
}	
