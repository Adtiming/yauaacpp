# 在指定目录下寻找头文件和动态库文件的位置，可以指定多个目标路径
find_path(antlr4-cpp-runtime_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h /usr/include/ /usr/local/include ${CMAKE_SOURCE_DIR}/ModuleMode)
find_library(antlr4-cpp-runtime_LIBRARY NAMES antlr4-runtime PATHS /usr/lib/antlr4-runtime /usr/local/lib/antlr4-runtime ${CMAKE_SOURCE_DIR}/ModuleMode)
find_file(antlr4-cpp-runtime_FILE_4_12_0 NAME libantlr4-runtime.so.4.12.0 PATHS /usr/lib /usr/local/lib)
if (antlr4-cpp-runtime_INCLUDE_DIR AND antlr4-cpp-runtime_LIBRARY)
    set(antlr4-cpp-runtime_FOUND TRUE)
endif (antlr4-cpp-runtime_INCLUDE_DIR AND antlr4-cpp-runtime_LIBRARY)
