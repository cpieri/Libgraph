/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:47:38 by delay             #+#    #+#             */
/*   Updated: 2019/01/09 15:52:42 by cpieri      ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__BUTTON_HPP__
# define __BUTTON_HPP__

# include <SDL.h>

# define	BUTTON_A		SDLK_o
# define	BUTTON_B		SDLK_k
# define	BUTTON_C		SDLK_c
# define	BUTTON_UP		SDLK_w
# define	BUTTON_DOWN		SDLK_s
# define	BUTTON_LEFT		SDLK_a
# define	BUTTON_RIGHT	SDLK_d

typedef	size_t	Button;

class	Buttons
{
	private:
		SDL_Event	_event;

	public:
		size_t	get_type(void) const;
		bool	update(void) ;
		bool	pressed(Button button) ;
		bool	released(Button button) ;
		bool	repeat(Button button, int period) ;
};

#endif
