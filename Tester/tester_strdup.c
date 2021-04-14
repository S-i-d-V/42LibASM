/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:21:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 17:17:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strdup_test(int n, int *success, char *str)
{
	char *ftret;
	char *ret;

	display_test_name(n);
	display_type_arg("char *", "str");
	printf(" = '%s';\n", str);
	display_type_return("char *");
	ftret = strdup(str);
	ret = strdup(str);
	printf("ftret = '%s' | ret = '%s'\n", ftret, ret);
	free(ftret);
	free(ret);
	printf("Resultat : ");
	if (strcmp(ftret, ret))
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

int	ft_strdup_tester()
{
	int success;
	char s1[] = "Dans cette string";
	char s2[] = "Je met ca";
	char s3[] = "Avec un backslash n\n";
	char s4[] = "";
	char s5[] = "123456789";
	char s6[] = "6789";
	

	success = 0;
	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRDUP )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();

	ft_strdup_test(1, &success, s1);
	ft_strdup_test(2, &success, s2);
	ft_strdup_test(3, &success, s3);
	ft_strdup_test(4, &success, s4);
	ft_strdup_test(5, &success, s5);
	ft_strdup_test(6, &success, s6);

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