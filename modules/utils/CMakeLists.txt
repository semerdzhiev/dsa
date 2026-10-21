set(MODULE_NAME "utils")
set(MODULE_TARGET "${PROJECT_ID}_${MODULE_NAME}")
set(MODULE_ALIAS "${PROJECT_ID}::${MODULE_NAME}")

add_library("${MODULE_TARGET}" INTERFACE)
add_library("${MODULE_ALIAS}" ALIAS "${MODULE_TARGET}")

target_include_directories("${MODULE_TARGET}" INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
