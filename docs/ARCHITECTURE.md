# Architecture

This document describes the code organization. Kept up to date as
implementation progresses, not written ahead of it.

## Layout

```
src/main.cpp          Entry point
include/scop.hpp      Project umbrella header
vendor/glad/           Vendored OpenGL loader (generated, not hand-written)
docs/                 Human-facing documentation
```
