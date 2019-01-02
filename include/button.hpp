/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 23:45:33 by delay             #+#    #+#             */
/*   Updated: 2019/01/02 01:22:17 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUTTON_HPP__
# define __BUTTON_HPP__

# include "display.hpp"
# include "bloc.hpp"
# include "utils.hpp"

class	Button
{
	private:
		int	const		_flags_pos;
		Color const		_color;
		Vector2d const	_ratio;
		Vector2d const	_margin;
		Vector4d		_pos;

	public:
		Button(Vector4d ppos, Color c, Vector4d ratio_marge, int flags);
		~Button(void);

		Vector4d	get_position(void) const;
		Vector2d	get_margin(void) const;
		Vector2d	get_ratio(void) const;
		void		recalc_position(Vector4d parent_pos);

		void		print(Window * win) const;
};

#endif
