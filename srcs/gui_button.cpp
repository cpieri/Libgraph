/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_button.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 23:48:12 by delay             #+#    #+#             */
/*   Updated: 2019/01/08 11:39:09 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_button.hpp"

Gui_Button::Gui_Button(Vector4d ppos, Color c, Vector4d ratio_marge, int flags) : 
	_flags_pos(flags), _color(c), _ratio(ratio_marge.get_x(), ratio_marge.get_y()),
	_margin(ratio_marge.get_z(), ratio_marge.get_w()), _pos(0, 0, 0, 0)
{
	this->_pos = calc_position(ppos, this->_ratio, this->_margin, flags);
}

Gui_Button::~Gui_Button(void)
{
}

Vector4d	Gui_Button::get_position(void) const
{
	return (this->_pos);
}

Vector2d	Gui_Button::get_margin(void) const
{
	return (this->_margin);
}

Vector2d	Gui_Button::get_ratio(void) const
{
	return (this->_ratio);
}

void		Gui_Button::recalc_position(Vector4d parent_pos)
{
	this->_pos = calc_position(parent_pos, this->_ratio, this->_margin,
			this->_flags_pos);
}

void       Gui_Button::print(Window * win) const
{
	win->drawRect(this->_pos, this->_color.color_to_int());
}
