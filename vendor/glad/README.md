# GLAD

Vendored OpenGL function loader, generated with [glad2](https://github.com/Dav1dde/glad).
Not written by hand — regenerate instead of editing.

## Regeneration

```sh
pip install glad2
python -m glad --api gl:core=3.3 --extensions "" --out-path <out_dir> c
```

Then copy `include/glad/gl.h`, `include/KHR/khrplatform.h` and `src/gl.c`
here, keeping this layout.

## Configuration

- API: OpenGL 3.3, core profile
- Extensions: none
- Language: C

License: see the header comment in `include/glad/gl.h`
(SPDX `(WTFPL OR CC0-1.0) AND Apache-2.0`).
