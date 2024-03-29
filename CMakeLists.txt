# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.15)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-tree builds are not supported. Run CMake from a separate directory: cmake -B build")
endif()

set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr and automatically regenerate CMakeLists.txt
	include(cmkr.cmake OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Create a configure-time dependency on cmake.toml to improve IDE support
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

project(sourcemod_cmkr)

# Target: amtl
add_library(amtl INTERFACE)

add_library(amtl::amtl ALIAS amtl)
target_include_directories(amtl INTERFACE
	"sourcemod/public/amtl"
	"sourcemod/public/amtl/amtl"
)

# Target: smsdk
add_library(smsdk INTERFACE)

add_library(smsdk::smsdk ALIAS smsdk)
target_include_directories(smsdk INTERFACE
	"sourcemod/"
	"sourcemod/core"
	"sourcemod/public"
	"sourcemod/sourcepawn/include"
)

# Target: mmsdk
add_library(mmsdk INTERFACE)

add_library(mmsdk::mmsdk ALIAS mmsdk)
target_include_directories(mmsdk INTERFACE
	"metamod/core"
)

# Target: extension
set(extension_SOURCES
	"extension/extension.cpp"
	"extension/extension.h"
	"extension/smsdk_config.h"
	"sourcemod/public/smsdk_ext.cpp"
	cmake.toml
)

add_library(extension SHARED)

target_sources(extension PRIVATE ${extension_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${extension_SOURCES})

target_compile_features(extension PUBLIC
	cxx_std_20
)

if((CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT MATCHES "^MSVC$") OR (CMAKE_C_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_C_COMPILER_FRONTEND_VARIANT MATCHES "^MSVC$")) # clang
	target_compile_options(extension PUBLIC
		-Wimplicit-exception-spec-mismatch
		-m32
		-Wno-non-virtual-dtor
		-Wno-delete-non-virtual-dtor
	)
endif()

target_include_directories(extension PUBLIC
	extension
)

target_link_libraries(extension PUBLIC
	amtl::amtl
	smsdk::smsdk
	mmsdk::mmsdk
)

if((CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT MATCHES "^MSVC$") OR (CMAKE_C_COMPILER_ID MATCHES "Clang" AND NOT CMAKE_C_COMPILER_FRONTEND_VARIANT MATCHES "^MSVC$")) # clang
	target_link_options(extension PUBLIC
		-m32
	)
endif()
