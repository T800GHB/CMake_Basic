This project demostrate how to install a project to system.
Follow build README.md to compile this project.
After building procedure, type:
    $make install
Could copy executable file, header file and library to specified path by
set(CMAKE_INSTALL_PREFIX /tmp)
Now, all the results has installed at /tmp
As default, install (TARGETS Power DESTINATION bin) will copy executable file to
/usr/local/bin
DESTINATION means /usr/local/ as default
So, you need to type:
    $sudo make install

This project has also show how to create a test project, add test command at CMakeLists.txt
After make procedure, type:
    $make test
To run test