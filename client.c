/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:19:52 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/23 10:27:28 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_print_error("To few arguments were given");
		return (0);
	}
	argv++;
	if (ft_check(argv[0]) == 1)
		return (0);
	ft_send_str(ft_atoi(argv[0]), argv[1]);
	return (0);
}

void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_char(pid, str[i]);
		i++;
	}
	ft_send_char(pid, str[i]);
}

void	ft_send_char(int pid, int byte)
{
	int	scan;

	scan = 1 << 14;
	while (scan != 0)
	{
		if (byte & scan)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_print_error("Bad Pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_print_error("Bad Pid\n");
		}
		scan >>= 1;
		usleep(50);
	}
}

int	ft_check(char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if ((ft_isdigit(stack[i]) == 0))
		{
			ft_print_error("Fisrt argument given weren't unsigned int");
			return (1);
		}
		i++;
	}
	if (ft_atoi(stack) < 2)
	{
		ft_print_error("Pid is under or equal to 1");
		return (1);
	}	
	return (0);
}
