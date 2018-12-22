/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:25:21 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/19 18:52:28 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include "vector.h"

# define DEG2RAD 0.01745329251

typedef struct	s_mat3d
{
	t_vector3d	fwd;
	t_vector3d	up;
	t_vector3d	rgt;
}				t_mat3d;

t_mat3d			matrix_mult(t_mat3d m1, t_mat3d m2);
t_mat3d			matrix_inv(t_mat3d mat);
t_mat3d			new_matrix(double x, double y, double z);
t_vector3d		adjust_direction(t_vector3d src, t_mat3d mat);
void			identity_mat(t_mat3d *mat);
void			rotate_x(t_mat3d *mat, double a);
void			rotate_y(t_mat3d *mat, double a);
void			rotate_z(t_mat3d *mat, double a);

class Matrix
{
	private:
		Vector3d	_fwd;
		Vector3d	_up;
		Vector3d	_rgt;

	public:
		Matrix(double x, double y, double z);
		~Matrix(void);

		void	rotate_x(double a);
		void	rotate_y(double a);
		void	rotate_z(double a);
		void	identity(void);
		double	det(void);
};


#endif
