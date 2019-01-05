/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 22:56:43 by delay             #+#    #+#             */
/*   Updated: 2019/01/05 21:00:50 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__GAMEBUINO_SDL_HPP__
# define __GAMEBUINO_SDL_HPP__

# include "display.hpp"


# define MACOS_WIDTH		800
# define MACOS_HEIGHT		640
# define GAMEBUINO_WIDTH    80
# define GAMEBUINO_HEIGHT   64

class	GamebuinoSdl
{
	private:
		SDL_Event	_event;

	public:
		Window	display;

		GamebuinoSdl(void);
		~GamebuinoSdl(void);

		bool	update(void);
		int		get_event_type(void);
};

#endif
