/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:13:58 by lwidmer           #+#    #+#             */
/*   Updated: 2023/05/05 18:06:15 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
t_lexertype check_single_tokens(char c)
{
	t_lexertype tokens[] = { l_quote, l_dquote, l_asterisk, l_paraopen, l_paraclose, l_in, l_out,
	l_semi, l_pipe, l_escape, l_amp, l_space};
    	int num_tokens = sizeof(tokens) / sizeof(tokens[0]);
    	
    	for (int i = 0; i < num_tokens; i++) {
        if ((char)tokens[i] == c) {
            return tokens[i];
        }
    }
}
*/

t_lexertype check_single_tokens(char c)
{
	if (c == 39)
		return (l_quote);
	else if (c == '"')
		return (l_dquote);
	else if (c == '*')
		return (l_asterisk);
	else if (c == '(')
		return (l_paraclose);
	else if (c == '<')
		return (l_in);
	else if (c == '>')
		return (l_out);
	else if (c == ';')
		return (l_semi);
	else if (c == '|')
		return (l_pipe);
	else if (ft_isspace(c) == 1)
		return (l_space);
	else if (c == '~')
		return (l_til);
	else	
		return (l_word);
}

t_lexertype check_token_with_prev(char c, char prev)
{
	if (c == '(' && prev != '$')
		return (l_paraopen);
}

t_lexertype check_double_tokens(char c, char next)
{
	if (c == '<' && next == '<')
		return (l_heredoc);
	else if (c == '>' && next == '>')
		return (l_append);
	else if (c == '&' && next == '&')
		return (l_and);
	else if (c == '|' && next == '|')
		return (l_or);
	else if (c ==  '$')
		return (l_dollar);
	else
		return (l_empty);
}

t_lexertype check_token(char c, char next)
{
	t_lexertype token_key;

	token_key = check_double_tokens(c, next);
	if (token_key == l_empty)
		token_key = check_single_tokens(c);
	return (token_key);
}
