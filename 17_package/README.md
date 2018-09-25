This project demostrate how to create a install package.
After make procedure done at directory build/ .
There will be to file has generate for installation:
CPackConfig.cmake and CPackSourceConfig.cmake
If you want to create a binary installation package, type:
    $cpack -C CPackConfig.cmake
If you want to create a source code installation package, type:
    $cpack -C CPackSourceConfig.cmake

Then, 3 package will generate at build/
    PowerDemo.sh
    PowerDemo.tar.gz
    PowerDeom.tar.Z

We could interactive install this package, like this:
    $sh PowerDemo.sh