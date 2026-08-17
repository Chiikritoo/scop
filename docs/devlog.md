# Devlog

Dated notes on what got done and why, as it happens.

## 2026-08-17

Wired GLFW and a vendored GLAD loader (GL 3.3 core) into the Makefile.
Needed now — next up is actually opening a window.

First window open. Wrapped it in a `Window` class instead of leaving it
procedural in `main.cpp` — constructor does init/create/load, destructor
tears it down, so there's no path where cleanup gets skipped.
