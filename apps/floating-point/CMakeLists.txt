set(APP_NAME "floating_point")
set(APP_TARGET "${PROJECT_ID}_${APP_NAME}")

add_executable("${APP_TARGET}"
    "floating-point.cpp"
)

target_link_libraries("${APP_TARGET}" PRIVATE
    "${PROJECT_ID}::build_options"
    "${PROJECT_ID}::cxx_version"
)

set_target_properties("${APP_TARGET}" PROPERTIES
    OUTPUT_NAME "floating-point"
)
