@if not exist build mkdir build
@sdcc -mmcs51 --code-size 0x4000 --xram-loc 0x4000 --xram-size 0x0000 test.c -o build\