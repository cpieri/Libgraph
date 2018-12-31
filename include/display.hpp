/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:11:02 by delay             #+#    #+#             */
/*   Updated: 2018/12/31 18:29:28 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

# include <SDL.h>
# include "vector.hpp"
# define WIN_CENTER SDL_WINDOWPOS_CENTERED

class	Window
{
	private:
		SDL_Window*		_win;
		SDL_Renderer*	_rend;
		int				_width;
		int				_height;
		int				_loop;

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
		void			clear(void);
		void			print(void);
		int				draw_pixel(int x, int y, int color);
		SDL_Renderer*	get_render(void);

		/*
		**	Fonctions for Events
		*/
		int				get_loop(void) const;
		void			set_loop(int loop);
};

#endif
