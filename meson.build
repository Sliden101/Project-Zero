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

datadir = get_option('prefix') / get_option('datadir') / 'project_zero'
assetdir = datadir / 'assets'
highscoredir = get_option('prefix') / get_option('localstatedir') / 'project_zero'
highscorefile = highscoredir / 'high_score.txt'

exe = executable(
  'Project-Zero',
  sources,
  dependencies : dependencies,
  c_args : [
    '-DASSET_DIR="@0@"'.format(assetdir),
    '-DHIGH_SCORE_FILE="@0@"'.format(highscorefile)
  ],
  install : true,
)

install_subdir('assets', install_dir: datadir)

install_data('high_score.txt', install_dir: highscoredir)
