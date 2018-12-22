/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:35:43 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/22 18:58:20 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

Vector3d	vector_op(Vector3d a, Vector3d b, char type)
{
	Vector3d	c(0, 0, 0);

	if (type == '-')
		c.set_value(a.get_x() - b.get_x(), a.get_y() - b.get_y(),
				a.get_z() - b.get_z());
	else if (type == '*')
		c.set_value(a.get_x() * b.get_x(), a.get_y() * b.get_y(),
				a.get_z() * b.get_z());
	else if (type == '/')
		c.set_value(a.get_x() / b.get_x(), a.get_y() / b.get_y(),
				a.get_z() / b.get_z());
	else
		c.set_value(a.get_x() + b.get_x(), a.get_y() + b.get_y(),
				a.get_z() + b.get_z());
	return (c);
}

Vector2d	vector_op_2d(Vector2d a, Vector2d b, char type)
{
	Vector2d	c(0, 0);

	if (type == '-')
		c.set_value(a.get_x() - b.get_x(), a.get_y() - b.get_y());
	else if (type == '*')
		c.set_value(a.get_x() * b.get_x(), a.get_y() * b.get_y());
	else if (type == '/')
		c.set_value(a.get_x() / b.get_x(), a.get_y() / b.get_y());
	else
		c.set_value(a.get_x() + b.get_x(), a.get_y() + b.get_y());
	return (c);
}
