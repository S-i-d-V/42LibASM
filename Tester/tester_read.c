/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:30:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 19:45:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	ft_read_test_full(char *file, int n, int *success, size_t buf_size)
{
	ssize_t ret;
	char buf[buf_size];
	int fd;
	int err;
	ssize_t ftret;
	char ftbuf[buf_size];
	int ftfd;
	int fterr;

	display_test_name(n);
	fd = open(file, O_RDONLY);
	ftfd = open(file, O_RDONLY);
	display_type_arg("size_t", "BUFFER_SIZE");
	printf(" = '%zd';\n", buf_size);
	display_type_return("char *");
	ret = read(fd, buf, buf_size);
	buf[ret] = '\0';
	printf("read : '%s'\n", buf);
	err = errno;
	printf("ret = %ld\nerrno = %d\n", ret, err);
	ftret = ft_read(ftfd, ftbuf, buf_size);
	ftbuf[ftret] = '\0';
	printf("ft_read : '%s'\n", ftbuf);
	fterr = errno;
	printf("ftret = %ld\nerrno = %d\n", ftret, fterr);
	printf("Resultat : ");
	if (ret != ftret || fterr != err)
		test_failure();
	else
		*success = *success + test_success();
	printf("\n\n");
	close(fd);
	close(ftfd);
}

void	ft_read_test(char *file, int n, int *success, size_t buf_size)
{
	ssize_t ret;
	char buf[buf_size];
	int fd;
	int err;
	ssize_t ftret;
	char ftbuf[buf_size];
	int ftfd;
	int fterr;

	blue();
	printf("Test [%02d] : ", n);
	reset_color();
	fd = open(file, O_RDONLY);
	ftfd = open(file, O_RDONLY);
	ret = read(fd, buf, buf_size);
	err = errno;
	ftret = ft_read(ftfd, ftbuf, buf_size);
	fterr = errno;
	if (ret != ftret || fterr != err)
		test_failure();
	else
		*success = *success + test_success();
	close(fd);
	close(ftfd);
}

int	ft_read_tester(int output)
{
	int success = 0;
	ssize_t ret;

	blue();
	printf("           (-------)            \n");
	printf("        -<( FT_READ )>-        \n");
	printf("           (-------)            \n\n");
	reset_color();
	if (output == 1)
	{
		ft_read_test_full("Tester/test.txt", 1, &success, 0);
		ft_read_test_full("Tester/test.txt", 2, &success, 2);
		ft_read_test_full("Tester/test.txt", 3, &success, -10);
		ft_read_test_full("Tester/test.txt", 4, &success, 256);
		ft_read_test_full("Tester/test.txt", 5, &success, 600);
		ft_read_test_full("Tester/test.txt", 6, &success, 255);
		ft_read_test_full("Tester/blank.txt", 7, &success, 0);
		ft_read_test_full("Tester/blank.txt", 8, &success, -10);
		ft_read_test_full("Tester/blank.txt", 9, &success, 2);
		ft_read_test_full("Tester/blank.txt", 10, &success, 4);
		ft_read_test_full("Tester/blank.txt", 11, &success, 60);
		ft_read_test_full("Tester/blank.txt", 12, &success, 255);
	}
	else
	{
		ft_read_test("Tester/test.txt", 1, &success, 0);
		ft_read_test("Tester/test.txt", 2, &success, 2);
		ft_read_test("Tester/test.txt", 3, &success, -10);
		ft_read_test("Tester/test.txt", 4, &success, 256);
		ft_read_test("Tester/test.txt", 5, &success, 600);
		ft_read_test("Tester/test.txt", 6, &success, 255);
		ft_read_test("Tester/blank.txt", 7, &success, 0);
		ft_read_test("Tester/blank.txt", 8, &success, -10);
		ft_read_test("Tester/blank.txt", 9, &success, 2);
		ft_read_test("Tester/blank.txt", 10, &success, 4);
		ft_read_test("Tester/blank.txt", 11, &success, 60);
		ft_read_test("Tester/blank.txt", 12, &success, 255);
	}
	if (success == 12)
		green();
	else
		red();
	printf("           -<( %d/12 )>-\n\n", success);
	reset_color();
	return ((success == 12) ? 1 : 0);
}
