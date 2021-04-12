/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:38:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 02:49:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TESTER_H
#define _TESTER_H

#include "../libasm.h"

void	red();
void	green();
void	blue();
void	reset_color();

int		test_success();
void	test_failure();
void	display_test_name(int count);
void	display_type_arg(char *type, char *name);
void	display_type_return(char *type);

int	ft_strlen_tester();
void	ft_strlen_test(int n, int *success, char *s);

int	ft_strcpy_tester();
void	ft_strcpy_test(int n, int *success, const char *dest, const char *src);

int	ft_strcmp_tester();
void	ft_strcmp_test(int n, int *success, char *s1, char *s2);

#endif
