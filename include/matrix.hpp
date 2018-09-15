/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:25:21 by cpieri            #+#    #+#             */
/*   Updated: 2018/09/15 10:55:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include "vector.h"

# define DEG2RAD 0.01745329251

class 	Matrix3d
{
	protected:
		Vector3d 	fwd;
		Vector3d 	up;
		Vector3d 	rgt;

	public:
		Matrix3d(double x, double y, double z);
		~Matrix3d(void) const;
		double		matrix_det(Matrix3d mat);
		void		identity_mat(Matrix3d *mat);
		void		rotate_x(Matrix3d* mat, double a);
		void		rotate_y(Matrix3d* mat, double a);
		void		rotate_z(Matrix3d* mat, double a);
		Matrix3d	matrix_mult(Matrix3d m1, Matrix3d m2);
		Matrix3d	matrix_inv(Matrix3d mat);
		Vector3d	adjust_direction(Vector3d src, Matrix3d mat);
};

#endif
