project('Emath++', 'cpp', version : '1.0.0')

include = ['./include']
header_files = ['./include/emath.h']
source_files = ['./src/emath.cpp']
test_files = ['./test/emath.cpp']

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

# Compile the source code into a shared and a static library
shlib = shared_library('dynamic_emath', files(header_files, source_files), include_directories: include, name_suffix: shared_ext, install: not meson.is_cross_build())
stlib = static_library('static_emath', files(header_files, source_files), include_directories: include, name_suffix: static_ext, install: not meson.is_cross_build())

#Create an installable target for the headers
install_headers(files(header_files))

#Add test file
test = executable('test_emath', files(test_files, source_files), name_suffix: exe_ext, include_directories: include)
test('tests', test, is_parallel: true)

#Install the documentation and create a target
run_command('doxygen', 'doxygen.conf', check: true)

#Print a summary of the build
summary('Project', 'Emath++')
summary('Version', '1.0.0')
summary('Langs', 'C++')
summary('Shared library', shlib.full_path())
summary('Static library', stlib.full_path())
summary('Header files', header_files)
summary('Source files', source_files)
summary('Test files', test_files)
summary('Host machine', host_machine.system())