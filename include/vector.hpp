/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:03:51 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/22 16:05:45 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

/*
   typedef struct	s_vector4d
   {
   double		x;
   double		y;
   double		z;
   double		w;
   }				t_vector4d;

   typedef struct	s_vector2d
   {
   double		x;
   double		y;
   }				t_vector2d;

   t_vector4d		new_vector_4d(double x, double y, double z, double w);
   t_vector2d		new_vector_2d(double x, double y);
   t_vector3d		cross(t_vector3d a, t_vector3d b);
   t_vector3d		vector_op(t_vector3d a, t_vector3d b, char type);
   t_vector2d		vector_op_2d(t_vector2d a, t_vector2d b, char type);
   t_vector3d		vectorial_prod(t_vector3d a, t_vector3d b);
   t_vector3d		find_normal_vect(t_vector3d u);
   t_vector2d		lambda_product_d2(double lambda, t_vector2d vector);
   double			dotprod_2d(t_vector2d a, t_vector2d b);
   double			distance_d3(t_vector3d a, t_vector3d b);
 */

class	Vector3d
{
	private:
		double	_x;
		double	_y;
		double	_z;

	public:
		Vector3d(double x, double y, double z);
		~Vector3d(void);

		double	get_x(void) const;
		double	get_y(void) const;
		double	get_z(void) const;
		double	get_length(void) const;
		double	dotprod(Vector3d b) const;
		void	set_value(double x, double y, double z);
		void	set_unicoord_value(double value);
		void	normalize(void);
		void	lamda_product(double const lambda);
}

#endif
