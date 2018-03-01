
#-------------------------------------------------------------------------------------------
# Compiler Flags
# see https://cmake.org/cmake/help/v3.1/prop_tgt/C_STANDARD.html cmake only supports c11 c99 c90
#-------------------------------------------------------------------------------------------
if(UNIX AND "${CMAKE_C_COMPILER_ID}" STREQUAL "Intel" )
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -fasm-blocks" )
endif()

# NOT LESS == GREATER_OR_EQUAL; CMake doesn't support this out of the box.
if(CMAKE_C_COMPILER_ID MATCHES "AppleClang")
    if(NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "6.1"))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "6.1" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "4.3")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
    endif()
    # It seems Apple started changing version numbers after 3.1, going straight to 4.0 after 3.1.
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "4.3" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "3.1")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "3.1")
        message(FATAL_ERROR "Building with a Apple clang version less than 3.1 is not supported.")
    endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "Clang") # non-Apple clangs uses different versioning.
    if(NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "3.5.0"))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "3.5.0" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "3.2")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "3.2" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "3.0")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "3.0")
        message(FATAL_ERROR "Building with a clang version less than 3.0 is not supported.")
    endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
    if(NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "5.2.0"))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "5.2.0" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "4.8.1")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "4.8.1" AND (NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS "4.7.3")))
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")
    endif()
    if(CMAKE_C_COMPILER_VERSION VERSION_LESS "4.7.3")
        message(FATAL_ERROR "Building with a gcc version less than 4.7.3 is not supported.")
    endif()
endif()


if (CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
endif()
