/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_word_eval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:59 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/05/09 17:09:11 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  ft_asterisk(t_lexer **token, t_expander **word)
{	
	t_expander	*end;
	

	if ((*word)->key == l_empty)
		(*word)->key = l_asterisk;
	else
	{	
		end = min_last_expander(*word);
		if (end->key != l_asterisk)
			end->next = min_init_expander(l_asterisk); 	
		if (!end->next)
			min_free_expander(word);
	}
	*token = (*token)->next;
	return (1);
} 	


static int	ft_count_values(t_expander *word)
{
	int c;

	c = 1;
	while (word)
	{
		if (word->key == l_space)
			c++;
		word = word->next;
	} 
	return (c);		
}


static char **ft_get_values(t_expander **word)
{
	char	**values;
	char	*temp;
	int		count;
	int		n;

	n = 0;
	if (!word)
		return (NULL);
	count = ft_count_values(*word);
	temp = NULL;
	values = ft_calloc(sizeof(char **) , (count +1));
	if (!values)
	{
		return (NULL);
	}
	while (*word)
	{	 
		if ((*word)->key == l_word)
		{
			if (!values[n])
			{	
				values[n] = ft_strdup((*word)->word); 
			}	
			else
			{
				temp = values[n];
				values[n] = ft_strjoin(temp, (*word)->word);
				//min_free(&temp);		
			}
		}
		else
			values[++n] = ft_strdup((*word)->word);
		if (!values[n])
		{
			//min_double_free(&values);
			*word = NULL;			
		}
		else					
			*word = (*word)->next;
	}
	if (values)
		values[n + 1] = NULL;
	return (values);
}


char **min_word_eval(t_lexer **token, t_dict *dict)
{
	char	**values;
	t_expander	*word;
	char	asterisk;
	
	asterisk = 0;
	word = min_init_expander(l_empty);
	while (word && *token && min_token_is_word((*token)->key))
	{
		if (min_token_is_word((*token)->key) == 1)
			min_word(token, &word);
		else if (min_token_is_word((*token)->key) == 2)
			min_dollar(token, &word, dict);
		else if ( min_token_is_word((*token)->key) == 4)
			min_til(token, &word, dict);
		else 
			asterisk = ft_asterisk(token, &word);
	}
	if (word && asterisk)
		values = min_asterisk(word);
	else

		values = ft_get_values(&word);
	min_free_expander(&word);
	
	return (values);
}
