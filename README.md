# SCOP

42 school computer graphics mini-project: load a 3D object from an `.obj`
file and display it in perspective, spinning continuously on its central
axis, with per-face coloring and a texture toggled by keyboard.

Full subject: [scop.pdf](scop.pdf).

## Build

```sh
make        # compile
make re     # rebuild from scratch
make clean  # remove object files
make fclean # remove object files + binary
```

Dependencies: GLFW (via `pkg-config`), OpenGL. GLAD (OpenGL loader) is
vendored in `vendor/glad/`, no install needed.

## Run

```sh
./bin/scop
```

## Documentation

- [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md) — code organization
- [docs/devlog.md](docs/devlog.md) — dated notes on choices made and why
