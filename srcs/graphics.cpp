/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:33:16 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 01:45:27 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.hpp"

int				Graphics::drawPixel(int x, int y, int color)
{
	int 	ret;

	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawPoint(this->_rend, x, y);
	return (ret);
}

int				Graphics::drawPixel(int x, int y, Color c)
{
	int 	ret;

	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawPoint(this->_rend, x, y);
	return (ret);

}

int				Graphics::drawRect(Vector4d rect, int color)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color.int_to_color(color);
	sdl_rect.x = rect.get_x(); 
	sdl_rect.y = rect.get_y(); 
	sdl_rect.w = rect.get_z(); 
	sdl_rect.h = rect.get_w();
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Graphics::drawRect(Vector4d rect, Color c)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color = c;
	sdl_rect.x = rect.get_x(); 
	sdl_rect.y = rect.get_y(); 
	sdl_rect.w = rect.get_z(); 
	sdl_rect.h = rect.get_w();
	SDL_SetRenderDrawColor(this->_rend,  this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Graphics::drawRect(int x, int y, int w, int h)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	sdl_rect.x = x; 
	sdl_rect.y = y; 
	sdl_rect.w = w; 
	sdl_rect.h = h;
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

void			Graphics::setColor(Color c)
{
	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}

void			Graphics::setColor(int color)
{
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}

void			Graphics::setColor(int r, int g, int b)
{
	this->_color.set_color(r, g, b);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}
