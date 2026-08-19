/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/19 18:03:55 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_HPP
# define VEC3_HPP

# include "scop.hpp"
# include <ostream>
# include <string>

class Vec3 {

	public:
		float x, y, z;

		Vec3();
		Vec3(float x, float y, float z);

		Vec3	operator+(float scalar) const;
		Vec3	operator+(const Vec3& other) const;
		Vec3	operator-() const;
		Vec3	operator-(const Vec3& other) const;
		float	length() const;
		float	dot(const Vec3 &other) const;
		Vec3	cross(const Vec3 &other) const;
		Vec3	normalize() const;


};

std::ostream& operator<<(std::ostream& os, const Vec3& v);

#endif
