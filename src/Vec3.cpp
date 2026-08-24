/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:29:06 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 12:34:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec3.hpp"
#include <cmath>

namespace math
{
    float dot(const Vec3& a, const Vec3& b)
    {
        return a.x * b.x
             + a.y * b.y
             + a.z * b.z;
    }

    Vec3 cross(const Vec3& a, const Vec3& b)
    {
        return Vec3{
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        };
    }

    float length(const Vec3& v)
    {
        return std::sqrt(dot(v, v));
    }

    Vec3 normalize(const Vec3& v)
    {
        float len = length(v);

        return Vec3{v.x / len, v.y / len, v.z / len};
    }

    Vec3 operator+(const Vec3& a, const Vec3& b)
    {
        return Vec3{a.x + b.x, a.y + b.y, a.z + b.z};
    }

    Vec3 operator+(const Vec3& v, float scalar)
    {
        return Vec3{v.x + scalar, v.y + scalar, v.z + scalar};
    }

    Vec3 operator-(const Vec3& a, const Vec3& b)
    {
        return Vec3{a.x - b.x, a.y - b.y, a.z - b.z};
    }

    Vec3 operator-(const Vec3& v)
    {
        return Vec3{-v.x, -v.y, -v.z};
    }

    std::ostream& operator<<(std::ostream& os, const Vec3& v)
    {
        os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";

        return os;
    }
}
