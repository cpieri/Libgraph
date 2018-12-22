/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:40:36 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/20 07:06:42 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	Matrix::matrix_det(void)
{
	double	res;

	res = 0;
	res += this->rgt.x * this->up.y * this->fwd.z;
	res += this->up.x * this->fwd.y * this->rgt.z;
	res += this->fwd.x * this->rgt.y * this->up.z;
	res -= this->rgt.x * this->fwd.y * this->up.z;
	res -= this->fwd.x * this->up.y * this->rgt.z;
	res -= this->up.x * this->rgt.y * this->fwd.z;
	return (res);
}

static t_vector3d	build_row(t_vector3d src, t_mat3d add)
{
	double	a;
	double	b;
	double	c;

	a = (src.x * add.rgt.x) + (src.y * add.up.x) + (src.z * add.fwd.x);
	b = (src.x * add.rgt.y) + (src.y * add.up.y) + (src.z * add.fwd.y);
	c = (src.x * add.rgt.z) + (src.y * add.up.z) + (src.z * add.fwd.z);
	return (new_vector_3d(a, b, c));
}

t_mat3d				matrix_mult(t_mat3d m1, t_mat3d m2)
{
	t_mat3d	ret;

	ret.rgt = build_row(m1.rgt, m2);
	ret.up = build_row(m1.up, m2);
	ret.fwd = build_row(m1.fwd, m2);
	return (ret);
}

t_vector3d			adjust_direction(t_vector3d src, t_mat3d mat)
{
	t_vector3d	ret;

	ret.x = mat.rgt.x * src.x + mat.rgt.y * src.y + mat.rgt.z * src.z;
	ret.y = mat.up.x * src.x + mat.up.y * src.y + mat.up.z * src.z;
	ret.z = mat.fwd.x * src.x + mat.fwd.y * src.y + mat.fwd.z * src.z;
	return (ret);
}

Matrix::Matrix(double x, double y, double z)
{
	t_mat3d	ret;
	t_mat3d	tmp;

	identity_mat(&ret);
	rotate_x(&tmp, x);
	if (x)
		ret = matrix_mult(ret, tmp);
	rotate_y(&tmp, y);
	if (y)
		ret = matrix_mult(ret, tmp);
	rotate_z(&tmp, z);
	if (z)
		ret = matrix_mult(ret, tmp);
	return (ret);
}
