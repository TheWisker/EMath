project('Emath++', 'cpp', version : '2.2.0')

emath_include = ['./include/', './third_party/CSet/include/', './third_party/eigen/']
emath_headers = ['./include/emath.h', './third_party/CSet/include/set.h']
eparser_headers = ['./include/eparser.h']
emath_files = [emath_headers, './src/emath.cpp']
eparser_files = [eparser_headers, './src/eparser.cpp', emath_files]
interface_files = ['./src/interface.cpp', emath_files, eparser_files]

emath_test_files = ['./test/emath.cpp', emath_files]
eparser_test_files = ['./test/eparser.cpp', eparser_files]

interface_include = [emath_include, './third_party/rapidjson/include/', './third_party/rapidjson/include/rapidjson/', './third_party/SFML/', './third_party/SFML/include/', './third_party/SFML/include/SFML/', './third_party/SFML/include/SFML/Graphics/', './third_party/SFML/include/SFML/Window/', './third_party/SFML/include/SFML/System/']

# Determine the system that is being built on
if host_machine.system() in ['windows', 'mingw']
    message('Windows machine detected, thus building for windows!')
    shared_ext = 'dll'
    static_ext = 'lib'
    exe_ext = 'exe'
    add_project_arguments('-DWINDOWS', '-DSFML_STATIC', language : 'cpp')
    dynamic_interface_dependencies = [declare_dependency(
        link_args : [meson.current_source_dir() + '/third_party/PDCurses/wincon/pdcurses.a', '-Wl,--no-whole-archive', '-dynamic'],
        include_directories : ['./third_party/PDCurses/', './third_party/PDCurses/wincon', './third_party/PDCurses/pdcurses']
    ), declare_dependency(
        link_args : ['-DSFML_GRAPHICS_OPENGL', '-DSFML_SYSTEM_WINDOWS', '-L/usr/x86_64-w64-mingw32/lib/', '-L' + meson.current_source_dir() + '/third_party/SFML/lib/', '-lopengl32', '-lwinmm', '-lglfw3', '-lgdi32', meson.current_source_dir() + '/third_party/SFML/lib/libfreetype.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-graphics.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-window.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-system.a', '-dynamic'],
        include_directories : ['./third_party/SFML/', './third_party/SFML/include/', './third_party/SFML/include/SFML/']
    )]
    static_interface_dependencies = [declare_dependency(
        link_args : [meson.current_source_dir() + '/third_party/PDCurses/wincon/pdcurses.a', '-Wl,--no-whole-archive', '-static'],
        include_directories : ['./third_party/PDCurses/', './third_party/PDCurses/wincon', './third_party/PDCurses/pdcurses']
    ), declare_dependency(
        link_args : ['-DSFML_STATIC', '-DSFML_GRAPHICS_OPENGL', '-DSFML_SYSTEM_WINDOWS', '-L/usr/x86_64-w64-mingw32/lib/', '-L' + meson.current_source_dir() + '/third_party/SFML/lib/', '-lopengl32', '-lwinmm', '-lglfw3', '-lgdi32', meson.current_source_dir() + '/third_party/SFML/lib/libfreetype.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-graphics-s.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-window-s.a', meson.current_source_dir() + '/third_party/SFML/lib/libsfml-system-s.a', '-static'],
        include_directories : ['./third_party/SFML/', './third_party/SFML/include/', './third_party/SFML/include/SFML/']
    )]
else
    message('Linux machine detected, thus building for linux!')
    shared_ext = 'so'
    static_ext = 'a'
    exe_ext = []
    dynamic_interface_dependencies = [dependency('ncurses', static: false), dependency('RapidJSON', static: false), dependency('sfml-graphics', static: false)]
    static_interface_dependencies = [dependency('ncurses', static: true), dependency('RapidJSON', static: true), dependency('sfml-graphics', static: true)]
endif
# Compile the source code into shared and a static libraries
emath_shlib = shared_library('dynamic_emath', files(emath_files), include_directories: emath_include, link_args: ['-dynamic'], name_suffix: shared_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())
emath_stlib = static_library('static_emath', files(emath_files), include_directories: emath_include, link_args: ['-static-libgcc', '-static-libstdc++', '-static'], name_suffix: static_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())

eparser_shlib = shared_library('dynamic_eparser', files(eparser_files), include_directories: emath_include, link_args: ['-dynamic'], name_suffix: shared_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())
eparser_stlib = static_library('static_eparser', files(eparser_files), include_directories: emath_include, link_args: ['-static-libgcc', '-static-libstdc++', '-static'], name_suffix: static_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())

#Create an installable target for the headers
install_headers(files(emath_headers, eparser_headers))

#Add test files
if host_machine.system() not in ['windows', 'mingw']
    emath_test = executable('test_emath', files(emath_test_files), name_suffix: exe_ext, include_directories: emath_include)
    eparser_test = executable('test_eparser', files(eparser_test_files), name_suffix: exe_ext, dependencies: dependency('gtest'), include_directories: emath_include)
    test('emath_tests', emath_test,)
    test('eparser_tests', eparser_test)
    install_data('./assets/emath.desktop', install_dir: '/usr/share/applications/')
    install_data('./assets/logo.png', install_dir: '/usr/share/icons/', rename: 'emath.png')
endif

#Add interface executable dependencies: interface_dependencies, 
executable('emath_cli_d', files(interface_files), include_directories: interface_include, dependencies: dynamic_interface_dependencies, link_args: ['-dynamic'], name_suffix: exe_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())
executable('emath_cli_s', files(interface_files), include_directories: interface_include, dependencies: static_interface_dependencies, link_args: ['-static-libgcc', '-static-libstdc++'], name_suffix: exe_ext, install: not meson.is_cross_build(), native: not meson.is_cross_build())

#Install the documentation
run_command('doxygen', 'doxygen.conf', check: false)

#Print a summary of the build
summary('Project', 'Emath++')
summary('Version', '2.2.0')
summary('Langs', 'C++')
summary('Emath shared library', emath_shlib.full_path())
summary('Emath static library', emath_stlib.full_path())
summary('Emath header files', emath_headers)
summary('Eparser shared library', eparser_shlib.full_path())
summary('Eparser static library', eparser_stlib.full_path())
summary('Eparser header files', eparser_headers)
summary('Source files', emath_files + eparser_files + interface_files)
summary('Test files', emath_test_files + eparser_test_files)
summary('Host machine', host_machine.system())