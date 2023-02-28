rm -fr ./bin
rm -fr ./doc
rm -fr ./dist
mkdir -v ./bin
mkdir -v ./bin/win
mkdir -v ./dist
mkdir -v ./dist/linux
mkdir -v ./dist/windows
mkdir -v ./dist/source
meson setup ./bin
meson setup ./bin/win --cross-file assets/crosswin.txt
cd ./bin
meson configure --buildtype=release --optimization=3
meson compile
cp ./emath_cli_d ../dist/linux/emath_cli_d
cp ./emath_cli_s ../dist/linux/emath_cli_s
cd ./win
meson configure --buildtype=release --optimization=3
meson compile
cp ./emath_cli_d.exe ../../dist/windows/emath_cli_d.exe
cp ./emath_cli_s.exe ../../dist/windows/emath_cli_s.exe
cd ../../../
mkdir -v ./temp
cp -r ./EMath++ ./temp
rm -fr ./temp/EMath++/bin
rm -fr ./temp/EMath++/.git
rm -fr ./temp/EMath++/dist
rm -fr ./temp/EMath++/.secret
rm -fr ./temp/EMath++/clear
mv ./temp/EMath++ ./EMath++/dist/source/
rm -fr ./temp
cd ./EMath++/dist/linux
tar -czvf linux_dist.tar.gz ../source/EMath++/ ./emath_cli_d ./emath_cli_s
cd ../windows
zip -r windows_dist.zip ../source/EMath++/ ./emath_cli_d.exe ./emath_cli_s.exe
cd ../../
rm -fr ./dist/source
#git add .
#git commit -m "New distribution!"
#git push