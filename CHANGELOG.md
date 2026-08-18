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
- `Shader` class (RAII): compiles GLSL vertex/fragment shaders from disk
  and links them into a program, throwing on failure.
- `shaders/basic.vert` / `shaders/basic.frag`: minimal pass-through
  shaders (flat orange fragment color).
- `main.cpp` now uploads a hardcoded triangle via VAO/VBO and draws it
  each frame using the `Shader` class — first visible render output.

### Changed
- `shaders/basic.vert` / `shaders/basic.frag`: added a second vertex
  attribute (`aColor`) passed through as `ourColor` from vertex to
  fragment shader, replacing the hardcoded flat color.
- `main.cpp`: interleaved vertex data (position + color) in a single
  VBO, with two `glVertexAttribPointer` calls (stride/offset) instead
  of one — revisiting the LearnOpenGL "Hello Triangle" / "Shaders"
  chapters to nail down attribute layout and GLSL in/out passing,
  which weren't solid on the first pass.
