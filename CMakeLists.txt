cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "3" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB ip_filter.cpp)

add_executable(ip_filter_cli ${SOURCE_EXE})

add_library(ip_filter STATIC ${SOURCE_LIB})	

set_target_properties(ip_filter_cli ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(ip_filter
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(ip_filter_cli PRIVATE
   ip_filter
)

if (MSVC)
    target_compile_options(ip_filter_cli PRIVATE
        /W4
    )
    #target_compile_options(ip_filter PRIVATE
   #     /W4
    #)
else ()
    target_compile_options(ip_filter_cli PRIVATE
        -Wall -Wextra -Wpedantic
    )
    #target_compile_options(ip_filter_cli PRIVATE
    #    -Wall -Wextra -Wpedantic
    #)
    #target_compile_options(ip_filter PRIVATE
   #     -Wall -Wextra -pedantic -Werror
    #)
   # target_compile_options(ip_filter PRIVATE
    #-Wall -Wextra -Wpedantic
#)
endif()

install(TARGETS ip_filter_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(test)