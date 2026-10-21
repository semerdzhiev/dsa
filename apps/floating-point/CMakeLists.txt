add_executable(dsa_floating_point
    "floating-point.cpp"
)

target_link_libraries(dsa_floating_point PRIVATE
    dsa::build_options
    dsa::cxx_version
)

set_target_properties(dsa_floating_point PROPERTIES OUTPUT_NAME "floating-point")
