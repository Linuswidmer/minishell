/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_bring_ast_to_beginning.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:20:03 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/05/04 11:23:13 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	min_bring_ast_to_beginning(t_ast **ast)
{
	if (!*ast)	
		return;		
	while (1)
	{
		if ((*ast)->key == jobnode)
		{
			if ((*ast)->node.job->up)
				*ast = (*ast)->node.job->up;
			else
				break;
		}
		else if((*ast)->key == subnode)
		{
			if ((*ast)->node.sub->up)
                *ast = (*ast)->node.sub->up;
            else
                break;
        }
		else if ((*ast)->key == pipenode)
		{
			if ((*ast)->node.pipe->prev)
				*ast = (*ast)->node.pipe->prev;
			else if ((*ast)->node.pipe->up)
                *ast = (*ast)->node.pipe->up;
			else
                break;
        }
		else if ((*ast)->key == routenode)
        {
            if ((*ast)->node.route->prev)
                *ast = (*ast)->node.route->prev;
            else if ((*ast)->node.route->up)
                *ast = (*ast)->node.route->up;
            else
                break;
		}
	}
	printf("end_bring\n");
}
