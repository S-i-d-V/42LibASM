/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:22:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 19:44:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strcmp_test_full(int n, int *success, char *s1, char *s2)
{
	int ftret;
	int ret;

	display_test_name(n);
	display_type_arg("char *", "s1");
	printf(" = '%s';\n", s1);
	display_type_arg("char *", "s2");
	printf(" = '%s';\n", s2);
	display_type_return("int");
	ftret = ft_strcmp(s1, s2);
	ret = strcmp(s1, s2);
	printf("ftret = %d | ret = %d\n", ftret, ret);
	printf("Resultat : ");
	if (ftret != ret)
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

void	ft_strcmp_test(int n, int *success, char *s1, char *s2)
{
	int ftret;
	int ret;

	blue();
	printf("Test [%02d] : ", n);
	reset_color();
	ftret = ft_strcmp(s1, s2);
	ret = strcmp(s1, s2);
	if (ftret != ret)
		test_failure();
	else
		*success = *success + test_success();
}

int	ft_strcmp_tester(int output)
{
	int success = 0;

	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRCMP )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();
	if (output == 1)
	{
		ft_strcmp_test_full(1, &success, "Ces strings sont les memes.", "Ces strings sont les memes.");
		ft_strcmp_test_full(2, &success, "Ces strings sont les memes.", "Ces strings ne sont pas les memes.");
		ft_strcmp_test_full(3, &success, "", "Je compare cette string a rien.");
		ft_strcmp_test_full(4, &success, "Je compare cette string a rien.", "");
		ft_strcmp_test_full(5, &success, "", "");
		ft_strcmp_test_full(6, &success, "Backslash n\n", "Backslash n");
		ft_strcmp_test_full(7, &success, "Backslash n", "Backslash \n");
		ft_strcmp_test_full(8, &success, "\\", "");
		ft_strcmp_test_full(9, &success, "", "\\");
	}
	else
	{
		ft_strcmp_test(1, &success, "Ces strings sont les memes.", "Ces strings sont les memes.");
		ft_strcmp_test(2, &success, "Ces strings sont les memes.", "Ces strings ne sont pas les memes.");
		ft_strcmp_test(3, &success, "", "Je compare cette string a rien.");
		ft_strcmp_test(4, &success, "Je compare cette string a rien.", "");
		ft_strcmp_test(5, &success, "", "");
		ft_strcmp_test(6, &success, "Backslash n\n", "Backslash n");
		ft_strcmp_test(7, &success, "Backslash n", "Backslash \n");
		ft_strcmp_test(8, &success, "\\", "");
		ft_strcmp_test(9, &success, "", "\\");
	}
	if (success == 9)
		green();
	else
		red();
	printf("           -<( %d/9 )>-\n\n", success);
	reset_color();
	blue();
	printf("       (-----------------)       \n\n");
	reset_color();
	return ((success == 9) ? 1 : 0);
}