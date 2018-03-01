
#-------------------------------------------------------------------------------------------
# Compiler Flags
# see https://cmake.org/cmake/help/v3.1/prop_tgt/C_STANDARD.html cmake only supports c11 c99 c90
# cmake will automatically use the highest stdc if complier supports
# in eacompilertraits.h we habe defined macro that indicates us what stdc this compiler supports
# so here just use -std=c11 simply
#-------------------------------------------------------------------------------------------
if (CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "GNU")
    # make it same to msvc that uses _DEBUG
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
endif()

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
