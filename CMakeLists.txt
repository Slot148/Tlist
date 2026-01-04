cmake_minimum_required(VERSION 3.10)
project(lista2)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(MAKE_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/tlist
    ${CMAKE_SOURCE_DIR}/tlist/include
    ${CMAKE_SOURCE_DIR}/tlist/lib
)

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
target_include_directories(Tlist PUBLIC include)

file(COPY ${CMAKE_SOURCE_DIR}/include/tlist/ DESTINATION ${CMAKE_SOURCE_DIR}/tlist/include)

set_target_properties(Tlist PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/tlist/lib
)