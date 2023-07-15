to compile you will need mono-complete:

sudo apt install mono-complete

then you can compile with:

mcs -out:bogosort.exe bogosort.cs

and then run with:

mono bogosort.exe

fun fact, this is seriously a windows executable, so someone running windows can run it with just "bogosort.exe".