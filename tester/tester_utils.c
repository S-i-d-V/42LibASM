/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:36:41 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 00:57:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int		test_success()
{
	printf("[");
	green();
	printf("SUCCESS");
	reset_color();
	printf("]\n");
	return (1);
}

void	test_failure()
{
	printf("[");
	red();
	printf("FAILURE");
	reset_color();
	printf("]\n");
}

void	display_test_name(int count)
{
	blue();
	printf("* --<( Test[%d] )>--\n", count);
	reset_color();
}

void	display_type_arg(char *type, char *name)
{
	blue();
	printf("%s", type);
	reset_color();
	printf(" %s", name);
}

void	display_type_return(char *type)
{
	blue();
	printf("return (");
	reset_color();
	printf("%s", type);
	blue();
	printf(")");
	reset_color();
	printf(";\n");
}