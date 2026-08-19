/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/19 18:35:30 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_HPP
# define MAT4_HPP

#include "Vec3.hpp"
# include <ostream>

class Mat4 {

	public:
		float _m[4][4];

		Mat4();

		Mat4	operator*(const Mat4 &other) const;
		static Mat4	scale(const Mat4& m, const Vec3& s);
		static Mat4	translate(const Mat4& m, const Vec3& s);
		static Mat4 rotateZ(const Mat4 &m, float angleRad);
		static Mat4 rotateX(const Mat4 &m, float angleRad);
		static Mat4 perspective(float fovyRad, float aspect, float near, float far);
		static Mat4 lookAt(const Vec3 &eye, const Vec3 &target, const Vec3 &up);

};

std::ostream& operator<<(std::ostream& os, const Mat4& v);

#endif
