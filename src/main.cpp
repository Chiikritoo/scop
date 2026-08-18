/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:20 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/18 17:16:59 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.hpp"
#include "Window.hpp"
#include "Shader.hpp"
#include <cmath>

int main(void)
{
	try {
		Window  window(800, 600, "scop");
		Shader  shader("shaders/basic.vert", "shaders/basic.frag");

		// float vertices[] = {
		//  -0.5f, -0.5f, 0.0f,
		//  0.5f, -0.5f, 0.0f,
		//  0.0f,  0.5f, 0.0f
		// };

		float vertices[] = {
		// positions         // colors
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
				};

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

		// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		// glEnableVertexAttribArray(0);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
				// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
		glEnableVertexAttribArray(1);

		// unsigned int EBO;
		// glGenBuffers(1, &EBO);
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		while (!window.shouldClose()) {
			window.pollEvents();
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			// float timeValue = glfwGetTime();
			// float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
			// int vertexColorLocation = glGetUniformLocation(shader.getId(), "ourColor");
			// glUseProgram(shader.getId());
			// glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
			shader.use();
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			window.swapBuffers();
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}
