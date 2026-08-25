/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 10:16:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/25 10:36:11 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"
#include <cmath>

Camera::Camera(
			const math::Vec3& position,
			const math::Vec3& target,
			const math::Vec3& worldUp
		)
		: _position(position)
		, _worldUp(worldUp)
{

	math::Vec3 direction = math::normalize(target - position);
	_pitch = std::asin(direction.y);
	_yaw   = std::atan2(direction.z, direction.x);

	updateVectors();

}

math::Mat4 Camera::viewMatrix() const {
    return math::lookAt(_position, _position + _front, _up);
}

void Camera::updateVectors() {

	math::Vec3 front;
	front.x = std::cos(_yaw) * std::cos(_pitch);
	front.y = std::sin(_pitch);
	front.z = std::sin(_yaw) * std::cos(_pitch);

	_front = math::normalize(front);
	_right = math::normalize(math::cross(_front, _worldUp));
	_up    = math::cross(_right, _front);

}

void Camera::yaw(float offset) {

	_yaw += offset;
	updateVectors();

}

void Camera::pitch(float offset) {

	const float limit = 89.0f * (M_PI / 180.0f);

	_pitch += offset;
	if (_pitch > limit)
		_pitch = limit;
	if (_pitch < -limit)
		_pitch = -limit;

	updateVectors();

}

void Camera::move(CameraMovement direction, float deltaTime) {

	const float speed = 5.0f * deltaTime;
	if (direction == CameraMovement::Forward)
		_position += _front * speed;
	if (direction == CameraMovement::Backward)
		_position -= _front * speed;
	if (direction == CameraMovement::Left)
		_position -= _right * speed;
	if (direction == CameraMovement::Right)
		_position += _right * speed;
}
