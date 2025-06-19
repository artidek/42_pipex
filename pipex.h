/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:38:06 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/05 11:27:42 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/libftprintf.h"
# include "get_next_line/get_next_line_bonus.h"
# include <sys/wait.h>

# ifndef PTH
#  define PTH "empty"
# endif

typedef struct s_commands
{
	char				*path;
	char				**argv;
	struct s_commands	*next;
}						t_commands;

typedef struct s_arguments
{
	char				*argument;
	struct s_arguments	*next;
}						t_arguments;

int						check_exist(char *path);
int						init_cmd(t_commands **cmd, char **argv, int argc);
int						arr_size(char **arr);
char					**copy_arr(char **arr);
char					**split_arguments(char *arguments);
void					free_arr(char **arr);
void					del(char *path, char **argv);
void					del_a(char *argument);
void					add_node(t_commands **lst, t_commands *new);
void					clear_list(t_commands **lst, void (*del)(char *,
								char **));
void					delete_node(t_commands *lst, void (*del)(char *,
								char **));
void					redirect_cmd(t_commands *cmd, char *infile,
							char *outfile);
void					start_piping(t_commands *cmd, char **argv, int argc);
void					redirect_input(char *file);
void					redirect_output(char *file);
void					add_node_a(t_arguments **lst, t_arguments *new);
void					clear_list_a(t_arguments **lst, void (*del_a)(char *));
void					delete_node_a(t_arguments *lst, void (*del)(char *));
t_commands				*create_node(char *path, char **argv);
t_arguments				*create_node_a(char *argument);
void					ext_qt(char **arg, char **res, int *i);
void					update_list(t_arguments **args, char *arg);
void					redirect_two(char **argv);
void					read_stdin(char **argv);
char					**create_argv(t_arguments **args);
#endif
