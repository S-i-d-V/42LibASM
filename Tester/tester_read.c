/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:30:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 16:59:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_read_test(int n, int *success, size_t count)
{
	ssize_t ftret;
	ssize_t ret;
	char buf[256];
	char ftbuf[256];
	int fd;
	int ftfd;

	fd = open("txt", O_RDONLY);
	ftfd = open("txt", O_RDONLY);
	display_test_name(n);
	display_type_arg("size_t", "count");
	printf(" = '%zd';\n", count);
	display_type_return("ssize_t");

	printf("ftret = %zd | ret = %zd\n", ftret, ret);

	ret = read(fd, buf, count);
	buf[ret] = '\0';
	printf("read : %s\n", buf);
	printf("errno = %d\n", errno);

	ftret = read(ftfd, ftbuf, count);
	ftbuf[ftret] = '\0';
	printf("ft_read : %s\n", ftbuf);
	printf("errno = %d\n", errno);

	printf("Resultat : ");
	if (ftret != ret)
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
	close(fd);
	close(ftfd);
}

int	ft_read_tester()
{
	int success;
	ssize_t ret;

	success = 0;
	blue();
	printf("           (-------)            \n");
	printf("        -<( FT_READ )>-        \n");
	printf("           (-------)            \n\n");
	reset_color();

	ft_read_test(1, &success, 0);
	ft_read_test(2, &success, 2);
	ft_read_test(3, &success, -10);
	ft_read_test(4, &success, 256);
	ft_read_test(5, &success, 600);
	ft_read_test(6, &success, 255);

	if (success == 6)
		green();
	else
		red();
	printf("           -<( %d/6 )>-\n\n", success);
	reset_color();
	return ((success == 6) ? 1 : 0);
}
