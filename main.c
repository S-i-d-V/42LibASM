/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:46:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 14:15:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester/tester.h"

int		main(int ac, char **av)
{
	int success;
	int output;

	success = 0;
	output = 0;
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 't' && av[1][2] == 'e' && av[1][3] == 's' && av[1][4] == 't' && strlen(av[1]) == 5)
		output = 1;
	if (ac == 1 || (ac == 2 && output == 1))
	{
		printf("\n");
		red();
		printf("##      ##  ####            ####    #####  ##    ##         \n");
		printf("##          ##  #          ##  ##  ##      ###  ###         \n");
		printf("##      ##  ####           ######  ######  ## ## ##         \n");
		printf("######  ##  ##  #          ##  ##      ##  ##    ##         \n");
		printf("######  ##  ####   ######  ##  ##  #####   ##    ##  Tester.\n");
		reset_color();
		printf("\n");

		success = success + ft_strlen_tester(output);
		success = success + ft_strcpy_tester(output);
		success = success + ft_strcmp_tester(output);
		success = success + ft_write_tester(output);
		success = success + ft_read_tester(output);
		success = success + ft_strdup_tester(output);
		if (success == 6)
			green();
		else
			red();
		printf("     *********************\n");
		printf("     * NOTE FINALE : %d/6 *\n", success);
		printf("     *********************\n");
		reset_color();
	}
	if (ac != 1 && ac != 2 || (ac == 2 && output == 0))
	{
		red();
		printf("[ERROR] arguments invalides. (./Libasm_tester [optional]-test)\n");
		reset_color();
		return(0);
	}
	return (0);
}
