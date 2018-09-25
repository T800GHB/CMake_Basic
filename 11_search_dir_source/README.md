Three source code files, CMakeLists.txt will bulid only one executable file.
It's not like 02 demo, instead of "set" command to collect all source files, 
use aux_source_directory to find all source files in the specific directory.
