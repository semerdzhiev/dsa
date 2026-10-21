# Executable target for the unit tests
add_executable(dsa_utils_tests
    allocator_tests.cpp
    mocking_objects_tests.cpp
)

target_link_libraries(dsa_utils_tests PRIVATE
    dsa::utils
    dsa::build_options
    dsa::cxx_version
    Catch2::Catch2WithMain
)

catch_discover_tests(dsa_utils_tests
    TEST_PREFIX "utils::"
    PROPERTIES LABELS "utils"
	ADD_TAGS_AS_LABELS
)
