/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:03 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/02 14:14:06 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BIS_H
# define LIBFT_BIS_H

long long	ft_atoll(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_strcpy(char *dst, const char *src);
int			ft_find_min(int *tab, int len);
int			ft_find_max(int *tab, int len);
int			ft_find_med(int *tab, int len);
int			ft_next_int(int *tab, int len, int current_int);
int			ft_prev_int(int *tab, int len, int current_int);

#endif
