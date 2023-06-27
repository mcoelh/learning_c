/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matanton <matanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:28:49 by mcoelho-          #+#    #+#             */
/*   Updated: 2023/05/23 21:13:44 by matanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <errno.h>
# include <string.h>

extern int	g_ret;

typedef struct s_input
{
	char				*input;
	char				**token;
	struct s_commands	*commands;
	char				**envp;
	char				*exp_value;
	t_node				*l_envp;
	char				quote;
}	t_input;

typedef struct s_commands
{
	char				**command;
	int					fd_in;
	int					fd_out;
	struct s_commands	*next;
}	t_commands;

typedef struct s_pid
{
	int				pd;
	struct s_pid	*next;
}	t_pid;

/*INIT & CHECKS*/
void	init_shell(t_input *ipt);
int		is_command(t_commands *cmmd);
int		is_operator(char *str);
void	call_commands(t_input *ipt, t_commands *cmmd);
char	**split_words_quotes(char *str, int i, int j, int k);
/*EXIT*/
int		ft_exit(t_input *ipt, t_commands *cmmd, int ret);
/*PID*/
void	free_pid(t_pid **pid);
/*FREE*/
void	free_list(t_commands **cmmd);
void	split_clean(char ***split);
/*PWD*/
void	ft_pwd(char **envp);
/*CD*/
void	ft_cd(t_input *ipt, t_commands *cmmd);
/*ENVP*/
char	**get_envp(char **envp, t_input *ipt);
void	print_envp(t_input *ipt);
/*ECHO*/
void	ft_echo(t_commands *cmmd);
/*EXPORT*/
void	call_export(t_input *ipt, t_commands *cmmd);
int		check_export(char *str);
/* UNSET*/
void	call_unset(t_input *ipt, t_commands *cmmd);
/*EXPANSÃO DE VARIÁVEIS*/
int		find_quotes(char *str, t_input *ipt);
char	*del_quote(char *str, char c, char *ret);
int		check_quotes(char *str, int *i, char *quote);
void	expand(t_input *ipt, int i);
int		ft_is_quote42(char *str);
int		count_words_quotes(char *str, int i);
char	*take_quotes(char *input, char *quote);
int		check_unique_quote(char *str, int i, char *quote);
int		count_size(char *str, char *quote);
int		check_var_expand(char *str, t_input *ipt, int *i);
/*EXECVE*/
int		ft_cmmd(t_input *ipt, t_commands *cmmd);
char	*getpath(char **envp, char *cmd, char *path, char **paths);
void	call_builtin(t_input *ipt);
void	msh_pidadd_back(t_pid **list, t_pid *node);
t_pid	*msh_pidnew(int pid);
/*PIPE*/
void	ft_pipeorg(t_input *ipt);
void	ft_lastpipeaux(t_pid *aux);
/*PARSE*/
void	ft_parse(t_input *ipt, int i);
void	cmdadd_back(t_commands **lst, t_commands *node);
void	parse_aux(t_input *ipt, int *i);
/*LEXER*/
int		ft_printerror(int a, char c, char *junk);
int		check_closedop(char *str);
int		check_pipe(char *line);
int		check_redirect(char *line, int i, char opt);
int		jump_quote(char *line);
int		check_lexer(char *arg);
#endif
