/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurase <tmurase@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by oouklich          #+#    #+#             */
/*   Updated: 2021/10/15 11:07:09 by tmurase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACROS_H
# define KEY_MACROS_H

# if defined(__linux__)

#  define X_EVENT_KEY_PRESS 2
#  define X_EVNET_KEY_RELEASE 3
#  define X_EVENT_KEY_EXIT 33
#  define K_ESC 65307
#  define K_AR_L 65361
#  define K_AR_R 65363
#  define K_Z 122
#  define K_Q 113
#  define K_S 115
#  define K_D 100
#  define K_W 119
#  define K_A 97

# else

#  define X_EVENT_KEY_PRESS 2
#  define X_EVNET_KEY_RELEASE 3
#  define X_EVENT_KEY_EXIT 17
#  define K_A 0
#  define K_D 2
#  define K_S 1
#  define K_W 13
#  define K_AR_L 123
#  define K_AR_R 124
#  define K_ESC 53

# endif
#endif
