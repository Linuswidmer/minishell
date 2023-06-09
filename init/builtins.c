/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:43:58 by lwidmer           #+#    #+#             */
/*   Updated: 2023/06/23 15:18:44 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_builtins_1(t_builtins *builtins, t_dict *dict,
		t_commands *commands)
{
	builtins[0].name = ft_strdup("export");
	builtins[0].func = &export_wrapper;
	builtins[0].dict = dict;
	builtins[0].commands = *commands;
	builtins[1].name = ft_strdup("cd");
	builtins[1].func = &cd_wrapper;
	builtins[1].dict = dict;
	builtins[1].commands = *commands;
	builtins[2].name = ft_strdup("pwd");
	builtins[2].func = &pwd_wrapper;
	builtins[2].dict = dict;
	builtins[2].commands = *commands;
	builtins[3].name = ft_strdup("env");
	builtins[3].func = &env_wrapper;
	builtins[3].dict = dict;
	builtins[3].commands = *commands;
}

void	create_builtins_2(t_builtins *builtins, t_dict *dict,
		t_commands *commands)
{
	builtins[4].name = ft_strdup("exit");
	builtins[4].func = &exit_wrapper;
	builtins[4].dict = dict;
	builtins[4].commands = *commands;
	builtins[5].name = ft_strdup("echo");
	builtins[5].func = &echo_wrapper;
	builtins[5].dict = dict;
	builtins[5].commands = *commands;
	builtins[6].name = ft_strdup("unset");
	builtins[6].func = &unset_wrapper;
	builtins[6].dict = dict;
	builtins[6].commands = *commands;
}

t_builtins	*create_builtins(t_dict *dict, t_commands *commands)
{
	t_builtins	*builtins;
	int			num_builtins;

	num_builtins = 32;
	builtins = malloc(sizeof(t_builtins) * num_builtins);
	create_builtins_1(builtins, dict, commands);
	create_builtins_2(builtins, dict, commands);
	return (builtins);
}

void	create_builtin_commands(t_min *min)
{
	min->commands.min_export = &min_export;
	min->commands.min_cd = &min_cd;
	min->commands.min_pwd = &min_pwd;
	min->commands.min_env = &min_env;
	min->commands.min_echo = &min_echo;
	min->commands.min_exit = &min_exit;
	min->commands.min_unset = &min_unset;
	min->commands.min_env = &min_env;
}
