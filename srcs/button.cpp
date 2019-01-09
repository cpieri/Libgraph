/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:47:23 by delay             #+#    #+#             */
/*   Updated: 2019/01/09 14:18:00 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "button.hpp"

size_t	Buttons::get_type(void) const
{
	return (this->_event.type);
}

bool	Buttons::update(void) 
{
	SDL_WaitEvent(&this->_event);
	if (this->_event.type == 512)
		return (false);
	return (true);
}

bool	Buttons::pressed(Button button) 
{
	Button	key;

	if (this->_event.type == SDL_KEYDOWN)
		if (this->_event.key.state == SDL_PRESSED)
		{
			key = this->_event.key.keysym.sym;
			if (key == button)
				return (true);
		}
	return (false);
}

bool	Buttons::released(Button button) 
{
	Button	key;

	if (this->_event.type == SDL_KEYDOWN)
		if (this->_event.key.state == SDL_RELEASED)
		{
			key = this->_event.key.keysym.sym;
			if (key == button)
				return (true);
		}
	return (false);
}

bool	Buttons::held(Button button, int time) 
{
	button = 0;
	time = 0;
	return (true);
}

bool	Buttons::repeat(Button button, int period) 
{
	if (period <= 1)
		if (this->pressed(button) == true)
			return (true);
	return (false);
}
