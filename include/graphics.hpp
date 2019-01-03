/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 01:39:23 by delay             #+#    #+#             */
/*   Updated: 2019/01/03 01:42:14 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GRAPHICS_HPP__
# define __GRAPHICS_HPP__

# include "display.hpp"

class	Graphics : public Window
{
	public:
		Graphics(void);
		~Graphics(void);

		int				drawPixel(int x, int y, int color = 0xffffff);
		int				drawPixel(int x, int y, Color c);

		int				drawRect(Vector4d rect, int color = 0xffffff);
		int				drawRect(Vector4d rect, Color c);
		int				drawRect(int x, int y, int w, int h);

		void			setColor(Color c);
		void			setColor(int color);
		void			setColor(int r, int g, int b);
};

#endif
