/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:35:43 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/22 16:43:07 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vector3d	vector_op(t_vector3d a, t_vector3d b, char type)
{
	if (type == '-')
		return (new_vector_3d(a.x - b.x, a.y - b.y, a.z - b.z));
	else if (type == '*')
		return (new_vector_3d(a.x * b.x, a.y * b.y, a.z * b.z));
	else if (type == '/')
		return (new_vector_3d(a.x / b.x, a.y / b.y, a.z / b.z));
	return (new_vector_3d(a.x + b.x, a.y + b.y, a.z + b.z));
}
