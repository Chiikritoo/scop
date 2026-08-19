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
- `Vec3` and `Mat4` classes (`include/`, `src/`): our own vector/matrix
  math, hand-rolled per the subject's constraints. `Vec3` covers
  add/sub/negate/dot/cross/normalize/length; `Mat4` covers
  scale/translate/rotateX/rotateZ, matrix multiplication, and the two
  camera-facing builders, `perspective` and `lookAt`.
- Vendored `stb_image.h` (`vendor/stb/`, header-only) for texture
  loading, alongside the existing vendored GLAD loader; Makefile
  updated with a matching `-I` include path.
- Texture support: `shaders/basic.vert`/`basic.frag` now carry a `vec2`
  UV attribute and sample a `sampler2D` instead of interpolating a flat
  vertex color; `main.cpp` loads `container.jpg` via `stb_image` and
  uploads it as a 2D texture.
- `main.cpp` now draws a textured cube (36 hardcoded vertices) instead
  of the flat triangle, driven by `model`/`view`/`projection` matrix
  uniforms built with `Mat4`.
- A simple orbiting camera: `view` is rebuilt every frame via
  `Mat4::lookAt`, with the eye position swept around the origin using
  `sin`/`cos` of `glfwGetTime()` — first moving/rotating 3D scene.
- `glEnable(GL_DEPTH_TEST)` so the cube's faces occlude correctly.

### Changed
- `shaders/basic.vert`/`basic.frag`: dropped the per-vertex color
  attribute in favor of texture coordinates; vertex shader now
  transforms positions through `projection * view * model`.
