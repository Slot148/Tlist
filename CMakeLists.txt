cmake_minimum_required(VERSION 3.10)
project(tlist VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
    set(COMPILE_FLAGS /W4 /WX)
else()
    set(COMPILE_FLAGS -Wall -Wextra -Wpedantic -Werror)
endif()

add_library(Tlist STATIC 
    src/Tlist.c 
    src/Titerator.c 
    src/Tvector.c
)

target_compile_options(Tlist PRIVATE ${COMPILE_FLAGS})

target_include_directories(Tlist PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(Tlist::Tlist ALIAS Tlist)

install(TARGETS Tlist
    EXPORT TlistTargets
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include
)

install(DIRECTORY include/tlist DESTINATION include)

install(EXPORT TlistTargets
    FILE TlistTargets.cmake
    NAMESPACE Tlist::
    DESTINATION share/tlist
)