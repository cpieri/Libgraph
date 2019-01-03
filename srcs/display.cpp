/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:44:57 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 01:38:55 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"
#include "color.hpp"
#include <iostream>

Window::Window(void) : _loop(1)
{
}

Window::~Window(void)
{
	SDL_DestroyRenderer(this->_rend);
	SDL_DestroyWindow(this->_win);
}

/******************************************************************************
**	Fonctions for Windows
*******************************************************************************/

void			Window::create(char const * title, int w, int h)
{
	this->_width = w;
	this->_height = h;
	this->_win = SDL_CreateWindow(title, WIN_CENTER, WIN_CENTER, w, h,
			SDL_WINDOW_RESIZABLE);
	this->_rend = SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);
}

void			Window::destroy(void)
{
	SDL_DestroyWindow(this->_win);
}

void			Window::change_size(void)
{
	SDL_GetWindowSize(this->_win, &this->_width, &this->_height);
	std::cout << "change_size " << this->_width << " " << this->_height << std::endl;
}

Vector4d		Window::get_size(void)
{
	return (Vector4d(0, 0, this->_width, this->_height));
}

SDL_Window*		Window::get(void)
{
	return (this->_win);
}

/*******************************************************************************
**	Fonctions for Renders
*******************************************************************************/

void			Window::clear(int color)
{
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, 
			this->_color.get_red(), this->_color.get_green(),
			this->_color.get_blue(), 1);
	SDL_RenderClear(this->_rend);
}

void			Window::clear(Color c)
{
	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, 
			this->_color.get_red(), this->_color.get_green(),
			this->_color.get_blue(), 1);
	SDL_RenderClear(this->_rend);
}

void			Window::print(void) const
{
	SDL_RenderPresent(this->_rend);
}

SDL_Renderer*	Window::get_render(void)
{
	return (this->_rend);
}

/*******************************************************************************
**	Fonctions for Events
*******************************************************************************/

int				Window::set_loop(int loop)
{
	if (loop > 1 && loop < 0)
		return (-1);
	this->_loop = loop;
	return (0);
}

int				Window::get_loop(void) const
{
	return (this->_loop);
}
