/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:23:56 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/23 10:26:01 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/ashes.h"

/* Server */
void	ft_received_char(int signum, siginfo_t *info, void *context);
void	ft_if(int *j, char *str);
/* client */
void	ft_send_char(int pid, int byte);
void	ft_send_str(int pid, char *str);
int		ft_check(char *stack);
#endif
