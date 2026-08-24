/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:08:36 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 15:53:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat4.hpp"
#include "Vec4.hpp"
#include <cmath>
#include <cstring>

namespace math
{
	Mat4 identity()
	{
		Mat4 result;

		result(0, 0) = 1.0f;
		result(1, 1) = 1.0f;
		result(2, 2) = 1.0f;
		result(3, 3) = 1.0f;

		return result;
	}

	Mat4 translation(const Vec3& t)
	{
		Mat4 result = identity();

		result(0, 3) = t.x;
		result(1, 3) = t.y;
		result(2, 3) = t.z;

		return result;
	}

	Mat4 translate(const Mat4& m, const Vec3& t)
	{
		return m * translation(t);
	}

	Mat4 scaling(const Vec3& s)
	{
		Mat4 result = identity();

		result(0, 0) = s.x;
		result(1, 1) = s.y;
		result(2, 2) = s.z;

		return result;
	}

	Mat4 scale(const Mat4& m, const Vec3& s)
	{
		return m * scaling(s);
	}

	Mat4 rotationX(float angleRad)
	{
		Mat4 result = identity();
		float c = std::cos(angleRad);
		float s = std::sin(angleRad);

		result(1, 1) = c;
		result(1, 2) = -s;
		result(2, 1) = s;
		result(2, 2) = c;

		return result;
	}

	Mat4 rotateX(const Mat4& m, float angleRad)
	{
		return m * rotationX(angleRad);
	}

	Mat4 rotationY(float angleRad)
	{
		Mat4 result = identity();
		float c = std::cos(angleRad);
		float s = std::sin(angleRad);

		result(0, 0) = c;
		result(0, 2) = s;
		result(2, 0) = -s;
		result(2, 2) = c;

		return result;
	}

	Mat4 rotateY(const Mat4& m, float angleRad)
	{
		return m * rotationY(angleRad);
	}

	Mat4 rotationZ(float angleRad)
	{
		Mat4 result = identity();
		float c = std::cos(angleRad);
		float s = std::sin(angleRad);

		result(0, 0) = c;
		result(0, 1) = -s;
		result(1, 0) = s;
		result(1, 1) = c;

		return result;
	}

	Mat4 rotateZ(const Mat4& m, float angleRad)
	{
		return m * rotationZ(angleRad);
	}

	Mat4 perspective(float fovyRad, float aspect, float near, float far)
	{
		Mat4 result;
		float f = 1.0f / std::tan(fovyRad / 2.0f);

		result(0, 0) = f / aspect;
		result(1, 1) = f;
		result(2, 2) = (far + near) / (near - far);
		result(2, 3) = (2.0f * far * near) / (near - far);
		result(3, 2) = -1.0f;

		return result;
	}

	Mat4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up)
	{
		Vec3 direction = normalize(eye - target);
		Vec3 right = normalize(cross(up, direction));
		Vec3 camUp = cross(direction, right);

		Mat4 rotation = identity();
		rotation(0, 0) = right.x;
		rotation(0, 1) = right.y;
		rotation(0, 2) = right.z;

		rotation(1, 0) = camUp.x;
		rotation(1, 1) = camUp.y;
		rotation(1, 2) = camUp.z;

		rotation(2, 0) = direction.x;
		rotation(2, 1) = direction.y;
		rotation(2, 2) = direction.z;

		return rotation * translation(-eye);
	}

	Mat4 operator*(const Mat4& a, const Mat4& b)
	{
		Mat4 result;

		for (std::size_t row = 0; row < 4; ++row)
		{
			for (std::size_t col = 0; col < 4; ++col)
			{
				Vec4 rowA{
					a(row, 0),
					a(row, 1),
					a(row, 2),
					a(row, 3)
				};

				Vec4 colB{
					b(0, col),
					b(1, col),
					b(2, col),
					b(3, col)
				};

				result(row, col) = dot(rowA, colB);
			}
		}

		return result;
	}

	Vec4 operator*(const Mat4& m, const Vec4& v)
	{
		Vec4 row0{
			m(0, 0),
			m(0, 1),
			m(0, 2),
			m(0, 3)
		};

		Vec4 row1{
			m(1, 0),
			m(1, 1),
			m(1, 2),
			m(1, 3)
		};

		Vec4 row2{
			m(2, 0),
			m(2, 1),
			m(2, 2),
			m(2, 3)
		};

		Vec4 row3{
			m(3, 0),
			m(3, 1),
			m(3, 2),
			m(3, 3)
		};

		return Vec4{dot(row0, v), dot(row1, v), dot(row2, v), dot(row3, v)};
	}
}
