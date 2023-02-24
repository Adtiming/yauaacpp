project(test_yauaacpp)

cmake_minimum_required(VERSION 3.1)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${YAUAA_CPP_CXX_STANDARD} -Wno-unused-parameter")



set(CMAKE_EXE_LINKER_FLAGS "-fno-stack-limit")


add_executable(test_c
        src/yauaacpp/test.c  )

add_executable(test_yauaacpp
        src/yauaacpp/test.cpp
        )


# yauaacpp dependency
target_include_directories(${PROJECT_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../${TLS_SUB_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../${CXX_UTILS_DIR}>)

find_package(Threads REQUIRED)

if(YAUAA_CPP_BUILD_STATIC)
    set(YAUAA_CPP_LIB yauaacpp_static)
else()
    set(YAUAA_CPP_LIB yauaacpp)
endif()

target_link_libraries(test_c ${YAUAA_CPP_LIB} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_yauaacpp ${YAUAA_CPP_LIB} ${CMAKE_THREAD_LIBS_INIT})
