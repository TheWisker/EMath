cd ./bin
meson configure --buildtype=debugoptimized --optimization=g --debug
meson compile
meson test -v
cd ..