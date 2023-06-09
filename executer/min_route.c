/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_route.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:30:25 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/07/05 17:51:54 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	min_route(t_ast *ast, t_dict *dict, t_builtins *build)
{
	int		exit;
	t_ast	*new;

	new = ast;
	exit = min_executer(new->u_no.route->down, dict, build, 1);
	while (exit != 1130 && exit >= 1000 && exit < 2000)
	{
		g_status = exit - 1000;
		while (new && new->u_no.route->rvalue == l_and && g_status)
			new = new->u_no.route->next;
		while (new && new->u_no.route->rvalue == l_or && !g_status)
			new = new->u_no.route->next;
		if (!new)
			break ;
		new = new->u_no.route->next;
		if (!new)
			break ;
		exit = min_executer(new->u_no.route->down, dict, build, 1);
	}
	return (exit);
}
