/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:35:08 by lwidmer           #+#    #+#             */
/*   Updated: 2023/05/09 14:24:13 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int export_wrapper(t_builtins *builtin, char **args)
{
    return (builtin->commands.min_export(builtin->dict, args + 1));
}

int cd_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_cd(builtin->dict, args + 1));
}

int pwd_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_pwd(args + 1));
}

int env_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_env(builtin->dict, args + 1));
}

int exit_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_exit(args + 1));
}

int echo_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_echo(args + 1));
}

int unset_wrapper(t_builtins *builtin, char **args)
{
	return (builtin->commands.min_unset(&builtin->dict, args + 1));
}
