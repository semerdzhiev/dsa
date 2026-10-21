add_executable(dsa_array_walking
	"array-walking.cpp"
)

target_sources(
	dsa_array_walking
	PRIVATE
		
)

target_link_libraries(dsa_array_walking PRIVATE
	dsa::utils
	dsa::build_options
	dsa::cxx_version
)

set_target_properties(dsa_array_walking PROPERTIES OUTPUT_NAME "array-walking")
