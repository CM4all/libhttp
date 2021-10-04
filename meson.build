project('libhttp', 'c', version: '1.3',
  meson_version: '>= 0.49',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ],
)

debug = get_option('b_ndebug') != 'true'

c_compiler = meson.get_compiler('c')

pkg_mod = import('pkgconfig')

common_flags = [
  '-D_REENTRANT', '-D_GNU_SOURCE',
]

test_common_flags = [
  '-Wwrite-strings', '-Wcast-qual', '-Wcast-align', '-Wfloat-equal',
  '-Wshadow',
  '-Wmissing-declarations', '-Wmissing-noreturn', '-Wmissing-format-attribute',
  '-Wredundant-decls', '-Wno-long-long', '-Wundef',
  '-Wunused',
]

test_cflags = test_common_flags + [
  '-Wmissing-prototypes', '-Wstrict-prototypes',
  '-Wbad-function-cast',
  '-Waggregate-return',
  '-Wredundant-decls', '-Wno-long-long', '-Wundef',
  '-Wnested-externs',
]

add_global_arguments(common_flags, language: 'c')
add_project_arguments(c_compiler.get_supported_arguments(test_cflags), language: 'c')

inc = include_directories('include')

libhttp = static_library(
  'cm4all-http',
  'src/method.c',
  'src/status.c',
  'src/header.c',
  include_directories: inc,
  install: true,
)

pkg_mod.generate(
  libhttp,
  version: meson.project_version(),
  name: 'libcm4all-http',
  description: 'CM4all HTTP library',
  install_dir: join_paths(get_option('datadir'), 'pkgconfig')
)

install_headers(
  'include/http/method.h',
  'include/http/status.h',
  'include/http/header.h',
  subdir: 'http')