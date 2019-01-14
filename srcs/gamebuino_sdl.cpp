/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:06:50 by delay             #+#    #+#             */
/*   Updated: 2019/01/14 01:42:54 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "gamebuino_sdl.hpp"

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

bool	GamebuinoSdl::update(void)
{
	if (buttons.update() == false)
		return (false);
	return (true);
}

int		GamebuinoSdl::get_event_type(void)
{
	return (this->buttons.get_type());
}
