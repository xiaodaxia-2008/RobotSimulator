file(GLOB shader_files */*.vert */*.frag */*.rgen */*.rchit */*.rint */*.rmiss)

file(GLOB shader_extra_files */*.glsl)
set_source_files_properties(${shader_extra_files} PROPERTIES HEADER_FILE_ONLY TRUE)

# Shader compilation
foreach(shader ${shader_files})
	#message("SHADER: ${shader}")
	get_filename_component(file_name ${shader} NAME)
	get_filename_component(full_path ${shader} ABSOLUTE)
	set(output_dir ${CMAKE_CURRENT_BINARY_DIR}/shaders)
	set(output_file ${output_dir}/${file_name}.spv)
	set(compiled_shaders ${compiled_shaders} ${output_file})
	set(compiled_shaders ${compiled_shaders} PARENT_SCOPE)
	set_source_files_properties(${shader} PROPERTIES HEADER_FILE_ONLY TRUE)
        add_custom_command(
            OUTPUT ${output_file}
            COMMAND ${CMAKE_COMMAND} -E make_directory ${output_dir}
            COMMAND ${Vulkan_GLSLANG_VALIDATOR} -V ${full_path} -o ${output_file}
            DEPENDS ${full_path}
        )
endforeach()

add_custom_target(
	shaders 
	DEPENDS ${compiled_shaders}
	SOURCES ${shader_files} ${shader_extra_files})
