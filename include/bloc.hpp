/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 16:55:47 by delay             #+#    #+#             */
/*   Updated: 2019/01/02 00:00:27 by delay            ###   ########.fr       */
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

typedef	struct		s_obj
{
	void *			obj;
	int				type;
	size_t			obj_size;
	struct s_obj *	next;
}					t_obj;

class	Bloc
{
	private:
		int const		_pos_flags;
		Vector4d		_pos;
		Vector2d const	_ratio;
		Vector2d const	_margin;
		Color			_color;
		//Label			_title;
		int				_nb_child;
		t_obj **		_lst_obj;

	public:
		Bloc(Vector4d win_size, Vector4d ratio_margin, Color c, int flags);
		~Bloc(void);

		//Label		get_title(void) const;
		//void		set_title(char const * title, Color c, Vector4d pos);

		/*
		**	Fonctions for Positions
		*/
		Vector4d	get_position(void) const;
		Vector2d	get_margin(void) const;
		Vector2d	get_ratio(void) const;
		void		recalc_position(Vector4d parent_pos);

		/*
		**	Fonctions for Printings
		*/
		void		print(Window* win) const;

		/*
		**	Fonctions for child obj
		*/
		int			init_nb_childrens(int nb);
		int			new_children(void * child, size_t child_size, int type);
};

#endif
