/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_strcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:21:58 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 19:43:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_strcpy_test_full(int n, int *success, const char *dest, const char *src)
{
	display_test_name(n);
	display_type_arg("char *", "dest");
	printf(" = '%s';\n", dest);
	display_type_arg("char *", "src");
	printf(" = '%s';\n", src);
	display_type_return("char *");
	printf("ftret = '%s' | ret = '%s'\n", ft_strcpy((char *)dest, src), strcpy((char *)dest, src));
	printf("Resultat : ");
	if (strcmp(ft_strcpy((char *)dest, src), strcpy((char *)dest, src)))
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

void	ft_strcpy_test(int n, int *success, const char *dest, const char *src)
{
	blue();
	printf("Test [%02d] : ", n);
	reset_color();
	if (strcmp(ft_strcpy((char *)dest, src), strcpy((char *)dest, src)))
		test_failure();
	else
		*success = *success + test_success();
}

int	ft_strcpy_tester(int output)
{
	int success = 0;
	char s1[] = "Petite string";
	char s2[] = "String de moyenne taille";
	char s3[] = "String d'une longueur plus grande";
	char s4[] = "";
	char s5[] = "\n";
	char s6[] = "String test";
	char s7[] = "String test\n";
	
	blue();
	printf("            (-------)            \n");
	printf("        -<( FT_STRCPY )>-        \n");
	printf("            (-------)            \n\n");
	reset_color();
	if (output == 1)
	{
		ft_strcpy_test_full(1, &success, s1, s2);
		ft_strcpy_test_full(2, &success, s2, s1);
		ft_strcpy_test_full(3, &success, s2, s3);
		ft_strcpy_test_full(4, &success, s3, s2);
		ft_strcpy_test_full(5, &success, s3, s4);
		ft_strcpy_test_full(6, &success, s4, s5);
		ft_strcpy_test_full(7, &success, s5, s4);
		ft_strcpy_test_full(8, &success, s6, s7);
		ft_strcpy_test_full(9, &success, s7, s6);
	}
	else
	{
		ft_strcpy_test(1, &success, s1, s2);
		ft_strcpy_test(2, &success, s2, s1);
		ft_strcpy_test(3, &success, s2, s3);
		ft_strcpy_test(4, &success, s3, s2);
		ft_strcpy_test(5, &success, s3, s4);
		ft_strcpy_test(6, &success, s4, s5);
		ft_strcpy_test(7, &success, s5, s4);
		ft_strcpy_test(8, &success, s6, s7);
		ft_strcpy_test(9, &success, s7, s6);
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