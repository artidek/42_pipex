/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:12 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/05 11:08:33 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	redirect_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (dup2(fd, 0) == -1)
	{
		perror("Failed to redirect input");
		exit(1);
	}
	close(fd);
}

void	redirect_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(fd, 1) == -1)
	{
		perror("Failed to redirect output");
		exit(1);
	}
	close(fd);
}

void	redirect_two(char **argv)
{
	int	infd;

	infd = open(argv[1], O_RDONLY);
	if (infd < 0 || dup2(infd, STDIN_FILENO) == -1)
	{
		perror("Failed to run command");
		exit(1);
	}
	close(infd);
	read_stdin(argv);
}

void	read_stdin(char **argv)
{
	char	*line;
	int		outfd;

	outfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd < 0)
	{
		perror("Failed to run command");
		exit(1);
	}
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		write(outfd, line, (int)ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	close(outfd);
	close(STDIN_FILENO);
}
