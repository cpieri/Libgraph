/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:31:44 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/20 07:06:45 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	Matrix::identity()
{
	this->rgt = new_vector_3d(1, 0, 0);
	this->up = new_vector_3d(0, 1, 0);
	this->fwd = new_vector_3d(0, 0, 1);
}

void	Matrix::rotate_x(double a)
{
	a *= DEG2RAD;
	this->rgt = new_vector_3d(1, 0, 0);
	this->up = new_vector_3d(0, cos(a), -sin(a));
	this->fwd = new_vector_3d(0, sin(a), cos(a));
}

void	Matrix::rotate_y(double a)
{
	a *= DEG2RAD;
	this->rgt = new_vector_3d(cos(a), 0, sin(a));
	this->up = new_vector_3d(0, 1, 0);
	this->fwd = new_vector_3d(-sin(a), 0, cos(a));
}

void	Matrix::rotate_z(double a)
{
	a *= DEG2RAD;
	this->rgt = new_vector_3d(cos(a), -sin(a), 0);
	this->up = new_vector_3d(sin(a), cos(a), 0);
	this->fwd = new_vector_3d(0, 0, 1);
}

Matrix	matrix_inv(Matrix mat)
{
	Matrix	ret;
	double	det;

	det = mat.det();
	if (det != 0)
	{
		ret.rgt = new_vector_3d((mat.up.y * mat.fwd.z)
				- (mat.up.z * mat.fwd.y), (mat.rgt.z * mat.fwd.y)
				- (mat.rgt.y * mat.fwd.z), (mat.rgt.y * mat.up.z)
				- (mat.rgt.z * mat.up.y));
		ret.up = new_vector_3d((mat.up.z * mat.fwd.x)
				- (mat.up.x * mat.fwd.z), (mat.rgt.x * mat.fwd.z)
				- (mat.rgt.z * mat.fwd.x), (mat.rgt.z * mat.up.x)
				- (mat.rgt.x * mat.up.z));
		ret.fwd = new_vector_3d((mat.up.x * mat.fwd.y)
				- (mat.up.y * mat.fwd.x), (mat.rgt.y * mat.fwd.x)
				- (mat.rgt.x * mat.fwd.y), (mat.rgt.x * mat.up.y)
				- (mat.rgt.y * mat.up.x));
		ret.rgt = vector_op(ret.rgt, new_vector_3d_unicoord(1.0 / det), '*');
		ret.up = vector_op(ret.up, new_vector_3d_unicoord(1.0 / det), '*');
		ret.fwd = vector_op(ret.fwd, new_vector_3d_unicoord(1.0 / det), '*');
		return (ret);
	}
	return (mat);
}
