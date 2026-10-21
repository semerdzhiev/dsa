add_library(dsa_utils INTERFACE)
add_library(dsa::utils ALIAS dsa_utils)

target_include_directories(dsa_utils INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
