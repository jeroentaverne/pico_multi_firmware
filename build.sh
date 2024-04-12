mkdir build
rm build/*

gcc uf2create.c -o uf2create

cd build
cmake ..
make -j64

../uf2create bootloader.bin firmware0.bin firmware1.bin firmware2.bin firmware3.bin firmware4.bin firmware5.bin total.uf2
