/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:40:33 by delay             #+#    #+#             */
/*   Updated: 2018/12/22 16:45:41 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <math.h>

Vector2d::Vector2d(double x, double y) : _x(x), _y(y)
{
	return ;
}

Vector2d::~Vector2d(void)
{
	return ;
}

double	Vector2d::get_x(void) const
{
	return (this->_x);
}

double	Vector2d::get_y(void) const
{
	return (this->_y);
}

double	Vector2d::dotprod(Vector2d b) const
{
	return (this->_x * b.get_x() + this->_y * b.get_y());
}

double	Vector2d::distance(Vector2d b) const
{
	double	x;
	double	y;
	double	d;

	x = (this->_x - b.get_x()) * (this->_x - b.get_x());
	y = (this->_y - b.get_y()) * (this->_y - b.get_y());
	d = sqrt(x + y);
	return (d);
}

void	Vector2d::set_value(double x, double y)
{
	this->_x = x;
	this->_y = y;
}

void	Vector2d::set_unicoord_value(double value)
{
	this->_x = value;
	this->_y = value;
}

void	Vector2d::lambda_product(double const lambda)
{
	this->_x = lambda * this->_x;
	this->_y = lambda * this->_y;
}
