/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:31:44 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/05 11:09:03 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "pipex.h"

static void	error_message(void)
{
	ft_printf("Failed to run command");
}

int	main(int argc, char **argv)
{
	t_commands	*cmd;
	int			num_cmd;

	cmd = NULL;
	if (check_exist(argv[1]) && argc - 3 >= 1)
	{
		num_cmd = init_cmd(&cmd, argv, argc);
		if (num_cmd == 1)
			redirect_cmd(cmd, argv[1], argv[argc - 1]);
		else if (num_cmd > 1)
			start_piping(cmd, argv, argc);
		else
			error_message();
	}
	else if (check_exist(argv[1]) && argc - 3 == 0)
		redirect_two(argv);
	else
	{
		ft_printf("some arguments are invalid\n");
		return (2);
	}
	clear_list(&cmd, del);
	return (0);
}
