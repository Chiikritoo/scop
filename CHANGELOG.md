# Changelog

All notable changes to this project are documented here.
Format based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

### Added
- Minimal build: Makefile compiling `src/` into `bin/scop`, C++17.
- GLFW (via `pkg-config`) and a vendored GLAD OpenGL 3.3 core loader
  (`vendor/glad/`) wired into the Makefile.
- `Window` class (RAII): opens a GLFW/OpenGL 3.3 core window, loads GL
  functions via GLAD, exposes `shouldClose`/`pollEvents`/`swapBuffers`.
- `main.cpp` opens a window and clears it to a solid color every frame.
- Project documentation: README, `docs/ARCHITECTURE.md`, `docs/devlog.md`.
