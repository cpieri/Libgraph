/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 18:17:34 by delay             #+#    #+#             */
/*   Updated: 2018/12/31 21:28:08 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

static Vector4d	calc_left_p(Vector4d ppos, Vector2d size, Vector2d mar, int f)
{
	int		lp_x;
	int		lp_y;

	lp_x = ppos.get_x() + mar.get_x();
	lp_y = ppos.get_y() + mar.get_y();
	if (f == LEFT_DOWN_CONER)
		lp_y = ppos.get_w() - size.get_y() - mar.get_y();
	if (f == RIGHT_UP_CONER)
		lp_x = ppos.get_z() - size.get_x() - mar.get_x();
	if (f == RIGHT_DOWN_CONER)
	{
		lp_x = ppos.get_z() - size.get_x() - mar.get_x();
		lp_y = ppos.get_w() - size.get_y() - mar.get_y();
	}
	if (f == VERTICAL_CENTER || f == CENTER)
		lp_y = (ppos.get_y() + (ppos.get_w() / 2)) - (size.get_y() / 2);
	if (f == HORIZONTAL_CENTER || f == CENTER)
		lp_x = (ppos.get_x() + (ppos.get_z() / 2)) - (size.get_x() / 2);
	return (Vector4d(lp_x, lp_y, size.get_x(), size.get_y()));
}

Vector4d	calc_position(Vector4d ppos, Vector2d r, Vector2d m, int flags)
{
	int			m_x;
	int			m_y;
	int			s_x;
	int			s_y;
	Vector4d	ret(0, 0, 0, 0);

	s_x = (ppos.get_z() * r.get_x() / 100);
	s_y = (ppos.get_w() * r.get_y() / 100);
	m_x = (ppos.get_z() * m.get_x() / 100);
	m_y = (ppos.get_w() * m.get_y() / 100);
	ret = calc_left_p(ppos, Vector2d(s_x, s_y), Vector2d(m_x, m_y), flags);
	return (ret);
}

