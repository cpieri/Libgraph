/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:11:02 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 13:50:36 by delay            ###   ########.fr       */
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
		void			present(void) const;
		SDL_Renderer*	get_render(void);

		/*
		**	Fonctions for draw
		*/
		int				drawPixel(int x, int y, int color = 0xffffff);
		int				drawPixel(int x, int y, Color c);
		int				drawRect(Vector4d rect, int color = 0xffffff);
		int				drawRect(Vector4d rect, Color c);
		int				drawRect(int x, int y, int w, int h);
		void			setColor(Color c);
		void			setColor(int color);
		void			setColor(int r, int g, int b);
	

		/*
		**	Fonctions for Events
		*/
		int				get_loop(void) const;
		int				set_loop(int loop);
};

#endif
