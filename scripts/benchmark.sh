cd ./bin
meson configure --buildtype=release --optimization=3 --debug
meson compile
meson test --benchmark -v
cd ..