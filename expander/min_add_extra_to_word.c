/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_add_extra_to_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:31:40 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/23 10:52:13 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	min_add_extra_to_word(t_expander **word, t_expander *extra)
{
	if (!extra)
		return ;
	while (extra && extra->key != l_empty)
	{
		if (min_addlast_expander(word, extra->word, NULL, 0))
			break ;
		extra = extra->next;
	}
}
