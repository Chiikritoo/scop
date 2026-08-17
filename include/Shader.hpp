/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/17 23:44:44 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_HPP
# define SHADER_HPP

# include "scop.hpp"
# include <string>

class Shader
{
	public:
		Shader(const char *vertexPath, const char *fragmentPath);
		~Shader();

		Shader(const Shader &other) = delete;
		Shader &operator=(const Shader &other) = delete;

		void    use() const;
		unsigned int    getId() const;

	private:
		unsigned int    _id;

		std::string     readFile(const char *path) const;
		unsigned int    compile(const char *path, GLenum type) const;
};

#endif
