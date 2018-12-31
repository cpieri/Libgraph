/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 16:55:47 by delay             #+#    #+#             */
/*   Updated: 2018/12/31 20:22:54 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BLOC_HPP__
# define __BLOC_HPP__

# include "color.hpp"
# include "display.hpp"
# include "vector.hpp"
# include "utils.hpp"
# include <cstdlib>

# define BUTTON		1
# define LABEL		2

class	Bloc
{
	private:
		int const		_pos_flags;
		Vector4d		_pos;
		Vector2d const	_ratio;
		Vector2d const	_margin;
		Color			_color;
		//Label			_title;
		//t_obj **		_lst_obj;

	public:
		Bloc(Vector4d win_size, Vector4d ratio_margin, Color c, int flags);
		~Bloc(void);

		/*
		**	Fonctions for Gets and Set
		*/
		Vector4d	get_position(void) const;
		Vector2d	get_margin(void) const;
		Vector2d	get_ratio(void) const;
		//Label		get_title(void) const;
		//void		set_title(char const * title, Color c, Vector4d pos);

		/*
		**	Position
		*/
		void		recalc_position(Vector4d parent_pos);

		void		print(Window* win);
};

#endif
