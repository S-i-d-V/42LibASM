/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:30:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 19:36:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strlen_test_full(int n, int *success, char *s)
{
	ssize_t ftret;
	ssize_t ret;

	display_test_name(n);
	display_type_arg("char *", "s");
	printf(" = '%s';\n", s);
	display_type_return("ssize_t");
	ftret = ft_strlen(s);
	ret = strlen(s);
	printf("ftret = %zd\nret = %zd\n", ftret, ret);
	printf("Resultat : ");
	if (ftret != ret)
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

void	ft_strlen_test(int n, int *success, char *s)
{
	ssize_t ftret;
	ssize_t ret;

	blue();
	printf("Test [%02d] : ", n);
	reset_color();
	ftret = ft_strlen(s);
	ret = strlen(s);
	if (ftret != ret)
		test_failure();
	else
		*success = *success + test_success();
}

int	ft_strlen_tester(int output)
{
	int success = 0;

	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRLEN )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();
	if (output == 1)
	{
		ft_strlen_test_full(1, &success, "Test strlen");
		ft_strlen_test_full(2, &success, "Avec un backslash n\n");
		ft_strlen_test_full(3, &success, "\n\\n123456789\\n");
		ft_strlen_test_full(4, &success, "");
		ft_strlen_test_full(5, &success, " ");
		ft_strlen_test_full(6, &success, "\n");
	}
	else
	{
		ft_strlen_test(1, &success, "Test strlen");
		ft_strlen_test(2, &success, "Avec un backslash n\n");
		ft_strlen_test(3, &success, "\n\\n123456789\\n");
		ft_strlen_test(4, &success, "");
		ft_strlen_test(5, &success, " ");
		ft_strlen_test(6, &success, "\n");
	}
	if (success == 6)
		green();
	else
		red();
	printf("           -<( %d/6 )>-\n\n", success);
	reset_color();
	return ((success == 6) ? 1 : 0);
}
