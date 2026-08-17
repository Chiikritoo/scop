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
