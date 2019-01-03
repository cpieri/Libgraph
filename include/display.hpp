/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:11:02 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 01:42:52 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

# include <SDL.h>
# include "vector.hpp"
# include "color.hpp"
# define WIN_CENTER SDL_WINDOWPOS_CENTERED

class	Window
{
	protected:
		SDL_Window*		_win;
		SDL_Renderer*	_rend;
		int				_width;
		int				_height;
		int				_loop;
		Color			_color;

	public:
		Window(void);
		~Window(void);
		
		/*
		**	Fonctions for Windows
		*/
		void			create(char const * title, int w, int h);
		void			destroy(void);
		void			change_size(void);
		Vector4d		get_size(void);
		SDL_Window*		get(void);

		/*
		**	Fonctions for Renders
		*/

		void			clear(int color = 0x000000);
		void			clear(Color c);

		void			print(void) const;

		SDL_Renderer*	get_render(void);

		/*
		**	Fonctions for Events
		*/
		int				get_loop(void) const;
		int				set_loop(int loop);
};

#endif
