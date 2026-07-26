cmake_minimum_required(VERSION 3.20)

project(TimerUl)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} 
	PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		DEBUG_INFO
		DEBUG_ACTION
		DEBUG_WARNING
		DEBUG_DBUG)

