/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-you <yoel-you@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:52:46 by yoel-you          #+#    #+#             */
/*   Updated: 2025/11/09 12:16:42 by yoel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


char **ft_split(char const *s, char c);
size_t ft_strlen(const char *s);
char   *ft_strdup(const char *s);

#endif