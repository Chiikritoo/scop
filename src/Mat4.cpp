/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:08:36 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/19 18:36:19 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat4.hpp"
#include <cmath>
#include <cstring>

Mat4::Mat4() {

	std::memset(_m, 0, sizeof(_m));

	_m[0][0] = 1.0f;
	_m[1][1] = 1.0f;
	_m[2][2] = 1.0f;
	_m[3][3] = 1.0f;

}

Mat4 Mat4::operator*(const Mat4& other) const {

	Mat4 result;
	std::memset(result._m, 0, sizeof(result._m));

	for (int col = 0; col < 4; ++col) {

		for (int row = 0; row < 4; ++row) {

			float sum = 0.0f;
			for (int k = 0; k < 4; ++k)
				sum += _m[k][row] * other._m[col][k];

			result._m[col][row] = sum;

		}

	}

	return result;

}

Mat4 Mat4::scale(const Mat4& m, const Vec3& s) {

	Mat4 scaleMat;
	scaleMat._m[0][0] = s.x;
	scaleMat._m[1][1] = s.y;
	scaleMat._m[2][2] = s.z;
	return m * scaleMat;

}

Mat4 Mat4::translate(const Mat4& m, const Vec3& t)
{
    Mat4 trans;
    trans._m[3][0] = t.x;
    trans._m[3][1] = t.y;
    trans._m[3][2] = t.z;
    return m * trans;
}

Mat4 Mat4::rotateZ(const Mat4 &m, float angleRad)
{
    Mat4 rot;
    float c = std::cos(angleRad);
    float s = std::sin(angleRad);

    rot._m[0][0] = c;
    rot._m[0][1] = s;
    rot._m[1][0] = -s;
    rot._m[1][1] = c;

    return m * rot;
}

Mat4 Mat4::perspective(float fovyRad, float aspect, float near, float far)
{
    Mat4 m;
    std::memset(m._m, 0, sizeof(m._m));

    float f = 1.0f / std::tan(fovyRad / 2.0f); // controle le "zoom" du champ de vision

    m._m[0][0] = f / aspect; // met x a l'echelle selon largeur/hauteur ecran
    m._m[1][1] = f;          // met y a l'echelle
    m._m[2][2] = (far + near) / (near - far);       // mappe z vers [-1,1]
    m._m[2][3] = -1.0f;                              // celle qu'on vient de deriver : w = -z
    m._m[3][2] = (2.0f * far * near) / (near - far); // ajuste z en fonction de near/far

    return m;
}

Mat4 Mat4::rotateX(const Mat4 &m, float angleRad)
{
    Mat4 rot;
    float c = std::cos(angleRad);
    float s = std::sin(angleRad);
    rot._m[1][1] = c;
    rot._m[1][2] = s;
    rot._m[2][1] = -s;
    rot._m[2][2] = c;
    return m * rot;
}

Mat4 Mat4::lookAt(const Vec3 &eye, const Vec3 &target, const Vec3 &up)
{
    Vec3 direction = (eye - target).normalize();
    Vec3 right = up.cross(direction).normalize();
    Vec3 camUp = direction.cross(right);

    Mat4 rotation;
    rotation._m[0][0] = right.x;
    rotation._m[1][0] = right.y;
    rotation._m[2][0] = right.z;

    rotation._m[0][1] = camUp.x;
    rotation._m[1][1] = camUp.y;
    rotation._m[2][1] = camUp.z;

    rotation._m[0][2] = direction.x;
    rotation._m[1][2] = direction.y;
    rotation._m[2][2] = direction.z;

    Mat4 translation = Mat4::translate(Mat4(), -eye);

    return rotation * translation;
}

std::ostream&  operator<<(std::ostream& os, const Mat4& m) {

	for (int row = 0; row < 4; ++row) {

		os << "[ ";
		for (int col = 0; col < 4; ++col)
			os << m._m[col][row] << " ";
		os << "]\n";

	}

	return os;

}
