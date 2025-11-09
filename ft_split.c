/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-you <yoel-you@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:23:13 by yoel-you          #+#    #+#             */
/*   Updated: 2025/11/09 12:23:48 by yoel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char **clean_all(char **ptrs, char *tmp,int *flag)
{
    size_t i = 0;

    *flag = 0;
    if (tmp)
        free(tmp);
    if (!ptrs)
        return (NULL);
    while (ptrs[i])
    {
        free(ptrs[i]);
        i++;
    }
    free(ptrs);
    return (NULL);
}

static char *charjoin(char *tmp, char c, int *flag, char **ptrs)
{
    char *str;
    size_t i = 0;
    size_t len = ft_strlen(tmp);

    str = (char *)malloc((len + 2) * sizeof(char));
    if (!str)
    {
        clean_all(ptrs,tmp,flag);
        return (NULL);
    }
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

static char **ptrjoin(char **tmp, char **ptrs, int *flag)
{
    char **new;
    size_t i = 0;

    while (ptrs && ptrs[i])
        i++;
    new = (char **)malloc((i + 2) * sizeof(char *));
    if (!new)
        return (clean_all(ptrs,*tmp,flag));
    i = 0;
    while (ptrs && ptrs[i])
    {
        new[i] = ptrs[i];
        i++;
    }
    new[i] = ft_strdup(*tmp);
    if (!new[i])
    {
        free(new);
        return (clean_all(ptrs,*tmp,flag));
    }
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

    while (s && s[i] && flag)
    {
        if (s[i] != c)
            tmp = charjoin(tmp, s[i], &flag, ptrs);
        else if (s[i] == c && tmp)
            ptrs = ptrjoin(&tmp, ptrs, &flag);
        i++;
    }
    if (tmp && flag)
        ptrs = ptrjoin(&tmp, ptrs, &flag);
    return (ptrs);
}
