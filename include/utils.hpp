/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delay <cpieri@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 18:12:56 by delay             #+#    #+#             */
/*   Updated: 2018/12/31 18:51:06 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__UTILS_HPP__
# define __UTILS_HPP__

# define LEFT_UP_CONER		0
# define LEFT_DOWN_CONER	1
# define RIGHT_UP_CONER		2
# define RIGHT_DOWN_CONER	3
# define VERTICAL_CENTER	4
# define HORIZONTAL_CENTER	5
# define CENTER				6

# include "vector.hpp"

Vector4d	calc_position(Vector4d ppos, Vector2d r, Vector2d m, int flags);

#endif
