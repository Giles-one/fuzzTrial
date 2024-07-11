```
docker pull aflplusplus/aflplusplus
docker run -ti -v $(pwd):/src aflplusplus/aflplusplus
cd qemu_mode
./build_qemu_support.sh
cd /src
make
echo -en '\xef\xbe\xad\xdf' > in/testcase1
afl-fuzz -Q -i in -o out -- ./PUT @@ 
```