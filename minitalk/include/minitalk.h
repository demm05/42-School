/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:12:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/02 16:59:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "../ft_printf/include/ft_printf.h"

void	server_startup_message(void);
void	message_receiveng_from_client(int pid);
void	message_collision_clients(int pid);
void	message_wrong_server(void);
void	message_succesfuly_sent(void);

#endif
