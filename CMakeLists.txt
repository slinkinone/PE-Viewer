cmake_minimum_required(VERSION 2.8)
project(PE-Viewer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -Wall")

file(GLOB INCLUDE_DIR
	include
)

file(GLOB INCLUDE_DIR
    include
    include/Common/*.h
    include/DataDirectory/*.h
    include/DosHeader/*.h
    include/NT_Header/*.h
    include/OptionalHeader/*.h
    include/PE_Signature/*.h
    include/SectionHeader/*.h
    include/Tables/*.h
)

file(GLOB SOURCE_DIR
    src/
    src/Common/*.cpp
    src/DataDirectory/*.cpp
    src/DosHeader/*.cpp
    src/NT_Header/*.cpp
    src/NT_Header/OptionalHeader/*.cpp
    src/NT_Header/FileHeader/*.cpp
    src/PE_Signature/*.cpp
    src/SectionHeader/*.cpp
    src/Tables/*.cpp
    main.cpp
)

#link_directories(${PROJECT_SOURCE_DIR}/src)

#message( STATUS ${INCLUDE_DIR} )
#message( STATUS ${SOURCE_DIR} )

include_directories (${INCLUDE_DIR})   

add_executable(${PROJECT_NAME} ${SOURCE_DIR} main.cpp)