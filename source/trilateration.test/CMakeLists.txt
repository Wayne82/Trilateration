cmake_minimum_required(VERSION 2.6)

set(TARGET_NAME Trilateration.test)

file(GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
	[^.]*.cpp
	[^.]*.txt
	)
	
set(SOURCE ${GENERAL})

include_directories(
	../../external/cppunit/include
	..
)

if(${T_LIB_TYPE} STREQUAL SHARED)
add_definitions(
	-DTRILATERATION_IS_DLL
)
endif()

add_executable(${TARGET_NAME} 
	${SOURCE}
)

target_link_libraries(${TARGET_NAME} cppunit Trilateration)