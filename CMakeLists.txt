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

get_filename_component(TLIST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/tlist" ABSOLUTE)
target_include_directories(Tlist PUBLIC
    $<BUILD_INTERFACE:${TLIST_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(Tlist PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# --- REGRAS DE INSTALAÇÃO (para o vcpkg) ---
include(GNUInstallDirs)

install(TARGETS Tlist
    EXPORT TlistTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} 
)

install(DIRECTORY include/tlist DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT TlistTargets
    FILE TlistTargets.cmake
    NAMESPACE Tlist::
    DESTINATION share/tlist
)