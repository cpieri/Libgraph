/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 17:13:05 by delay             #+#    #+#             */
/*   Updated: 2018/12/31 21:45:51 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bloc.hpp"
#include <iostream>

Bloc::Bloc(Vector4d win_size, Vector4d ratio_margin, Color c, int flags) :
	_pos_flags(flags), _pos(0, 0, 0, 0),
	_ratio(ratio_margin.get_x(), ratio_margin.get_y()),
	_margin(ratio_margin.get_z(), ratio_margin.get_w()), _color(c)
{
	this->_pos = calc_position(win_size, this->_ratio, this->_margin, flags);
}

Bloc::~Bloc(void)
{
}

Vector4d	Bloc::get_position(void) const
{
	return (this->_pos);
}

Vector2d	Bloc::get_margin(void) const
{
	return (this->_margin);
}

Vector2d	Bloc::get_ratio(void) const
{
	return (this->_ratio);
}

void		Bloc::recalc_position(Vector4d parent_pos)
{
	std::cout << "pos " << parent_pos.get_z() << std::endl;
	std::cout << "pos " << parent_pos.get_w() << std::endl;
	this->_pos = calc_position(parent_pos, this->_ratio, this->_margin,
			this->_pos_flags);
}

void		Bloc::print(Window* win)
{
	win->draw_rect(this->_pos, 0xffccaa);
}
