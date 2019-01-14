/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.cpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cpieri <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 21:46:27 by cpieri       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 01:49:10 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "image.hpp"
#include <iostream>

Image::Image(void)
{
	std::cout << "in Image(void)" << std::endl;
}

Image::~Image(void)
{
}

Image::Image(const uint16_t * buffer)
{
	int		width;
	int		height;
	int		pitch;


	width = buffer[0];
	height = buffer[1];
	pitch = 3 * width;
	buffer += 6;
	this->_image = SDL_CreateRGBSurfaceFrom((void*)buffer, width, height, DEPTH,
			pitch, RMASK, GMASK, BMASK, AMASK);
	this->_height = height;
	this->_width = width;
}

Image::Image(const char * filename)
{
	this->_image =  IMG_Load(filename);
}

int				Image::width(void)
{
	return (this->_width);
}

int				Image::height(void)
{
	return (this->_height);
}

SDL_Texture *	Image::get_texture(SDL_Renderer * rend)
{
	SDL_Texture	*	ret;

	ret = SDL_CreateTextureFromSurface(rend, this->_image);
	return (ret);
}

SDL_Surface *	Image::get_surface(void)
{
	return (this->_image);
}
