/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec4.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:07:28 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 12:29:02 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec4.hpp"

namespace math
{
    float dot(const Vec4& a, const Vec4& b)
    {
        return a.x * b.x
             + a.y * b.y
             + a.z * b.z
             + a.w * b.w;
    }

    std::ostream& operator<<(std::ostream& os, const Vec4& v)
    {
        os << "[ " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " ]";

        return os;
    }
}
