/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:44:57 by delay             #+#    #+#             */
/*   Updated: 2019/01/08 11:31:33 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"
#include "color.hpp"
#include <iostream>
#include <stdlib.h>

Window::Window(void) : _loop(1)
{
}

Window::~Window(void)
{
	SDL_DestroyRenderer(this->_rend);
	SDL_DestroyWindow(this->_win);
}

/*******************************************************************************
**							Fonctions for Windows							  **
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

int				Window::height(void) const
{
	return (this->_height);
}

int				Window::width(void) const
{
	return (this->_width);
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
**							Fonctions for Renders							  **
*******************************************************************************/

void			Window::fill(int color)
{
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, 
			this->_color.get_red(), this->_color.get_green(),
			this->_color.get_blue(), 1);
	SDL_RenderClear(this->_rend);
}

void			Window::fill(Color c)
{
	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, 
			this->_color.get_red(), this->_color.get_green(),
			this->_color.get_blue(), 1);
	SDL_RenderClear(this->_rend);
}


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

void			Window::present(void) const
{
	SDL_RenderPresent(this->_rend);
}

SDL_Renderer*	Window::get_render(void)
{
	return (this->_rend);
}

/*******************************************************************************
**							Fonctions for draw								  **
*******************************************************************************/

int				Window::drawPixel(int x, int y, int color)
{
	int 	ret;

	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawPoint(this->_rend, P(x), P(y));
	return (ret);
}

int				Window::drawPixel(int x, int y, Color c)
{
	int 	ret;

	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawPoint(this->_rend, P(x), P(y));
	return (ret);

}

int				Window::drawLine(int x0, int y0, int x1, int y1)
{
	int		ret;

	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawLine(this->_rend, P(x0), P(y0), P(x1), P(y1));
	return (ret);
}

void			Window::drawFastVLine(int x, int y, int h, int color)
{
	x = P(x);
	y = P(y);
	h = P(h);
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	if (h < 0) {
		y += h + 1;
		h = abs(h);
	}
	SDL_RenderDrawLine(this->_rend, x, y, x, y + h - 1);
}

void			Window::drawFastHLine(int x, int y, int w, int color)
{
	x = P(x);
	y = P(y);
	w = P(w);
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	if (w < 0) {
		x += w + 1;
		w = abs(w);
	}
	SDL_RenderDrawLine(this->_rend, x, y, x + w - 1, y);
}

int				Window::drawRect(Vector4d rect, int color)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color.int_to_color(color);
	sdl_rect.x = P(rect.get_x());
	sdl_rect.y = P(rect.get_y());
	sdl_rect.w = P(rect.get_z());
	sdl_rect.h = P(rect.get_w());
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Window::drawRect(Vector4d rect, Color c)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color = c;
	sdl_rect.x = P(rect.get_x());
	sdl_rect.y = P(rect.get_y());
	sdl_rect.w = P(rect.get_z());
	sdl_rect.h = P(rect.get_w());
	SDL_SetRenderDrawColor(this->_rend,  this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Window::drawRect(int x, int y, int w, int h)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	sdl_rect.x = P(x);
	sdl_rect.y = P(y);
	sdl_rect.w = P(w);
	sdl_rect.h = P(h);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderDrawRect(this->_rend, &sdl_rect);
	return (ret);
}


int				Window::fillRect(Vector4d rect, int color)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color.int_to_color(color);
	sdl_rect.x = P(rect.get_x()); 
	sdl_rect.y = P(rect.get_y());
	sdl_rect.w = P(rect.get_z()); 
	sdl_rect.h = P(rect.get_w());
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Window::fillRect(Vector4d rect, Color c)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	this->_color = c;
	sdl_rect.x = P(rect.get_x()); 
	sdl_rect.y = P(rect.get_y());
	sdl_rect.w = P(rect.get_z()); 
	sdl_rect.h = P(rect.get_w());
	SDL_SetRenderDrawColor(this->_rend,  this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

int				Window::fillRect(int x, int y, int w, int h)
{
	SDL_Rect	sdl_rect;
	int 		ret;

	sdl_rect.x = P(x); 
	sdl_rect.y = P(y); 
	sdl_rect.w = P(w); 
	sdl_rect.h = P(h);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	ret = SDL_RenderFillRect(this->_rend, &sdl_rect);
	return (ret);
}

void			Window::drawCircle(int x0, int y0, int r, int color)
{
	x0 = P(x0);
	y0 = P(y0);
	r = P(r);
	int		f = 1 - r;
	int		ddF_x = 1;
	int		ddF_y = -2 * r;
	int		x = 0;
	int		y = r;

	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
	SDL_RenderDrawPoint(this->_rend, x0, y0+r);
	SDL_RenderDrawPoint(this->_rend, x0, y0-r);
	SDL_RenderDrawPoint(this->_rend, x0+r, y0);
	SDL_RenderDrawPoint(this->_rend, x0-r, y0);
	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
		SDL_RenderDrawPoint(this->_rend, x0 + x, y0 + y);
		SDL_RenderDrawPoint(this->_rend, x0 - x, y0 + y);
		SDL_RenderDrawPoint(this->_rend, x0 + x, y0 - y);
		SDL_RenderDrawPoint(this->_rend, x0 - x, y0 - y);
		SDL_RenderDrawPoint(this->_rend, x0 + y, y0 + x);
		SDL_RenderDrawPoint(this->_rend, x0 - y, y0 + x);
		SDL_RenderDrawPoint(this->_rend, x0 + y, y0 - x);
		SDL_RenderDrawPoint(this->_rend, x0 - y, y0 - x);
	}
}



void			Window::setColor(Color c)
{
	this->_color = c;
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}

void			Window::setColor(int color)
{
	this->_color.int_to_color(color);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}

void			Window::setColor(int r, int g, int b)
{
	this->_color.set_color(r, g, b);
	SDL_SetRenderDrawColor(this->_rend, this->_color.get_red(),
			this->_color.get_green(), this->_color.get_blue(), 1);
}

/*******************************************************************************
**							Fonctions for Events							  **
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
