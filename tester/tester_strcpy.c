/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:21:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 02:48:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strcpy_test(int n, int *success, const char *dest, const char *src)
{
	display_test_name(n);
	display_type_arg("char *", "dest");
	printf(" = '%s';\n", dest);
	display_type_arg("char *", "src");
	printf(" = '%s';\n", src);
	display_type_return("char *");
	printf("ftret = %s | ret = %s\n", "", "");
	printf("Resultat : ");
	if (strcmp("", ""))
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

int	ft_strcpy_tester()
{
	int success;
	char s1[] = "Dans cette string";
	char s2[] = "Je met ca";
	char s3[] = "Avec un backslash n\n";
	char s4[] = "Pas assez";
	char s5[] = "123456789";
	char s6[] = "6789";
	char s7[] = "";
	

	success = 0;
	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRCPY )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();

	ft_strcpy_test(1, &success, s1, s2);
	ft_strcpy_test(2, &success, s3,s2);
	ft_strcpy_test(3, &success, s4, s2);
	ft_strcpy_test(4, &success, s1, s7);
	ft_strcpy_test(5, &success, s5, s6);
	ft_strcpy_test(6, &success, s7, s7);

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