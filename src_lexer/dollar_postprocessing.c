/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_postprocessing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:42:52 by lwidmer           #+#    #+#             */
/*   Updated: 2023/04/26 14:43:02 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *dollar_postprocessing(t_lexer *tmp)
{
	t_lexer *tmp2;
	char *dollar_value;
	int pos;
	int start;

	pos = 0;
	start = 0;
	dollar_value = tmp->value;
	tmp->value = NULL;
	while (dollar_value[pos] != '\0')
	{
		if (dollar_value[pos] == '$')
		{
			tmp = add_to_token_list(tmp, l_dollar, NULL, 0, 0);
			pos++;
			start++;
			if (dollar_value[pos] == '?')
				pos++;
			else if (dollar_value[pos] == '$')
				continue ;
			else
			{
				while (ft_isalnum(dollar_value[pos]) != 0)
					pos++;
			}
			if (pos > start)
				tmp = add_to_token_list(tmp, l_word, dollar_value, start, pos);
			start = pos;
		}
		else
		{
			while (dollar_value[pos] != '$' && dollar_value[pos] != '\0')
				pos++;
			tmp = add_to_token_list(tmp, l_word, dollar_value, start, pos);
			start = pos;
		}
	}
	free(dollar_value);
	if (tmp->key == l_empty)
			tmp = remove_token_from_list_end(tmp);
	return (tmp);
}
