/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:21:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 19:35:03 by user42           ###   ########.fr       */
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
	ret = strdup(str);
	printf("strdup : '%s'\n", ret);
	ftret = ft_strdup(str);
	printf("ft_strdup : '%s'\n", ftret);
	printf("Resultat : ");
	if (strcmp(ftret, ret))
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
	free(ftret);
	free(ret);
}

int	ft_strdup_tester()
{
	int success = 0;
	char s1[] = "Je duplique cette string";
	char s2[] = "Avec un backslash n\n";
	char s3[] = "\n";
	char s4[] = "";
	char s5[] = "\\";
	
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
	if (success == 5)
		green();
	else
		red();
	printf("           -<( %d/5 )>-\n\n", success);
	reset_color();
	blue();
	printf("       (-----------------)       \n\n");
	reset_color();
	return ((success == 5) ? 1 : 0);
}