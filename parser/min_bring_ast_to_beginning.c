/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_bring_ast_to_beginning.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:20:03 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/06/23 16:15:18 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	ft_jobnode(t_ast **ast)
{
	if ((*ast)->u_no.job->up)
	{
		*ast = (*ast)->u_no.job->up;
		return (0);
	}
	else
		return (1);
}

static int	ft_subnode(t_ast **ast)
{
	if ((*ast)->u_no.sub->up)
	{
		*ast = (*ast)->u_no.sub->up;
		return (0);
	}
	else
		return (1);
}

static int	ft_pipenode(t_ast **ast)
{
	if ((*ast)->u_no.pipe->prev)
	{
		*ast = (*ast)->u_no.pipe->prev;
		return (0);
	}
	else if ((*ast)->u_no.pipe->up)
	{
		*ast = (*ast)->u_no.pipe->up;
		return (0);
	}
	return (1);
}

static int	ft_routenode(t_ast **ast)
{
	if ((*ast)->u_no.route->prev)
	{
		*ast = (*ast)->u_no.route->prev;
		return (0);
	}
	else if ((*ast)->u_no.route->up)
	{
		*ast = (*ast)->u_no.route->up;
		return (0);
	}
	return (1);
}

void	min_bring_ast_to_beginning(t_ast **ast)
{
	if (!*ast)
		return ;
	while (1)
	{
		if ((*ast)->key == jobnode)
		{
			if (ft_jobnode(ast))
				break ;
		}
		else if ((*ast)->key == subnode)
		{
			if (ft_subnode(ast))
				break ;
		}
		else if ((*ast)->key == pipenode)
		{
			if (ft_pipenode(ast))
				break ;
		}
		else if ((*ast)->key == routenode)
		{
			if (ft_routenode(ast))
				break ;
		}
	}
}
