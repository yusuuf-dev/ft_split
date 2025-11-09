/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-you <yoel-you@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:52:37 by yoel-you          #+#    #+#             */
/*   Updated: 2025/11/09 12:17:02 by yoel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *ft_strdup(const char *s)
{
    char  *new;
    size_t i = 0;

    if (!s)
        return (NULL);
    while (s[i])
        i++;
    new = (char *)malloc((i + 1) * sizeof(char));
    if (!new)
        return (NULL);
    i = 0;
    while (s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}
