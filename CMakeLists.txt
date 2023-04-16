cmake_minimum_required(VERSION 3.10)

project(LeetCode)
file(GLOB SRC_FILES 
	"${CMAKE_CURRENT_SOURCE_DIR}/Easy/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/Medium/*.cpp")

foreach(src_file ${SRC_FILES})
    get_filename_component(target ${src_file} NAME_WLE)
    add_executable(${target} ${src_file})
    list(APPEND TARGETS ${target})
    message("target added: ${target}")
endforeach(src_file ${SRC_FILES})

foreach(target ${TARGETS})
    set_target_properties(${target}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )
    target_compile_options(${target} PRIVATE
            /EHsc /W4 #/WX
        )
endforeach(target ${TARGETS})

#if (PRINT_ALL_VARS)
#    get_cmake_property(_variableNames VARIABLES)
#    foreach (_variableName ${_variableNames})
#        message(STATUS "${_variableName}=${${_variableName}}")
#    endforeach()
#endif()

#if(MSVC)
#if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "19.34")
#  string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
#    "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> <SOURCE> -nologo -TP"
#    " -showIncludes"
#    " -scanDependencies <DYNDEP_FILE>"
#    " -Fo<OBJECT>")
#  set(CMAKE_EXPERIMENTAL_CXX_SCANDEP_DEPFILE_FORMAT "msvc")
#  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "msvc")
#  set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG "@<MODULE_MAP_FILE>")
#endif ()
#endif(MSVC)

#if(CMAKE_COMPILER_IS_GNUXX)
#if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "19.34")
#string(CONCAT CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE
#  "<CMAKE_CXX_COMPILER> <DEFINES> <INCLUDES> <FLAGS> <SOURCE>"
#  " -MT <DYNDEP_FILE> -MD -MF <DEP_FILE>"
#  " ${flags_to_scan_deps} -fdep-file=<DYNDEP_FILE> -fdep-output=<OBJECT>"
#  )
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FORMAT "gcc")
#set(CMAKE_EXPERIMENTAL_CXX_MODULE_MAP_FLAG
#  "${compiler_flags_for_module_map} -fmodule-mapper=<MODULE_MAP_FILE>")
#endif()
#endif(CMAKE_COMPILER_IS_GNUXX)
