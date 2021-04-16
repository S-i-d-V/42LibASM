/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:30:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 19:36:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_write_test(int n, int *success, const void *buf, size_t count)
{
	ssize_t ftret;
	ssize_t ret;
	int err;
	int fterr;

	display_test_name(n);
	display_type_arg("int", "fd");
	printf(" = '%d';\n", 1);
	display_type_arg("const void *", "buf");
	printf(" = '%s';\n", (char *)buf);
	display_type_arg("size_t", "count");
	printf(" = '%zd';\n", count);
	display_type_return("ssize_t");
	printf("ft_write :\n");
	ftret = ft_write(1, buf, count);
	printf("errno = %d\n", errno);
	err = errno;
	printf("write :\n");
	ret = write(1, buf, count);
	printf("errno = %d\n", errno);
	fterr = errno;
	printf("ftret = %zd | ret = %zd\n", ftret, ret);
	printf("Resultat : ");
	if (ftret != ret || err != fterr)
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
}

int	ft_write_tester()
{
	int success = 0;
	
	blue();
	printf("            (------)            \n");
	printf("        -<( FT_WRITE )>-        \n");
	printf("            (------)            \n\n");
	reset_color();
	ft_write_test(1, &success, "Je print cette string", 21);
	ft_write_test(2, &success, "Avec un backslash n\n", 20);
	ft_write_test(3, &success, "\n\\n123456789\\n", 14);
	ft_write_test(4, &success, "", 0);
	ft_write_test(5, &success, "\n", 1);
	ft_write_test(6, &success, "\\", 1);
	if (success == 6)
		green();
	else
		red();
	printf("           -<( %d/6 )>-\n\n", success);
	reset_color();
	return ((success == 6) ? 1 : 0);
}
