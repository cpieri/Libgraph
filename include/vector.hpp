/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:03:51 by cpieri            #+#    #+#             */
/*   Updated: 2018/12/22 18:35:07 by delay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

/*
   t_vector3d		vector_op(t_vector3d a, t_vector3d b, char type);
   t_vector2d		vector_op_2d(t_vector2d a, t_vector2d b, char type);
   t_vector3d		find_normal_vect(t_vector3d u);
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
		double	distance(Vector3d b) const;
		void	set_value(double x, double y, double z);
		void	set_unicoord_value(double value);
		void	normalize(void);
		void	lambda_product(double const lambda);
		void	vectorial_prod(Vector3d b);
		void	find_normal(void);
};

class	Vector2d
{
	private:
		double	_x;
		double	_y;

	public:
		Vector2d(double x, double y);
		~Vector2d(void);

		double	get_x(void) const;
		double	get_y(void) const;
		double	dotprod(Vector2d b) const;
		double	distance(Vector2d b) const;
		void	set_value(double x, double y);
		void	set_unicoord_value(double value);
		void	lambda_product(double lambda);
};

class	Vector4d
{
	private:
		double	_x;
		double	_y;
		double	_z;
		double	_w;

	public:
		Vector4d(double x, double y, double z, double w);
		~Vector4d(void);

		double	get_x(void) const;
		double	get_y(void) const;
		double	get_z(void) const;
		double	get_w(void) const;
		void	set_value(double x, double y, double z, double w);
		void	set_unicoord_value(double value);
};

Vector3d	vector_op(Vector3d a, Vector3d b, char type);
Vector2d	vector_op_2d(Vector2d a, Vector2d b, char type);

#endif
