meson setup ./bin
meson setup ./bin/win --cross-file assets/crosswin.txt
git add .
git commit -m "Cross compilation executing"
cd ./bin
meson dist
cd ./win
meson dist --formats zip
mkdir -v ../../dist/
cp -r ./meson-dist/* ../../dist/
cd ..
cp -r ./meson-dist/* ../dist/
cd ..
git add .
git commit -m "Cross compilation executed"