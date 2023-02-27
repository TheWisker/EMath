mkdir -v ./bin
mkdir -v ./bin/win
meson setup ./bin/win --cross-file ./assets/crosswin.txt
cd ./bin/win
meson configure --buildtype=release --optimization=3
meson compile
cd ../../