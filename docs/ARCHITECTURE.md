# Architecture

This document describes the code organization. Kept up to date as
implementation progresses, not written ahead of it.

## Layout

```
src/main.cpp           Entry point
src/Window.cpp          GLFW/GL window + context, RAII
include/scop.hpp       Project umbrella header
include/Window.hpp      Window class declaration
vendor/glad/            Vendored OpenGL loader (generated, not hand-written)
docs/                  Human-facing documentation
```

One file per class, named after the class. No subfolders yet — introduced
once there are enough classes to group by domain, not before.
