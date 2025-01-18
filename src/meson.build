# C sources
math_c = py.extension_module(
    'math_c',
    ['math_c_ext.c', 'math_c_impl.c'],
    install: true,
    subdir: mod_name,
)

# Pure Python sources
python_sources = files(
    '__init__.py',
    'math_py.py',
)
py.install_sources(python_sources, subdir: mod_name)
