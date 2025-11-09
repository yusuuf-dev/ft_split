/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-you <yoel-you@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:25:12 by yoel-you          #+#    #+#             */
/*   Updated: 2025/11/09 12:31:59 by yoel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    this main for testing and you need to complain using :
    cc main.c ft_split.c ft_strlen.c ft_strdup.c

    if you want to test simple version compile with :
    cc main.c ft_split_simple_.c ft_strlen.c ft_strdup.c
*/

#include "header.h"

int main()
{
    char *str = " hello      world  how        are  you        ";

    char **words = ft_split(str,' ');

    int i = 0;
    while(words && words[i])
    {
        printf("%s\n",words[i]);
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}