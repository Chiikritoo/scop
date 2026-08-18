# Devlog

Dated notes on what got done and why, as it happens.

## 2026-08-17

Wired GLFW and a vendored GLAD loader (GL 3.3 core) into the Makefile.
Needed now — next up is actually opening a window.

First window open. Wrapped it in a `Window` class instead of leaving it
procedural in `main.cpp` — constructor does init/create/load, destructor
tears it down, so there's no path where cleanup gets skipped.

Wrote a minimal `Shader` class (RAII): reads GLSL source from disk,
compiles vertex and fragment shaders, links them into a program, throws
on any compile/link failure instead of leaving a half-built object
around. Wired it into `main.cpp` alongside a hardcoded triangle
(VAO/VBO) to validate the whole pipeline end to end — first pixels on
screen.

## 2026-08-18

Went back over the LearnOpenGL "Hello Triangle" and "Shaders" chapters
— the basics weren't solid enough after the first pass, so spent the
day re-doing the fundamentals properly instead of building on top of a
shaky understanding.

Extended the triangle with a per-vertex color attribute: `aColor`
alongside `aPos` in the VBO, interleaved (`pos, color, pos, color, …`)
rather than in two separate buffers, to get comfortable with
`glVertexAttribPointer`'s stride/offset arguments. Updated
`basic.vert`/`basic.frag` to pass the color through as an `out`/`in`
`vec3` (`ourColor`) — first real use of GLSL's shader-to-shader
interface instead of a hardcoded fragment color.

Left commented-out snippets in `main.cpp` (EBO/indices, wireframe
mode, uniform-driven color animation via `glfwGetTime`) as scratch
notes while working through the tutorial's variations — to be cleaned
up once the next chapter's actual code lands.
