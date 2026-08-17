/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 23:50:00 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/17 23:45:14 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shader.hpp"
#include <fstream>
#include <sstream>

std::string	Shader::readFile(const char *path) const
{
	std::ifstream	file(path);

	if (!file.is_open())
		throw std::runtime_error(std::string("failed to open shader file: ") + path);

	std::stringstream	buffer;
	buffer << file.rdbuf();
	return (buffer.str());
}

unsigned int	Shader::compile(const char *path, GLenum type) const
{
	std::string	source = readFile(path);
	const char	*src = source.c_str();

	unsigned int	shader = glCreateShader(type);
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	int		success;
	char	infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		glDeleteShader(shader);
		throw std::runtime_error(std::string("shader compile error (") + path + "): " + infoLog);
	}

	return (shader);
}

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
	unsigned int	vertexShader = compile(vertexPath, GL_VERTEX_SHADER);
	unsigned int	fragmentShader = compile(fragmentPath, GL_FRAGMENT_SHADER);

	_id = glCreateProgram();
	glAttachShader(_id, vertexShader);
	glAttachShader(_id, fragmentShader);
	glLinkProgram(_id);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	int		success;
	char	infoLog[512];
	glGetProgramiv(_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(_id, 512, nullptr, infoLog);
		glDeleteProgram(_id);
		throw std::runtime_error(std::string("shader program link error: ") + infoLog);
	}
}

Shader::~Shader()
{
	glDeleteProgram(_id);
}

void	Shader::use() const
{
	glUseProgram(_id);
}

unsigned int	Shader::getId() const
{
	return (_id);
}
