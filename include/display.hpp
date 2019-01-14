/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:11:02 by delay             #+#    #+#             */
/*   Updated: 2019/01/14 04:29:53 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DISPLAY_HPP__
# define __DISPLAY_HPP__

# include <SDL.h>
# include "vector.hpp"
# include "color.hpp"
# include "gb_image.hpp"

# define	WIN_CENTER SDL_WINDOWPOS_CENTERED
# define	P(x)		(x * 10)
# define	WHITE		0xFFFFFF
# define	GRAY		0xAD9A84
# define	DARKGRAY	0x524D42
# define	BLACK		0x000000
# define	PURPLE		0x940042
# define	PINK		0xCE4584
# define	RED			0xDE1C21
# define	ORANGE		0xFFAA10
# define	BROWN		0xCE8E42
# define	BEIGE		0xFFD794
# define	YELLOW		0xF7E700
# define	LIGHTGREEN	0x84CE42
# define	GREEN		0x008A52
# define	DARKBLUE	0x004184
# define	BLUE		0x4286CE
# define	LIGHTBLUE	0x7BBAFF

class	Window
{
	protected:
		SDL_Window*		_win;
		SDL_Renderer*	_rend;
		int				_width;
		int				_height;
		int				_loop;
		int				_cursor_x;
		int				_cursor_y;
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
		int				height(void) const;
		int				width(void) const;
		Vector4d		get_size(void);
		SDL_Window*		get(void);

		/*
		**	Fonctions for Renders
		*/
		void			fill(int color = 0x000000);
		void			fill(Color c);
		void			clear(int color = 0x000000);
		void			clear(Color c);
		void			present(void) const;
		SDL_Renderer*	get_render(void);

		/*
		**	Fonctions for draw
		*/
		void			drawImage(int x, int y, Image img);
		void			drawImage(int x, int y, Image img, int w, int h);
		int				drawPixel(int x, int y, int color = 0xffffff);
		int				drawPixel(int x, int y, Color c);
		int				drawLine(int x0, int y0, int x1, int y1);
		void			drawFastVLine(int x, int y, int h, int color = 0xffffff);
		void			drawFastHLine(int x, int y, int w, int color = 0xffffff);
		int				drawRect(Vector4d rect, int color = 0xffffff);
		int				drawRect(Vector4d rect, Color c);
		int				drawRect(int x, int y, int w, int h);
		int				fillRect(Vector4d rect, int color = 0xffffff);
		int				fillRect(Vector4d rect, Color c);
		int				fillRect(int x, int y, int w, int h);
		void			drawCircle(int x, int y, int r, int color = 0xffffff);
		//void			fillCircle(int x, int y, int r, int color = 0xffffff);
		void			setColor(Color c);
		void			setColor(int color);
		void			setColor(int r, int g, int b);
		void			setCursor(int x, int y);
	

		/*
		**	Fonctions for Events
		*/
		int				get_loop(void) const;
		int				set_loop(int loop);
};

#endif
