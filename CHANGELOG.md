# Changelog

All notable changes to this project are documented here.
Format based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

### Added
- Minimal build: Makefile compiling `src/` into `bin/scop`, C++17.
- GLFW (via `pkg-config`) and a vendored GLAD OpenGL 3.3 core loader
  (`vendor/glad/`) wired into the Makefile.
- Minimal `main.cpp` ("Hello world").
- Project documentation: README, `docs/ARCHITECTURE.md`, `docs/devlog.md`.
