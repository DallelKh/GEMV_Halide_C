
#get path to halide
HALIDE="$1"

echo "____Compiling ./code/Halidecode.c "
g++ ./code/Halidecode.cpp -g -L "$HALIDE"/bin -I "$HALIDE"/include -I "$HALIDE"/tools  -lHalide -ldl -lpthread -std=c++11 -o ./exe/Hexe
echo "____Executing Halide implementation "
LD_LIBRARY_PATH=../Halide/bin ./exe/Hexe
echo "____Compiling ./code/Ccode.c "
gcc ./code/Ccode.c -o ./exe/Cexe
echo "____Executing C implementation "
./exe/Cexe
