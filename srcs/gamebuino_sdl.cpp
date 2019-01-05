/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:06:50 by delay             #+#    #+#             */
/*   Updated: 2019/01/05 19:40:45 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamebuino_sdl.hpp"

GamebuinoSdl::GamebuinoSdl(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	display.create("game", MACOS_WIDTH, MACOS_HEIGHT);
}

GamebuinoSdl::~GamebuinoSdl(void)
{
	SDL_Quit();
}

bool	GamebuinoSdl::update(void)
{
	SDL_WaitEvent(&this->_event);
	if (this->_event.type == 512)
		return (false);
	return (true);
}

int		GamebuinoSdl::get_event_type(void)
{
	return (this->_event.type);
}
