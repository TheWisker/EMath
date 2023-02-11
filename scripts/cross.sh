source_path=$(cd "$(dirname ".")"; pwd)/$(basename ".")
rm -fr ./bin
rm -fr ./doc
rm -fr ./dist
mkdir -v ./bin
mkdir -v ./bin/win
meson setup ./bin --prefix=$source_path/
meson setup ./bin/win --cross-file assets/crosswin.txt --prefix=$source_path/
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
unset source_path