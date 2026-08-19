/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:29:06 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/19 18:03:51 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vec3.hpp"
#include <cmath>

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(float scalar) const {

	return Vec3(x + scalar, y + scalar, z + scalar);

}

Vec3 Vec3::operator+(const Vec3& other) const {

	return Vec3(x + other.x, y + other.y, z + other.z);

}

Vec3 Vec3::operator-(const Vec3& other) const {

	return Vec3(x - other.x, y - other.y, z - other.z);

}

Vec3 Vec3::operator-() const {

	return Vec3(-x, -y, -z);

}

float Vec3::length() const {

	return std::sqrt((x * x) + (y * y) + (z * z));

}

float Vec3::dot(const Vec3 &other) const {

	return x * other.x + y * other.y + z * other.z;

}

Vec3 Vec3::cross(const Vec3 &other) const {

	return Vec3(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	);

}

Vec3 Vec3::normalize() const {

    float len = length();
    return Vec3(x / len, y / len, z / len);

}

std::ostream &operator<<(std::ostream &os, const Vec3 &v) {

	os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	return os;

}
