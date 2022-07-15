/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:20:02 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/23 10:27:49 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	act;

	ft_printf ("PID : %d\n", getpid ());
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_received_char;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_print_error("signal error\n");
		return (0);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_print_error("signal error\n");
		return (0);
	}
	while (1)
		pause();
	return (0);
}

void	ft_received_char(int signum, siginfo_t *info, void *context)
{
	static int	i = 1;
	static int	j = 0;
	static int	c = 0;
	static char	str[524288] = "a";

	(void)context;
	(void)info;
	if (i < 15)
	{
		if (signum == SIGUSR1)
			c = (c + 1) << 1;
		else if (signum == SIGUSR2)
			c <<= 1;
		i++;
	}
	else
	{
		if (signum == SIGUSR1)
			c += 1;
		str[j++] = c;
		i = 1;
		c = 0;
		if (str[j - 1] == '\0')
			ft_if(&j, str);
	}
}

void	ft_if(int *j, char *str)
{
	ft_putstr_fd(str, 1);
	*j = 0;
}
