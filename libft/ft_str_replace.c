/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:46:10 by jtrujill          #+#    #+#             */
/*   Updated: 2017/04/21 15:53:32 by jtrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_str_replace(char **old, char *new)
{
	if (*old)
		ft_strdel(old);
	*old = ft_strdup(new);
}
