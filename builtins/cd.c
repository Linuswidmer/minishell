/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwidmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:55:25 by lwidmer           #+#    #+#             */
/*   Updated: 2023/04/12 17:04:19 by lwidmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"

static int update_directories_in_dict(char *pwd, t_dict *dict_pwd, t_dict *dict_oldpwd)
{
  if (dict_oldpwd && dict_pwd)
  {
    free(dict_oldpwd->value);
    dict_oldpwd->value = dict_pwd->value;
  }
  if (dict_pwd)
    write_to_env_variable(dict_pwd, "PWD", pwd);

  return (0);
}

static int cd_to_oldpwd(t_dict *dict_oldpwd)
{
  int status;

  if (dict_oldpwd)
  {
    status = chdir(dict_oldpwd->value);  
  }
  else
  {
    printf("cd: OLDPWD not set\n");
    return (1);
  }
	if (status == -1)
  {
    printf("cd: %s: No such file or directory\n", dict_oldpwd->value);
		return (1);
  }
  else
    return (0);
}

static int cd_to_home(t_dict *dict_home)
{
  int status;

  if (dict_home)
    status = chdir(dict_home->value);  
  else
  {
    printf("cd: HOME not set\n");
    return (1);
  }
	if (status == -1)
  {
    printf("cd: %s: No such file or directory\n", dict_home->value);
		return (1);
  }
  else
    return (0);
}

int cd(char *arg, t_dict *dict)
{
    int status;
    char *pwd;
  t_dict *dict_home;
	t_dict *dict_pwd;
	t_dict *dict_oldpwd;

  dict_pwd = search_key_in_dict(dict, "PWD");
  dict_oldpwd = search_key_in_dict(dict, "OLDPWD");
  dict_home = search_key_in_dict(dict, "HOME");

  if (ft_strncmp(arg, "-", ft_strlen(arg)) == 0)
    status = cd_to_oldpwd(dict_oldpwd);
  else if (arg == NULL || ft_strncmp(arg, "~", ft_strlen(arg)) == 0)
    status = cd_to_home(dict_home);
  else
  {
    status = chdir(arg);
	  if (status == -1)
    {
      printf("%s: No such file or directory\n", arg);
		  return (1);
    }
  }
  pwd = getcwd(NULL, 0);
  printf("%s\n", pwd);
  update_directories_in_dict(pwd, dict_pwd, dict_oldpwd);
  free(pwd);
  return (0);
}