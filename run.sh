echo "____Compiling ./code/Halidecode.c "
g++ ./code/Halidecode.cpp -g -L ../Halide/bin -I ../Halide/include -I ../Halide/tools  -lHalide -ldl -lpthread -std=c++11 -o ./exe/Hexe
echo "____Executing Halide implementation "
LD_LIBRARY_PATH=../Halide/bin ./exe/Hexe
echo "____Compiling ./code/Ccode.c "
gcc ./code/Ccode.c -o ./exe/Cexe
echo "____Executing C implementation "
./exe/Cexe
