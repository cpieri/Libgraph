/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamebuino_sdl.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 22:56:43 by delay             #+#    #+#             */
/*   Updated: 2019/01/16 12:11:48 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__GAMEBUINO_SDL_HPP__
# define __GAMEBUINO_SDL_HPP__

# include "display.hpp"
# include "button.hpp"


# define MACOS_WIDTH		800
# define MACOS_HEIGHT		640
# define GAMEBUINO_WIDTH    80
# define GAMEBUINO_HEIGHT   64

class	GamebuinoSdl
{
	private:
		double	time_per_frame;
		bool	frame_end_flag;

	public:
		Window	display;
		Buttons	buttons;


		GamebuinoSdl(void);
		~GamebuinoSdl(void);

		bool	update(void);
		int		get_event_type(void);
};

#endif
