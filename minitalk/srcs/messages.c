/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:59:14 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/02 16:59:14 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	server_startup_message(void)
{
	ft_printf(
		" _______ _       _             _  "
		"_         ______                               \n"
		"(_______|_)     (_)  _        | |"
		"| |       / _____)                              \n"
		" _  _  _ _ ____  _ _| |_ _____| || "
		"|  _   ( (____  _____  ____ _   _ _____  ____ \n"
		"| ||_|| | |  _ \\| (_   _|____ | |"
		"| |_/ )   \\____ \\| ___ |/ ___) | | | ___ |/ ___)\n"
		"| |   | | | | | | | | |_/ ___ | |"
		"|  _ (    _____) ) ____| |    \\ V /| ____| |    \n"
		"|_|   |_|_|_| |_|_|  \\__)_____|\\_"
		")_| \\_)  (______/|_____)_|     \\_/ |_____)_|    \n\n"
		);
}

void	message_receiveng_from_client(int pid)
{
	ft_printf("\nReceiving message from client with pid: %d\n\n", pid);
}

void	message_collision_clients(int pid)
{
	ft_printf("\nError: Message was interupted by another "
		"client: %d\nTerminating the server\n", pid);
}

void	message_wrong_server(void)
{
	ft_printf("Couldn't connect to the server, "
		"please check pid of the server\n");
}

void	message_succesfuly_sent(void)
{
	ft_printf("Message was succefully sent\n");
}
