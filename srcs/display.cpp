/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:44:57 by delay             #+#    #+#             */
/*   Updated: 2019/04/02 17:23:20 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.hpp"
#include "color.hpp"
#include <iostream>
#include <stdlib.h>

Window::Window(void) : _loop(1), _cursor_x(0), _cursor_y(0), _font_size(5)
{
	TTF_Init();
}

Window::~Window(void)
{
	SDL_DestroyRenderer(this->_rend);
	SDL_DestroyWindow(this->_win);
	TTF_Quit();
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

void			Window::drawImage(int x, int y, Image img)
{
	SDL_Texture *	texture;
	SDL_Rect		pos;

	pos.x = P(x);
	pos.y = P(y);
	texture = img.get_texture(this->_rend);
	SDL_RenderCopy(this->_rend, texture, NULL, &pos);
	SDL_DestroyTexture(texture);
}

void			Window::drawImage(int x, int y, Image img, int w, int h)
{
	SDL_Texture *	texture;
	SDL_Rect		pos;

	pos.x = P(x);
	pos.y = P(y);
	pos.w = w;
	pos.h = h;
	texture = img.get_texture(this->_rend);
	SDL_RenderCopy(this->_rend, texture, NULL, &pos);
	SDL_DestroyTexture(texture);
}

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

/******************************************************************************/
/*							Fonctions for Text								  */
/******************************************************************************/

void			Window::setCursor(int x, int y)
{
	this->_cursor_x = x;
	this->_cursor_y = y;
}

void			Window::setCursorX(int x)
{
	this->_cursor_x = x;
}

void			Window::setCursorY(int y)
{
	this->_cursor_y = y;
}

void			Window::setFontSize(int size)
{
	this->_font_size = size;
}

uint16_t		Window::getCursorX(void) const
{
	return (this->_cursor_x);
}

uint16_t		Window::getCursorY(void) const
{
	return (this->_cursor_y);
}

size_t			Window::print(const char *s)
{
	TTF_Font		*font;
	SDL_Rect		pos;
	SDL_Surface		*text;
	SDL_Texture		*texture;
	SDL_Color		c;

	c.r = this->_color.get_red();
	c.g = this->_color.get_green();
	c.b = this->_color.get_blue();
	c.a = 255;
	if ((font = TTF_OpenFont(FONT, P(this->_font_size))) == NULL)
		return (-1);
	if ((text = TTF_RenderText_Blended(font, s, c)) == NULL)
		return (-1);
	if ((texture = SDL_CreateTextureFromSurface(this->_rend, text)) == NULL)
		return (-1);
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	pos.x = P(this->_cursor_x);
	pos.y = P(this->_cursor_y);
	SDL_RenderCopy(this->_rend, texture, NULL, &pos);
	TTF_CloseFont(font);
	SDL_FreeSurface(text);
	SDL_DestroyTexture(texture);
	return (1);
}

void			Window::drawChar(int x, int y, char c, int size)
{
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	this->_cursor_x = x;
	this->_cursor_y = y;
	this->_font_size = size;
	this->print(s);
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
