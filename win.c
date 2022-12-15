/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:44:13 by artvan-d          #+#    #+#             */
/*   Updated: 2022/12/02 09:43:15 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	printf("Congratulations, you found all the Diamonds and the exit.\n");
	printf("You won!\n");
	printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}
