/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:03:33 by delay             #+#    #+#             */
/*   Updated: 2018/12/22 17:09:00 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

Vector4d::Vector4d(double x, double y, double z, double w) : _x(x), _y(y), _z(z),
	_w(w)
{
	return ;
}

Vector4d::~Vector4d(void)
{
	return ;
}

double	Vector4d::get_x(void) const
{
	return (this->_x);
}

double	Vector4d::get_y(void) const
{
	return (this->_y);
}

double	Vector4d::get_z(void) const
{
	return (this->_z);
}

double	Vector4d::get_w(void) const
{
	return (this->_w);
}

void	Vector4d::set_value(double x, double y, double z, double w)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_w = w;
}

void	Vector4d::set_unicoord_value(double value)
{
	this->_x = value;
	this->_y = value;
	this->_z = value;
	this->_w = value;
}
