/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchikri <anchikri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:26:48 by anchikri          #+#    #+#             */
/*   Updated: 2026/08/17 19:27:07 by anchikri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "scop.hpp"

class Window
{
	public:
		Window(int width, int height, const char *title);
		~Window();

		Window(const Window &other) = delete;
		Window &operator=(const Window &other) = delete;

		bool	shouldClose() const;
		void	pollEvents() const;
		void	swapBuffers() const;
		GLFWwindow	*getWindow() const;

	private:
		GLFWwindow	*_window;
};

#endif
