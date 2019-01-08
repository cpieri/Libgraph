/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:47:38 by delay             #+#    #+#             */
/*   Updated: 2019/01/08 12:01:47 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__BUTTON_HPP__
# define __BUTTON_HPP__

# include <SDL.h>

# define	BUTTON_A	SDLK_o

class	Buttons
{
	private:

	public:
		bool	pressed(void button) const;
		bool	released(void button) const;
		bool	held(void button, int time) const;
		bool	repeat(void button, int period) const;
};

#endif
