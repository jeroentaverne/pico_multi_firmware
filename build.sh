if [ "$1" = "rp2040" ]
then
BOARD="pico"
fi
if [ "$1" = "rp2350" ]
then
BOARD="pico2"
fi

if [ "$BOARD" = "" ]
then
echo "Please supply MCU type (rp2040 or rp2350)"
exit
fi

cp memmap_$1.ld general.ld

BUILDDIR=$1_build

mkdir $BUILDDIR
rm $BUILDDIR/*

gcc uf2create.c -o uf2create

cd $BUILDDIR
cmake -DPICO_BOARD=$BOARD ..
make -j64

../uf2create $1 bootloader.bin firmware0.bin firmware1.bin firmware2.bin firmware3.bin firmware4.bin firmware5.bin total.uf2
