/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:44:41 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/04 21:46:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	redirect_out(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Failed to redirect output");
		exit(1);
	}
	close(fd);
}

static void	redirect_in(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || dup2(fd, STDIN_FILENO) == -1)
	{
		perror("Failed to redirect input");
		exit(1);
	}
	close(fd);
}

static void	exec_command(t_commands *cmd, int prev_pipe, int *pidfd)
{
	if (fork() == 0)
	{
		if (prev_pipe != STDIN_FILENO)
		{
			dup2(prev_pipe, STDIN_FILENO);
			close(prev_pipe);
		}
		if (cmd->next)
			dup2(pidfd[1], STDOUT_FILENO);
		close(pidfd[1]);
		close(pidfd[0]);
		execve(cmd->path, cmd->argv, NULL);
		perror("execve failed");
		exit(1);
	}
}

static void	start_proc(t_commands *cmd)
{
	int	pidfd[2];
	int	prev_pipe;

	prev_pipe = STDIN_FILENO;
	while (cmd)
	{
		if (cmd->next && pipe(pidfd) == -1)
		{
			perror("pipe failed");
			exit(1);
		}
		exec_command(cmd, prev_pipe, pidfd);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		close(pidfd[1]);
		prev_pipe = pidfd[0];
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
}

void	start_piping(t_commands *cmd, char **argv, int argc)
{
	redirect_in(argv[1]);
	redirect_out(argv[argc - 1]);
	start_proc(cmd);
}
