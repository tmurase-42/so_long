/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 06:11:28 by tmurase           #+#    #+#             */
/*   Updated: 2021/10/05 20:27:30 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAKS_H
# define LEAKS_H

//# define LEAKS 0
# if LEAKS

void	end(void) __attribute__((destructor));

# endif

#endif
