/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.hpp                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cpieri <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/13 21:44:10 by cpieri       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 01:28:31 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef	__IMAGE_HPP__
# define __IMAGE_HPP__

# include <SDL.h>
# include <SDL_image.h>
# include "image.hpp"

# define	DEPTH	24
# define	RMASK	0xFF000000
# define	GMASK	0x00FF0000
# define	BMASK	0x0000FF00
# define	AMASK	0x000000FF

class	Image
{
	private:
		int				_width;
		int				_height;
		SDL_Surface *	_image;

	public:
		Image(void);
		~Image(void);
		Image(const uint16_t * buffer);
		Image(const char * filename);

		int				width(void);
		int				height(void);
		SDL_Texture *	get_texture(SDL_Renderer * rend);
		SDL_Surface *	get_surface(void);
};

#endif
