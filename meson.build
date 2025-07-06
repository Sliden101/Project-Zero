project(
  'Project-Zero',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

dependencies = [
  dependency('miniaudio'),
  dependency('GL'),
  dependency('X11'),
]

sources = [
  'audio.c',
  'boss.c',
  'bullet.c',
  'highscore.c',
  'main.c',
  'player.c',
  'screen.c',
  'tigr.c',
]

exe = executable(
  'Project-Zero',
  sources,
  dependencies : dependencies,
  install : true,
)

test('basic', exe)
