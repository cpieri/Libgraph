/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 17:13:05 by delay             #+#    #+#             */
/*   Updated: 2019/01/02 00:50:12 by delay            ###   ########.fr       */
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

void		Bloc::print(Window* win) const
{
	win->draw_rect(this->_pos, this->_color.color_to_int());
}

int			Bloc::init_nb_childrens(int nb)
{
	this->_lst_child = new Obj*[nb];
	if (this->_lst_child == NULL)
		return (-1);
	this->_lst_child[nb] = NULL;
	this->_nb_child = nb;
	this->_not_null_child = 0;
	return (0);
}

int		Bloc::new_children(void * child, size_t child_size, int type)
{
	Obj *	nchild = new Obj;

	if (nchild == NULL)
		return (-1);
	nchild->obj = child;
	nchild->obj_size = child_size;
	nchild->type = type;
	if (this->_not_null_child < this->_nb_child)
	{
		this->_lst_child[this->_not_null_child] = nchild;
		this->_not_null_child++;
	}
	return (0);
}
