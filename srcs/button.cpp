/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:47:23 by delay             #+#    #+#             */
/*   Updated: 2019/01/21 17:45:13 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "button.hpp"
#include <iostream>

void	Buttons::wait(void)
{
}

size_t	Buttons::get_type(void) const
{
	return (this->_event.type);
}

bool	Buttons::update(void) 
{
	//SDL_WaitEvent(&this->_event);
	SDL_PollEvent(&this->_event);
	if (this->_event.type == SDL_KEYDOWN)
		return (false);
	return (true);
}

bool	Buttons::pressed(Button button) 
{
	Button	key;

	if (this->_event.type == SDL_KEYDOWN)
		if (this->_event.key.state == SDL_PRESSED  && this->_event.key.repeat == 0)
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
		if (this->_event.key.state == SDL_RELEASED && this->_event.key.repeat == 0)
		{
			key = this->_event.key.keysym.sym;
			if (key == button)
				return (true);
		}
	return (false);
}

bool	Buttons::repeat(Button button, int period) 
{
	Button	key;

	if (period <= 1)
		if (this->_event.key.state == SDL_PRESSED && this->_event.key.repeat <= 1)
		{
			key = this->_event.key.keysym.sym;
			if (key == button)
				return (true);
		}
	return (false);
}
