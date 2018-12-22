/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:31:43 by delay             #+#    #+#             */
/*   Updated: 2018/12/22 18:38:55 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <math.h>

Vector3d::Vector3d(double x, double y, double z) : _x(x), _y(y), _z(z)
{
	return ;
}

Vector3d::~Vector3d(void)
{
	return ;
}

double	Vector3d::get_x(void) const
{
	return (this->_x);
}

double	Vector3d::get_y(void) const
{
	return (this->_y);
}

double	Vector3d::get_z(void) const
{
	return (this->_z);
}

double	Vector3d::get_length(void) const
{
	return (sqrt(this->_x * this->_x + this->_y + this->_y + this->_z + this->_z));
}

double	Vector3d::dotprod(Vector3d b) const
{
	return (this->_x * b.get_x() + this->_y * b.get_y() + this->_z * b.get_z());
}

double	Vector3d::distance(Vector3d b) const
{
	double	x;
	double	y;
	double	z;
	double	d;

	x = (this->_x - b.get_x()) * (this->_x - b.get_x());
	y = (this->_y - b.get_y()) * (this->_y - b.get_y());
	z = (this->_z - b.get_z()) * (this->_z - b.get_z());
	d = sqrt(x + y + z);
	return (d);
}

void	Vector3d::set_value(double x, double y, double z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

void	Vector3d::set_unicoord_value(double value)
{
	this->_x = value;
	this->_y = value;
	this->_z = value;
}

void	Vector3d::normalize(void)
{
	double const	length = this->get_length();

	this->_x = this->_x / length;
	this->_y = this->_y / length;
	this->_z = this->_z / length;
}

void	Vector3d::lambda_product(double const lambda)
{
	this->_x = lambda * this->_x;
	this->_y = lambda * this->_y;
	this->_z = lambda * this->_z;
}

void	Vector3d::vectorial_prod(Vector3d b)
{
	this->_x = this->_y * b.get_z() - this->_z * b.get_y();
	this->_y = this->_z * b.get_x() - this->_x * b.get_z();
	this->_z = this->_x * b.get_y() - this->_y * b.get_x();
}

void	Vector3d::find_normal(void)
{
	if (this->_x)
	{
		if (this->_y)
			this->set_value(1, -this->_x / this->_y, 0);
		else
			this->set_value(0, 1, 0);
	}
	else if (this->_y || this->_z)
		this->set_value(1, 0, 0);
	else
		this->set_value(0, 0, 0);
}
