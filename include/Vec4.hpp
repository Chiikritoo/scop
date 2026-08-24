/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec4.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:03:30 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/24 12:28:43 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_HPP
# define VEC4_HPP

# include <ostream>

namespace math
{
    struct Vec4
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float w = 0.0f;
    };

    float dot(const Vec4& a, const Vec4& b);

    std::ostream& operator<<(std::ostream& os, const Vec4& v);
}

#endif
