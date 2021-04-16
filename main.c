/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:46:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 21:07:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester/tester.h"

int		main()
{
	int success;

	success = 0;
	success = success + ft_strlen_tester();
	success = success + ft_strcpy_tester();
	success = success + ft_strcmp_tester();
	success = success + ft_write_tester();
	success = success + ft_read_tester();
	success = success + ft_strdup_tester();

	if (success == 6)
		green();
	else
		red();
	printf("     *********************\n");
	printf("     * NOTE FINALE : %d/6 *\n", success);
	printf("     *********************\n");
	reset_color();
	return (0);
}
