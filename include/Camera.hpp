/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 10:11:15 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/25 10:49:39 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
# define CAMERA_HPP

#include "Mat4.hpp"
#include "Vec3.hpp"

enum class CameraMovement
{
    Forward,
    Backward,
    Left,
    Right
};

class Camera {

	public:
		Camera(
			const math::Vec3& position,
			const math::Vec3& target,
			const math::Vec3& worldUp = math::Vec3{0.0f, 1.0f, 0.0f}
		);

		math::Mat4 viewMatrix() const;

		void	move(CameraMovement direction, float deltaTime);
		void	yaw(float offset);
		void	pitch(float offset);

	private:
		void	updateVectors();

		math::Vec3	_position;
		math::Vec3	_front;
		math::Vec3	_up;
		math::Vec3	_right;
		math::Vec3	_worldUp;
		float		_yaw;
		float		_pitch;
};

#endif
