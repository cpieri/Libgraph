/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 23:48:12 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 01:49:57 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button.hpp"

Button::Button(Vector4d ppos, Color c, Vector4d ratio_marge, int flags) : 
	_flags_pos(flags), _color(c), _ratio(ratio_marge.get_x(), ratio_marge.get_y()),
	_margin(ratio_marge.get_z(), ratio_marge.get_w()), _pos(0, 0, 0, 0)
{
	this->_pos = calc_position(ppos, this->_ratio, this->_margin, flags);
}

Button::~Button(void)
{
}

Vector4d	Button::get_position(void) const
{
	return (this->_pos);
}

Vector2d	Button::get_margin(void) const
{
	return (this->_margin);
}

Vector2d	Button::get_ratio(void) const
{
	return (this->_ratio);
}

void		Button::recalc_position(Vector4d parent_pos)
{
	this->_pos = calc_position(parent_pos, this->_ratio, this->_margin,
			this->_flags_pos);
}

void       Button::print(Graphics * win) const
{
	win->drawRect(this->_pos, this->_color.color_to_int());
}
