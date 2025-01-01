cmake_minimum_required(VERSION 3.5)
project(chunkbiomes)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
if (WIN32)
	set(CMAKE_C_FLAGS "-D_WIN32")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -DDEBUG")

set(HEADERS
	Bfinders.h
	Brng.h
)
set(SOURCES
	Bfinders.c
)

add_subdirectory(cubiomes)

add_library(chunkbiomesObjects OBJECT ${SOURCES})
set_property(TARGET chunkbiomesObjects PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(chunkbiomes SHARED $<TARGET_OBJECTS:chunkbiomesObjects>)
add_library(chunkbiomes_static STATIC $<TARGET_OBJECTS:chunkbiomesObjects>)

target_link_libraries(chunkbiomes PUBLIC cubiomes)
target_include_directories(chunkbiomes PRIVATE HEADERS)

install(TARGETS chunkbiomes chunkbiomes_static DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)


