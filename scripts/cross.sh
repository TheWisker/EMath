source_path=$(cd "$(dirname ".")"; pwd)/$(basename ".")
rm -fr ./bin
rm -fr ./doc
rm -fr ./dist
meson setup ./bin --prefix=$source_path/ --wipe
meson setup ./bin/win --cross-file assets/crosswin.txt --prefix=$source_path/ --wipe
git add .
git commit -m "Cross compilation executing"
cd ./bin
meson setup dist
cd ./win
meson setup dist --formats zip
mkdir -v ../../dist/
cp -r ./meson-dist/* ../../dist/
cd ..
cp -r ./meson-dist/* ../dist/
cd ..
git add .
git commit -m "Cross compilation executed"
unset source_path