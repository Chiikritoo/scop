/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mat4.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 12:53:16 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_HPP
# define MAT4_HPP

# include "Vec3.hpp"
# include "Vec4.hpp"
# include <ostream>
# include <array>

namespace math
{
    class Mat4
	{
		public:
			float& operator()(std::size_t row, std::size_t col)
			{
				return _data[col * 4 + row];
			}

			const float& operator()(std::size_t row, std::size_t col) const
			{
				return _data[col * 4 + row];
			}

			const float* data() const
			{
				return _data.data();
			}

		private:
			std::array<float, 16> _data{};
	};

	Mat4 identity();
	Mat4 translation(const Vec3& t);
	Mat4 translate(const Mat4& m, const Vec3& t);
	Mat4 scaling(const Vec3& s);
	Mat4 scale(const Mat4& m, const Vec3& s);
	Mat4 rotationX(float angleRad);
	Mat4 rotateX(const Mat4& m, float angleRad);
	Mat4 rotationY(float angleRad);
	Mat4 rotateY(const Mat4& m, float angleRad);
	Mat4 rotationZ(float angleRad);
	Mat4 rotateZ(const Mat4& m, float angleRad);
	Mat4 perspective(float fovyRad, float aspect, float near, float far);
	Mat4 lookAt(const Vec3& eye, const Vec3& target, const Vec3& up);
	Mat4 operator*(const Mat4& a, const Mat4& b);
	Vec4 operator*(const Mat4& m, const Vec4& v);
	std::ostream& operator<<(std::ostream& os, const Mat4& v);
}


#endif
