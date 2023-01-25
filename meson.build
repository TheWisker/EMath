project('CSet++', 'cpp', version : '1.0.0')

include = ['./include']
header_files = ['./include/set.h']
#source_files = [''] #None
test_files = ['./test/set.cpp']
benchmark_files = ['./benchmark/set.cpp']
man_files = ['./doc/man/man3/contains.3', './doc/man/man3/count.3', './doc/man/man3/diff.3', './doc/man/man3/intersection.3', './doc/man/man3/sdiff.3', './doc/man/man3/sunion.3', './doc/man/man3/unique.3']

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
shlib = shared_library('dynamic_cset', files(header_files), include_directories: include, name_suffix: shared_ext, install: not meson.is_cross_build())
stlib = static_library('static_cset', files(header_files), include_directories: include, name_suffix: static_ext, install: not meson.is_cross_build())

#Create an installable target for the headers
install_headers(files(header_files))

#Add test file
test = executable('test_set', files(test_files), name_suffix: exe_ext, include_directories: include)
test('tests', test, is_parallel: true)

#Add benchmark file
benchmark = executable('benchmark_set', files(benchmark_files), name_suffix: exe_ext, include_directories: include)
benchmark('benchmarks', benchmark)

#Install the documentation and create a target
run_command('doxygen', 'doxygen.conf', check: true)
install_man(files(man_files))

#Release windows zip build target
#win_build = meson.buildtype()
#win_build.compiler('c')
#win_build.linker('link')

#Print a summary of the build
summary('Project', 'CSet++')
summary('Version', '1.0.0')
summary('Langs', 'C++')
summary('Shared library', shlib.full_path())
summary('Static library', stlib.full_path())
summary('Header files', header_files)
#summary('Source files', source_files)
summary('Test files', test_files)
summary('Benchmark files', benchmark_files)
summary('Host machine', host_machine.system())