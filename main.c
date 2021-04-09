/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:30:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 19:29:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("Mon ft_strlen  : %ld\n", ft_strlen("Cette string fait 27 chars."));
	printf("Le vrai strlen : %ld\n", strlen("Cette string fait 27 chars."));
	return (0);
}