/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:45:14 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 00:57:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	red()
{
	printf("\033[1;31m");
}

void	green()
{
	printf("\033[1;32m");
}

void	blue()
{
	printf("\033[1;34m");
}

void	reset_color()
{
	printf("\033[0m");
}