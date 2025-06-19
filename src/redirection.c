/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:32:16 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/04 21:47:22 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	redirect_cmd(t_commands *cmd, char *infile, char *outfile)
{
	int	forkfd;

	forkfd = fork();
	if (forkfd == 0)
	{
		redirect_input(infile);
		redirect_output(outfile);
		execve(cmd->path, cmd->argv, 0);
		perror("command fail");
		exit(1);
		return ;
	}
	wait(NULL);
}
