/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:22:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 18:49:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strcmp_test(int n, int *success, char *s1, char *s2)
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

int	ft_strcmp_tester()
{
	int success;

	success = 0;
	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRCMP )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();

	ft_strcmp_test(1, &success, "Ces strings sont les memes.", "Ces strings sont les memes.");
	ft_strcmp_test(2, &success, "Ces strings sont les memes.", "Ces strings ne sont pas les memes.");
	ft_strcmp_test(3, &success, "", "Je compare cette string a rien.");
	ft_strcmp_test(4, &success, "Je compare cette string a rien.", "");
	ft_strcmp_test(5, &success, "Backslash n\n", "Backslash n");
	ft_strcmp_test(6, &success, "", "");

	if (success == 6)
		green();
	else
		red();
	printf("           -<( %d/6 )>-\n\n", success);
	reset_color();

	blue();
	printf("       (-----------------)       \n\n");
	reset_color();
	return ((success == 6) ? 1 : 0);
}