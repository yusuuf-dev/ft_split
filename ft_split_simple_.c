/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_simple_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-you <yoel-you@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:27:43 by yoel-you          #+#    #+#             */
/*   Updated: 2025/11/09 12:31:19 by yoel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    this is simple version just to let you got the idea 
    and without protect the malloc
*/

#include "header.h"

static char *charjoin(char *tmp, char c)
{
    char *str;
    size_t i = 0;
    size_t len = ft_strlen(tmp);

    str = (char *)malloc((len + 2) * sizeof(char));
    while (tmp && tmp[i])
    {
        str[i] = tmp[i];
        i++;
    }
    str[i++] = c;
    str[i] = '\0';
    free(tmp);
    return (str);
}

static char **ptrjoin(char **tmp, char **ptrs)
{
    char **new;
    size_t i = 0;

    while (ptrs && ptrs[i])
        i++;
    new = (char **)malloc((i + 2) * sizeof(char *));
    i = 0;
    while (ptrs && ptrs[i])
    {
        new[i] = ptrs[i];
        i++;
    }
    new[i] = ft_strdup(*tmp);
    new[++i] = NULL;
    free(*tmp);
    *tmp = NULL;
    free(ptrs);
    return (new);
}

char **ft_split(char const *s, char c)
{
    char *tmp = NULL;
    char **ptrs = NULL;
    size_t i = 0;
    int flag = 1;

    while (s && s[i])
    {
        if (s[i] != c)
            tmp = charjoin(tmp, s[i]);
        else if (s[i] == c && tmp)
            ptrs = ptrjoin(&tmp, ptrs);
        i++;
    }
    if (tmp)
        ptrs = ptrjoin(&tmp, ptrs);
    return (ptrs);
}
