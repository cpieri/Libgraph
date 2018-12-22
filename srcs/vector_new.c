/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:17:23 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/22 16:44:04 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector4d	new_vector_4d(double x, double y, double z, double w)
{
	t_vector4d	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = w;
	return (a);
}
