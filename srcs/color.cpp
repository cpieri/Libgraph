/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:53:16 by tmilon            #+#    #+#             */
/*   Updated: 2018/12/31 19:09:10 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include <math.h>

Color::Color(void)
{
	return ;
}

Color::~Color(void)
{
}

int		Color::get_red(void) const
{
	return (this->_r);
}

int		Color::get_green(void) const
{
	return (this->_g);
}

int		Color::get_blue(void) const
{
	return (this->_b);
}

int		Color::color_to_int(void) const
{
	return ((((this->_r > 0xff) ? 0xff : this->_r) << 16) |
			(((this->_g > 0xff) ? 0xff : this->_g) << 8) |
			((this->_b > 0xff) ? 0xff : this->_b));
}

void	Color::int_to_color(int nb)
{
	this->_r = (nb & 0x00FF0000) >> 16;
	this->_g = (nb & 0x0000FF00) >> 8;
	this->_b = (nb & 0x000000FF);
}

void	Color::set_color(int red, int green, int blue)
{
	this->_r = red;
	this->_g = green;
	this->_b = blue;
}

void	Color::set_red(int red)
{
	this->_r = red;
}

void	Color::set_green(int green)
{
	this->_g = green;
}

void	Color::set_blue(int blue)
{
	this->_b = blue;
}

int		interpolate(int start, int finish, float ratio)
{
	Color	a;
	Color	b;

	a.int_to_color(start);
	b.int_to_color(finish);
	a.set_red(a.get_red() + ((b.get_red() - a.get_red()) * ratio));
	a.set_green(a.get_green() + ((b.get_green() - a.get_green()) * ratio));
	a.set_blue(a.get_blue() + ((b.get_blue() - a.get_blue()) * ratio));
	return (a.color_to_int());
}


Color	color_prod(Color c, double lambda)
{
	Color	n;

	n.set_red(fmax(0, fmin(255, lambda * c.get_red())));
	n.set_green(fmax(0, fmin(255, lambda * c.get_green())));
	n.set_blue(fmax(0, fmin(255, lambda * c.get_blue())));
	return (n);
}
