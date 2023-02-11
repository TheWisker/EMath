project('Emath++', 'cpp', version : '1.1.0')

include = ['./include/', './third_party/CSet/include/']
emath_headers = ['./include/emath.h', './third_party/CSet/include/set.h']
eparser_headers = ['./include/eparser.h']
emath_files = [emath_headers, './src/emath.cpp']
eparser_files = [eparser_headers, './src/eparser.cpp', emath_files]

emath_test_files = ['./test/emath.cpp', emath_files]
eparser_test_files = [eparser_files, './test/eparser.cpp']

# Determine the system that is being built on
if host_machine.system() in ['windows', 'mingw']
    message('Windows machine detected, thus building for windows!')
    shared_ext = 'dll'
    static_ext = 'lib'
    exe_ext = 'exe'
else
    message('Linux machine detected, thus building for linux!')
    shared_ext = 'so'
    static_ext = 'a'
    exe_ext = []
endif

# Compile the source code into shared and a static libraries
emath_shlib = shared_library('dynamic_emath', files(emath_files), include_directories: include, name_suffix: shared_ext, install: not meson.is_cross_build())
emath_stlib = static_library('static_emath', files(emath_files), include_directories: include, name_suffix: static_ext, install: not meson.is_cross_build())

eparser_shlib = shared_library('dynamic_eparser', files(eparser_files), include_directories: include, name_suffix: shared_ext, install: not meson.is_cross_build())
eparser_stlib = static_library('static_eparser', files(eparser_files), include_directories: include, name_suffix: static_ext, install: not meson.is_cross_build())

#Create an installable target for the headers
install_headers(files(emath_headers, eparser_headers))

#Add test files
if not host_machine.system() in ['windows', 'mingw']
    emath_test = executable('test_emath', files(emath_test_files), name_suffix: exe_ext, include_directories: include)
    eparser_test = executable('test_eparser', files(eparser_test_files), name_suffix: exe_ext, include_directories: include) #dependencies: dependency('gtest')
    test('emath_tests', emath_test,)
    test('eparser_tests', eparser_test)
endif

#Install the documentation
run_command('doxygen', 'doxygen.conf', check: false)

#Print a summary of the build
summary('Project', 'Emath++')
summary('Version', '1.1.0')
summary('Langs', 'C++')
summary('Emath shared library', emath_shlib.full_path())
summary('Emath static library', emath_stlib.full_path())
summary('Emath header files', emath_headers)
summary('Eparser shared library', eparser_shlib.full_path())
summary('Eparser static library', eparser_stlib.full_path())
summary('Eparser header files', eparser_headers)
summary('Source files', emath_files + eparser_files)
summary('Test files', emath_test_files + eparser_test_files)
summary('Host machine', host_machine.system())