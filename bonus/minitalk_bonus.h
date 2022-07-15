/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:49:08 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/25 16:49:09 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./../libft/ashes.h"

/* server_bonus */
void	ft_received_char(int signum, siginfo_t *info, void *context);
void	ft_if(siginfo_t *info, int *j, char *str);
/* client_bonus */
void	ft_send_char(int pid, int byte);
void	ft_send_str(int pid, char *str);
void	ft_received(int sig);
int		ft_check(char *stack);
#endif
