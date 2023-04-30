/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:44:38 by lwidmer           #+#    #+#             */
/*   Updated: 2023/04/21 17:29:49 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

int min_pwd(char **args)
{
	char *pwd;

	(void)args;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		printf("%s\n", pwd);
		return (1000);
	}
	else
    	return (1001);
}
