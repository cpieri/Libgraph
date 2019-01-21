/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:06:50 by delay             #+#    #+#             */
/*   Updated: 2019/01/21 17:40:18 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamebuino_sdl.hpp"
#include <ctime>
#include <iostream>

GamebuinoSdl::GamebuinoSdl(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);
	display.create("game", MACOS_WIDTH, MACOS_HEIGHT);
}

GamebuinoSdl::~GamebuinoSdl(void)
{
	SDL_Quit();
}

void	GamebuinoSdl::begin(void)
{
	this->frameEndFlag = true;
	this->_time = 0;
	this->frameCount = 0;
	buttons.update();
	display.clear(WHITE);
	display.present();
}

bool	GamebuinoSdl::update(void)
{
	if (((this->_time - SDL_GetTicks()) > TIMEPERFRAME) && this->frameEndFlag)
	{
		this->frameCount++;
		this->_time = SDL_GetTicks() + TIMEPERFRAME;
		std::cout << this->frameCount << std::endl;
		buttons.update();
		this->frameEndFlag = false;
		return (true);
	}
	if (this->frameEndFlag)
		return (false);
	this->frameEndFlag = true;
	return (false);
}

int		GamebuinoSdl::get_event_type(void)
{
	return (this->buttons.get_type());
}
