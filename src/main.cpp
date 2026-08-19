/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:20 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/19 18:44:27 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mat4.hpp"
#include "Vec3.hpp"
#include "scop.hpp"
#include "Window.hpp"
#include "Shader.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <cmath>

float toRadians(float degrees)
{
    return degrees * (M_PI / 180.0f);
}

int main(void)
{
	// Vec3 v1(1.0, 1.0, 0.0);
	// Vec3 v2(8.0, 4.0, 0.0);

	// std::cout << "v1 = " << v1 << std::endl;
	// std::cout << "v2 = " << v2 << std::endl;
	// std::cout << "v1 + 1 = " << v1 + 1 << std::endl;
	// std::cout << "-v1 = " << -v1 << std::endl;
	// std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
	// std::cout << "v1 - v2 = " << v1 - v2 << std::endl;
	// std::cout << "length(v1) = " << v1.length() << std::endl;
	// std::cout << "length(v2) = " << v2.length() << std::endl;
	// std::cout << "v1 . v2 = " << v1.dot(v2) << std::endl;
	// std::cout << "v1 * v2 = " << v1.cross(v2) << std::endl;

	// Mat4 m;
	// std::cout << "m.scale(v1) = " << m.scale(m, v1) << std::endl;
	// std::cout << "m.translate(v1) = " << m.translate(m, v1) << std::endl;
	// std::cout << "m = " << m << std::endl;
	// m = Mat4::rotateZ(m, toRadians(90.0f));
	// std::cout << "m after rotation = " << m << std::endl;
	try {
		Window  window(800, 600, "scop");
		Shader  shader("shaders/basic.vert", "shaders/basic.frag");

		// float vertices[] = {
		//  -0.5f, -0.5f, 0.0f,
		//  0.5f, -0.5f, 0.0f,
		//  0.0f,  0.5f, 0.0f
		// };

		// float texCoords[] = {
		// 	0.0f, 0.0f,  // lower-left corner
		// 	1.0f, 0.0f,  // lower-right corner
		// 	0.5f, 1.0f   // top-center corner
		// };

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		int width, height, nrChannels;
		unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		stbi_image_free(data);

		float vertices[] = {
			// back face
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			// front face
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			// left face
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			// right face
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			// bottom face
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			// top face
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		// float vertices[] = {
		// 	// positions          // colors           // texture coords
		// 	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		// 	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		// 	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		// 	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
		// };

		// float vertices[] = {
		// // positions         // colors
		// 	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		// 	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		// 	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
		// };

		// float vertices[] = {
		//  0.5f,  0.5f, 0.0f,  // top right
		//  0.5f, -0.5f, 0.0f,  // bottom right
		//  -0.5f, -0.5f, 0.0f,  // bottom left
		//  -0.5f,  0.5f, 0.0f   // top left
		// };
		// unsigned int indices[] = {  // note that we start from 0!
		//  0, 1, 3,   // first triangle
		//  1, 2, 3    // second triangle
		// };

		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		// glEnableVertexAttribArray(0);

		// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		// glEnableVertexAttribArray(1);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		unsigned int indices[] = {
			0, 1, 3,
			1, 2, 3
		};

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


		// unsigned int transformLoc = glGetUniformLocation(shader.getId(), "transform");
		unsigned int transformLoc = glGetUniformLocation(shader.getId(), "transform");
		shader.use();
		Mat4 identity;
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &identity._m[0][0]);


		Mat4 model;
		model = Mat4::rotateX(model, toRadians(-55.0f));

		Mat4 projection = Mat4::perspective(toRadians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shader.getId(), "model");
		int viewLoc = glGetUniformLocation(shader.getId(), "view");
		int projLoc = glGetUniformLocation(shader.getId(), "projection");

		shader.use();
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model._m[0][0]);
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projection._m[0][0]);
		glEnable(GL_DEPTH_TEST);

		while (!window.shouldClose()) {
			window.pollEvents();
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			shader.use();

			float radius = 10.0f;
			float camX = std::sin((float)glfwGetTime()) * radius;
			float camZ = std::cos((float)glfwGetTime()) * radius;
			Mat4 view = Mat4::lookAt(Vec3(camX, 0.0f, camZ), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view._m[0][0]);

			glBindVertexArray(VAO);
			glBindTexture(GL_TEXTURE_2D, texture);
			// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			window.swapBuffers();
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
