/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:24:24 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/19 18:22:38 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label.hpp"

Label::Label(char const * s, int f_size, Color c, Vector4d r_m) : _title(s),
	_font_size(f_size), _color(c), _ratio_marge(r_m)
{
}

Label::~Label(void)
{
	delete this->_title;
}
