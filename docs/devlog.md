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

## 2026-08-19

Kept following LearnOpenGL past the mandatory chapters — Textures,
Transformations, Coordinate Systems, Camera — skipping a couple of
sections that didn't seem worth the detour right now. The math side
was rough. I know vectors and matrices in the abstract, but stacking
that on top of writing our own `Vec3`/`Mat4` from scratch (no glm
allowed anyway) made everything feel less like "apply a formula" and
more like "figure out what this formula is even for." Worked through
it with Claude's help, function by function, which suits how I learn
better than reading the whole theory first before writing a line.

`Vec3` and `Mat4` now exist for real: dot/cross/normalize on the
vector side, scale/translate/rotate plus `perspective` and `lookAt`
on the matrix side.

Textures came next — `stb_image.h` vendored in, `container.jpg`
loaded and bound as a `sampler2D`, UVs replacing the old per-vertex
color in the shaders.

Then the cube: swapped the triangle for 36 hardcoded vertices, wired
`model`/`view`/`projection` uniforms, turned on depth testing so it
doesn't render inside-out, and hooked `lookAt` to `glfwGetTime()` for
a camera that orbits the object instead of a static view. First time
something spins in 3D on screen instead of sitting flat — genuinely
happy with that one.

Coordinate systems, the camera basis, and homogeneous coordinates
are still shaky in my head though — none of it feels actually
acquired yet, more like it worked this time. I'll need to go back
over this math regularly, not just once, before it really sticks.

## 2026-08-24

Same instinct as the OpenGL detour a few days back, but for the math
side this time — I wanted to actually understand the mechanics instead
of having something that just works. Took each notion apart one at a
time. `lookAt` is still a bit fuzzy honestly, but the rest is clearer
than last time.

Refactored `Vec3`, `Vec4`, and `Mat4` for consistency: everything lives
in `namespace math` now, plain structs with public members instead of
classes with constructors, and every operation (`dot`, `cross`,
`normalize`, matrix multiplication) is a free function instead of a
method. Matrix transforms are also split into pure factories
(`identity`, `translation`, `scaling`, `rotationX`/`Y`/`Z`,
`perspective`) composed explicitly with `operator*`, instead of
functions that build and apply in one call. `main.cpp` got readapted to
match.

Still the same spinning cube at the end of the day — or rather, the
camera orbiting around it, `lookAt` does the same job as before, just
cleaner underneath now. Wondering if a `Camera` class is worth it next,
haven't decided yet.
