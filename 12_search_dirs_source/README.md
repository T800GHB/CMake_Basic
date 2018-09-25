Three source code files, CMakeLists.txt will bulid only one executable file.
It's not like 02 demo, instead of "set" command to collect all source files, 
use aux_source_directory to find all source files in the specific directory.
In this demostration, math function will locate at directory "math".
Static library will be generated at build/math
"target_link_libraries" command will find it at current work directory.
