/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 12:34:05 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_HPP
# define VEC3_HPP

# include <ostream>

namespace math
{
    struct Vec3
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
    };

    float dot(const Vec3& a, const Vec3& b);
    Vec3 cross(const Vec3& a, const Vec3& b);
    float length(const Vec3& v);
    Vec3 normalize(const Vec3& v);

    Vec3 operator+(const Vec3& a, const Vec3& b);
    Vec3 operator+(const Vec3& v, float scalar);
    Vec3 operator-(const Vec3& a, const Vec3& b);
    Vec3 operator-(const Vec3& v);

    std::ostream& operator<<(std::ostream& os, const Vec3& v);
}

#endif
