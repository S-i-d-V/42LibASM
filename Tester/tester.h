/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:38:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 21:10:53 by user42           ###   ########.fr       */
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

int		ft_strlen_tester(int output);
void	ft_strlen_test_full(int n, int *success, char *s);
void	ft_strlen_test(int n, int *success, char *s);

int		ft_strcpy_tester(int output);
void	ft_strcpy_test_full(int n, int *success, const char *dest, const char *src);
void	ft_strcpy_test(int n, int *success, const char *dest, const char *src);

int		ft_strcmp_tester(int output);
void	ft_strcmp_test_full(int n, int *success, char *s1, char *s2);
void	ft_strcmp_test(int n, int *success, char *s1, char *s2);

int		ft_write_tester(int output);
void	ft_write_test_full(int n, int *success, const void *buf, size_t count);
void	ft_write_test(int n, int *success, const void *buf, size_t count);

int		ft_read_tester(int output);
void	ft_read_test_full(char *file, int n, int *success, size_t buf_size);
void	ft_read_test(char *file, int n, int *success, size_t buf_size);

int		ft_strdup_tester(int output);
void	ft_strdup_test_full(int n, int *success, char *str);
void	ft_strdup_test(int n, int *success, char *str);

void	test_read();

#endif
