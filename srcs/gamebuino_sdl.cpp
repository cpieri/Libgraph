/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:06:50 by delay             #+#    #+#             */
/*   Updated: 2019/01/09 14:12:34 by cpieri      ###    #+. /#+    ###.fr     */
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
	if (buttons.update() == false)
		return (false);
	return (true);
}

int		GamebuinoSdl::get_event_type(void)
{
	return (this->buttons.get_type());
}
