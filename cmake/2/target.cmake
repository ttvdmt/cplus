cmake_minimum_required(VERSION 3.20)

function(print_target_info target)
  message("Name: '${target}'")

  get_target_property(type ${target} TYPE)
  message("\nType: ${type}")

  get_target_property(sources ${target} SOURCES)
  message("\nSources: ${sources}")

  get_target_property(sources ${target} SOURCE_DIR)
  message("\nSource Dir: ${sources}")

  get_target_property(binary ${target} BINARY_DIR)
  message("\nBinary Dir: ${binary}")

  get_target_property(dir ${target} INCLUDE_DIRECTORIES)
  message("\nInclude Directories: ${dir}")

  get_target_property(defs ${target} COMPILE_DEFINITIONS)
  message("\nCompile Definitions: ${defs}")

  get_target_property(opts ${target} COMPILE_OPTIONS)
  message("\nCompile Options: ${opts}")

  get_target_property(libs ${target} LINK_LIBRARIES)
  message("\nLink Libraries: ${libs}")

  get_target_property(opts ${target} LINK_OPTIONS)
  message("\nLink Options: ${opts}")
endfunction()