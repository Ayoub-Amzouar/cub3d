/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:50:37 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/20 14:52:06 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		commas(char *s)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			res++;
		i++;
	}
	return (res);
}
