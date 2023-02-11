source_path=$(cd "$(dirname ".")"; pwd)/$(basename ".")
mkdir -v ./bin
meson setup ./bin --prefix=$source_path/
unset source_path