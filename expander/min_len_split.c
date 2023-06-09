/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_len_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:58:33 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/22 12:59:06 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	min_len_split(char **values)
{
	int	n;

	n = 0;
	while (values[n])
		n++;
	return (n);
}
