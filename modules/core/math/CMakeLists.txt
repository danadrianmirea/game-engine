#=======================================================================================================================
 target_precompile_headers(core PUBLIC headers.hpp)
            target_sources(core PUBLIC functions.cpp mat4.cpp column.cpp vec3.cpp quat.cpp)
#=======================================================================================================================