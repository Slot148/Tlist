cmake_minimum_required( VERSION 3.10)
project(tlist VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(TLIST_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)

if(MSVC)
  set(COMPILE_FLAGS /W4)
  if(TLIST_WARNINGS_AS_ERRORS)
    list(APPEND COMPILE_FLAGS /WX)
  endif()
else()
  set(COMPILE_FLAGS -Wall -Wextra -Wpedantic)
  if(TLIST_WARNINGS_AS_ERRORS)
    list(APPEND COMPILE_FLAGS -Werror)
  endif()
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

install(TARGETS Tlist 
    EXPORT TlistTargets.cmake
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/tlist DESTINATION include)

install(EXPORT TlistTargets
    FILE TlistTargets.cmake
    NAMESPACE tlist::
    DESTINATION share/tlist
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    cmake/TlistConfig.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/TlistConfig.cmake"
    INSTALL_DESTINATION share/tlist
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/TlistConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/TlistConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/TlistConfigVersion.cmake"
    DESTINATION share/tlist
)

# add_executable(main main.c)
# target_link_libraries(main PRIVATE Tlist)