/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:10:40 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/19 18:35:56 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COLOR_HPP__
# define __COLOR_HPP__

class	Color
{
	private:
		int		_r;
		int		_g;
		int		_b;

	public:
		Color(void);
		~Color(void);

		int		get_red(void) const;
		int		get_green(void) const;
		int		get_blue(void) const;
		int		color_to_int(void) const;
		void	int_to_color(int nb);
		void	set_color(int red, int green, int blue);
		void	set_red(int red);
		void	set_green(int green);
		void	set_blue(int blue);
};

int				interpolate(int start, int finish, float ratio);
Color			color_prod(Color c, double lambda);

#endif
