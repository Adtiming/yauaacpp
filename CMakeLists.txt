cmake_minimum_required(VERSION 3.1)

set(YAUAA_CPP_VERSION "6.6")
message(STATUS "yauaa-cpp version: ${YAUAA_CPP_VERSION}")

project(yauaacpp LANGUAGES CXX VERSION ${YAUAA_CPP_VERSION})

EXEC_PROGRAM(gcc ARGS --version OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION)
IF(CMAKE_C_COMPILER_VERSION MATCHES ".*4\\.[0-9].*")
    message("gcc is version 4")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_UTF8_INSTEAD_OF_CODECVT")
ENDIF(CMAKE_C_COMPILER_VERSION MATCHES ".*4\\.[0-9].*")


# set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include_directories(/usr/local/include/antlr4-runtime)
include_directories(${PROJECT_SOURCE_DIR}/analyser/cpp)

set(YAUAA_CPP_DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE ${YAUAA_CPP_DEFAULT_BUILD_TYPE} CACHE STRING "Set build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()
message(STATUS "yauaa-cpp build type: ${CMAKE_BUILD_TYPE}")

set(YAUAA_CPP_DEFAULT_CXX_STANDARD 11)
if(NOT YAUAA_CPP_CXX_STANDARD)
    set(YAUAA_CPP_CXX_STANDARD ${YAUAA_CPP_DEFAULT_CXX_STANDARD} CACHE STRING "Set CXX standard" FORCE)
    set_property(CACHE YAUAA_CPP_CXX_STANDARD PROPERTY STRINGS "11" "14" "17" "20")
endif()
message(STATUS "yauaa-cpp build with CXX standard: c++${YAUAA_CPP_CXX_STANDARD}")

if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${YAUAA_CPP_CXX_STANDARD} -Wno-unused-parameter")
else()
    if(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++${YAUAA_CPP_CXX_STANDARD}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${YAUAA_CPP_CXX_STANDARD}")
    endif()
endif()



set(YAUAA_CPP_SOURCE_DIR src/yauaacpp)
set(YAUAA_GENERATED_SOURCE_DIR analyser/cpp)
set(YAUAA_RESOURCE_DIR src/resource)

set(TMP_SOURCE src/yauaacpp/tool/tool.cpp
        src/yauaacpp/debug/AbstractUserAgentAnalyzerTester.h
        src/yauaacpp/analyze/Analyzer.h
        src/yauaacpp/debug/DebugUserAgent.h
        src/yauaacpp/debug/FlattenPrinter.h
        src/yauaacpp/debug/UserAgentAnalyzerTester.h
        src/yauaacpp/parse/EvilManualUseragentStringHacks.h
        src/yauaacpp/parse/UserAgentTreeFlattener.h
        src/yauaacpp/utils/AntlrUtils.h
        src/yauaacpp/utils/CheckLoggingDependencies.h
        src/yauaacpp/utils/HostnameExtracter.h
        src/yauaacpp/utils/ListSplitter.h
        src/yauaacpp/utils/Normalize.h
        src/yauaacpp/utils/Splitter.h
        src/yauaacpp/utils/VersionSplitter.h
        src/yauaacpp/utils/WordSplitter.h
        src/yauaacpp/utils/YamlUtils.h
        src/yauaacpp/utils/YauaaVersion.h
        src/yauaacpp/analyze/MatcherAction.cpp
        src/yauaacpp/analyze/Matcher.cpp
        src/yauaacpp/config/MatcherConfig.cpp
        src/yauaacpp/analyze/treewalker/TreeExpressionEvaluator.cpp
        src/yauaacpp/analyze/treewalker/TreeExpressionEvaluator.h
        src/yauaacpp/analyze/treewalker/steps/Step.cpp
        src/yauaacpp/analyze/treewalker/steps/Step.h
        src/yauaacpp/analyze/treewalker/steps/WalkList.cpp
        src/yauaacpp/analyze/treewalker/steps/WalkList.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepContains.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepContains.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepDefaultIfNull.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepDefaultIfNull.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepEndsWith.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepEndsWith.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepEquals.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepEquals.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsInSet.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsInSet.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsNotInSet.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsNotInSet.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsNull.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepIsNull.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepNotContains.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepNotContains.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepNotEquals.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepNotEquals.h
        src/yauaacpp/analyze/treewalker/steps/compare/StepStartsWith.cpp
        src/yauaacpp/analyze/treewalker/steps/compare/StepStartsWith.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsInLookupContains.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsInLookupContains.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsInLookupPrefix.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsInLookupPrefix.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsNotInLookupPrefix.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepIsNotInLookupPrefix.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookup.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookup.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookupContains.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookupContains.h
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookupPrefix.cpp
        src/yauaacpp/analyze/treewalker/steps/lookup/StepLookupPrefix.h
        src/yauaacpp/analyze/treewalker/steps/value/StepBackToFull.h
        src/yauaacpp/analyze/treewalker/steps/value/StepCleanVersion.h
        src/yauaacpp/analyze/treewalker/steps/value/StepConcat.h
        src/yauaacpp/analyze/treewalker/steps/value/StepConcatPostfix.h
        src/yauaacpp/analyze/treewalker/steps/value/StepConcatPrefix.h
        src/yauaacpp/analyze/treewalker/steps/value/StepExtractBrandFromUrl.h
        src/yauaacpp/analyze/treewalker/steps/value/StepNormalizeBrand.h
        src/yauaacpp/analyze/treewalker/steps/value/StepReplaceString.h
        src/yauaacpp/analyze/treewalker/steps/value/StepSegmentRange.h
        src/yauaacpp/analyze/treewalker/steps/value/StepWordRange.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepDown.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepNext.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepNext.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepDown.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepNextN.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepNextN.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepPrev.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepPrev.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepPrevN.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepPrevN.h
        src/yauaacpp/analyze/treewalker/steps/walk/StepUp.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/StepUp.h
        src/yauaacpp/analyze/treewalker/steps/walk/stepdown/ChildIterable.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/stepdown/ChildIterable.h
        src/yauaacpp/analyze/treewalker/steps/walk/stepdown/UserAgentGetChildrenVisitor.cpp
        src/yauaacpp/analyze/treewalker/steps/walk/stepdown/UserAgentGetChildrenVisitor.h
        src/yauaacpp/config/AnalyzerConfig.cpp
        src/yauaacpp/config/TestCase.cpp
        src/yauaacpp/parse/UserAgentTreeFlattener.cpp
        src/yauaacpp/utils/AntlrUtils.cpp
        src/yauaacpp/parse/EvilManualUseragentStringHacks.cpp src/yauaacpp/utils/WordSplitter.cpp src/yauaacpp/utils/VersionSplitter.cpp src/yauaacpp/utils/YauaaVersion.cpp src/yauaacpp/utils/Normalize.cpp src/yauaacpp/calculate/CalculateDeviceName.cpp src/yauaacpp/utils/HostnameExtracter.cpp src/yauaacpp/utils/PrefixMap.h src/yauaacpp/utils/StringPrefixMap.h src/yauaacpp/utils/StringPrefixTrie.h src/yauaacpp/utils/ListSplitter.cpp src/yauaacpp/config/PackagedRules.cpp src/yauaacpp/config/PackagedRules.h)


set(YAUAA_CPP_SOURCES ${TMP_SOURCE}
        src/yauaacpp/yauaacpp.cpp
        src/yauaacpp/AgentField.cpp
        src/yauaacpp/UserAgent.cpp
        src/yauaacpp/yauaacpp.h
        src/yauaacpp/yauaacpp_def.h
        src/yauaacpp/UserAgentAnalyzer.h
        src/yauaacpp/UserAgent.h
        src/yauaacpp/AgentField.h
        src/yauaacpp/tool/tool.h
        src/yauaacpp/tool/tool.cpp
        src/yauaacpp/tool/encode.cpp
        src/yauaacpp/tool/encode.hpp
        src/yauaacpp/DefaultANTLRErrorListener.h
        src/yauaacpp/analyze/Matcher.h
        src/yauaacpp/analyze/InvalidParserConfigurationException.h
        src/yauaacpp/analyze/MatcherAction.h
        src/yauaacpp/analyze/MatcherExtractAction.h
        src/yauaacpp/analyze/MatcherFailIfFoundAction.h
        src/yauaacpp/analyze/MatcherList.h
        src/yauaacpp/analyze/MatcherRequireAction.h
        src/yauaacpp/analyze/MatcherVariableAction.h
        src/yauaacpp/analyze/MatchesList.h
        src/yauaacpp/analyze/NumberRangeList.h
        src/yauaacpp/analyze/NumberRangeVisitor.h
        src/yauaacpp/analyze/WordRangeVisitor.h
        src/yauaacpp/analyze/UselessMatcherException.h
        src/yauaacpp/calculate/CalculateAgentClass.h
        src/yauaacpp/calculate/CalculateAgentEmail.h
        src/yauaacpp/calculate/CalculateAgentName.h
        src/yauaacpp/calculate/CalculateDeviceBrand.h
        src/yauaacpp/calculate/CalculateDeviceName.h
        src/yauaacpp/calculate/CalculateNetworkType.h
        src/yauaacpp/calculate/ConcatNONDuplicatedCalculator.h
        src/yauaacpp/calculate/FieldCalculator.h
        src/yauaacpp/calculate/MajorVersionCalculator.h
        src/yauaacpp/classify/DeviceClass.h
        src/yauaacpp/config/AnalyzerConfig.h
        src/yauaacpp/config/ConfigLoader.h
        src/yauaacpp/config/MatcherConfig.h
        src/yauaacpp/config/TestCase.h
        src/yauaacpp/classify/UserAgentClassifier.h
        src/yauaacpp/AbstractUserAgentAnalyzer.h
        src/yauaacpp/AbstractUserAgentAnalyzerDirect.h
        src/yauaacpp/UserAgentAnalyzerDirect.h
        src/yauaacpp/AnalyzerPreHeater.cpp
        src/yauaacpp/AnalyzerPreHeater.h
        src/yauaacpp/PreHeatCases.cpp
        src/yauaacpp/PreHeatCases.h
        src/yauaacpp/AbstractUserAgentAnalyzerDirect.cpp
        src/yauaacpp/analyze/MatcherFailIfFoundAction.cpp
        src/yauaacpp/analyze/NumberRangeVisitor.cpp
        src/yauaacpp/analyze/MatcherRequireAction.cpp
        src/yauaacpp/utils/NotInAntlr4.h
        src/yauaacpp/tool/LUrlParser.h
        src/yauaacpp/tool/LUrlParser.cpp
        src/yauaacpp/tool/Builder.h
        src/yauaacpp/tool/lrumap.h
        src/yauaacpp/UserAgentAnalyzer.cpp
        src/yauaacpp/analyze/WordRangeVisitor.cpp
        src/yauaacpp/tool/dir.h
        src/yauaacpp/tool/dir.cpp
        src/yauaacpp/config/ConfigLoader.cpp
        src/yauaacpp/AbstractUserAgentAnalyzer.cpp
        src/yauaacpp/Range.cpp
        src/yauaacpp/Range.h
        src/yauaacpp/ImmutableUserAgent.h
        src/yauaacpp/yauaa_c.h
        )

set(YAUAA_GENERATED_SOURCE
        analyser/cpp/UserAgentBaseListener.cpp
        analyser/cpp/UserAgentBaseVisitor.cpp
        analyser/cpp/UserAgentLexer.cpp
        analyser/cpp/UserAgentListener.cpp
        analyser/cpp/UserAgentParser.cpp
        analyser/cpp/UserAgentTreeWalkerBaseListener.cpp
        analyser/cpp/UserAgentTreeWalkerBaseVisitor.cpp
        analyser/cpp/UserAgentTreeWalkerLexer.cpp
        analyser/cpp/UserAgentTreeWalkerListener.cpp
        analyser/cpp/UserAgentTreeWalkerParser.cpp
        analyser/cpp/UserAgentTreeWalkerVisitor.cpp
        analyser/cpp/UserAgentVisitor.cpp
        analyser/cpp/UserAgentBaseListener.h
        analyser/cpp/UserAgentBaseVisitor.h
        analyser/cpp/UserAgentLexer.h
        analyser/cpp/UserAgentListener.h
        analyser/cpp/UserAgentParser.h
        analyser/cpp/UserAgentTreeWalkerBaseListener.h
        analyser/cpp/UserAgentTreeWalkerBaseVisitor.h
        analyser/cpp/UserAgentTreeWalkerLexer.h
        analyser/cpp/UserAgentTreeWalkerListener.h
        analyser/cpp/UserAgentTreeWalkerParser.h
        analyser/cpp/UserAgentTreeWalkerVisitor.h
        analyser/cpp/UserAgentVisitor.h
        src/yauaacpp/linked_hash.h src/yauaacpp/utils/YamlUtils.cpp)
# cxx utils
if(YAUAA_CPP_CXX_STANDARD LESS 17)
    set(CXX_UTILS_DIR "${YAUAA_CPP_SOURCE_DIR}/cxx11")
else()
    set(CXX_UTILS_DIR "${YAUAA_CPP_SOURCE_DIR}/cxx17")
endif()

# shared_ptr use boost
option(YAUAA_CPP_SHAREDPTR_BOOST "Build with boost shared ptr" OFF)
message(STATUS "yauaa-cpp shared_ptr use boost: ${YAUAA_CPP_SHAREDPTR_BOOST}")

if(YAUAA_CPP_SHAREDPTR_BOOST)
    add_definitions(-DYAUAA_CPP_SHAREDPTR_BOOST)
endif()

# hiredis dependency
find_package(yaml-cpp)
if(yaml-cpp_FOUND)
    list(APPEND YAUAA_CPP_YAML_CPP_LIBS yaml-cpp)
else()
    message(FATAL_ERROR "ADD library not found")
endif()


# Build static library
option(YAUAA_CPP_BUILD_STATIC "Build static library" ON)
message(STATUS "yauaa-cpp build static library: ${YAUAA_CPP_BUILD_STATIC}")

if(YAUAA_CPP_BUILD_STATIC)
    set(STATIC_LIB yauaacpp_static)

    add_library(${STATIC_LIB} STATIC ${YAUAA_CPP_SOURCES} ${YAUAA_GENERATED_SOURCE})
    add_library(yauaacpp::${STATIC_LIB} ALIAS ${STATIC_LIB})

    list(APPEND YAUAA_CPP_TARGETS ${STATIC_LIB})

    target_include_directories(${STATIC_LIB} PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${YAUAA_CPP_SOURCE_DIR}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${TLS_SUB_DIR}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${CXX_UTILS_DIR}>
            $<INSTALL_INTERFACE:include>)

    target_link_libraries(${STATIC_LIB} PUBLIC ${YAUAA_CPP_YAML_CPP_LIBS} antlr4-runtime)


    if (WIN32)
        target_compile_definitions(${STATIC_LIB} PRIVATE NOMINMAX)
        set_target_properties(${STATIC_LIB} PROPERTIES CXX_STANDARD ${YAUAA_CPP_CXX_STANDARD})
        set_target_properties(${STATIC_LIB} PROPERTIES OUTPUT_NAME yauaacpp_static)
    else()
        target_compile_options(${STATIC_LIB} PRIVATE "-Wall" "-W" "-Werror")
        set_target_properties(${STATIC_LIB} PROPERTIES OUTPUT_NAME yauaacpp)
    endif()

    set_target_properties(${STATIC_LIB} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
    set_target_properties(${STATIC_LIB} PROPERTIES CXX_EXTENSIONS OFF)

    option(YAUAA_CPP_BUILD_STATIC_WITH_PIC "Build static library with position independent code" ON)
    message(STATUS "yauaa-cpp build static library with position independent code: ${YAUAA_CPP_BUILD_STATIC_WITH_PIC}")

    if(YAUAA_CPP_BUILD_STATIC_WITH_PIC)
        set_target_properties(${STATIC_LIB} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    endif()
endif()

# Build shared library
option(YAUAA_CPP_BUILD_SHARED "Build shared library" ON)
message(STATUS "yauaa-cpp build shared library: ${YAUAA_CPP_BUILD_SHARED}")

if(YAUAA_CPP_BUILD_SHARED)
    set(SHARED_LIB yauaacpp)

    add_library(${SHARED_LIB} SHARED ${YAUAA_CPP_SOURCES} ${YAUAA_GENERATED_SOURCE})
    add_library(yauaacpp::${SHARED_LIB} ALIAS ${SHARED_LIB})
    
    list(APPEND YAUAA_CPP_TARGETS ${SHARED_LIB})

    target_include_directories(${SHARED_LIB} PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${YAUAA_CPP_SOURCE_DIR}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${TLS_SUB_DIR}>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${CXX_UTILS_DIR}>
            $<INSTALL_INTERFACE:include>)
    target_link_libraries(${SHARED_LIB} PUBLIC ${YAUAA_CPP_YAML_CPP_LIBS}  antlr4-runtime)

    if(WIN32)
        target_compile_definitions(${SHARED_LIB} PRIVATE NOMINMAX)
        set_target_properties(${SHARED_LIB} PROPERTIES CXX_STANDARD ${YAUAA_CPP_CXX_STANDARD})
        set_target_properties(${SHARED_LIB} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    else()
        target_compile_options(${SHARED_LIB} PRIVATE "-Wall" "-W" "-Werror")
    endif()

    set_target_properties(${SHARED_LIB} PROPERTIES OUTPUT_NAME yauaacpp)
    set_target_properties(${SHARED_LIB} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
    set_target_properties(${SHARED_LIB} PROPERTIES CXX_EXTENSIONS OFF)
    set_target_properties(${SHARED_LIB} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    set_target_properties(${SHARED_LIB} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR})
endif()

option(YAUAA_CPP_BUILD_TEST "Build tests for yauaacpp" ON)
message(STATUS "yauaa-cpp build test: ${YAUAA_CPP_BUILD_TEST}")

if(YAUAA_CPP_BUILD_TEST)
    add_subdirectory(test)
endif()


install(TARGETS ${YAUAA_CPP_TARGETS}
        EXPORT yauaacpp-targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

set(YAUAA_CPP_CMAKE_DESTINATION share/cmake/yauaacpp)

install(EXPORT yauaacpp-targets
        FILE yauaacpp-targets.cmake
        NAMESPACE yauaacpp::
        DESTINATION ${YAUAA_CPP_CMAKE_DESTINATION})


set(USER_AGENT_YAML_FILES_PATH ${CMAKE_INSTALL_PREFIX}/lib/yauaacpp/UserAgents)
file(GLOB USER_AGENT_YAML_FILES "${YAUAA_RESOURCE_DIR}/UserAgents/*.yaml")
install(FILES ${USER_AGENT_YAML_FILES} DESTINATION ${USER_AGENT_YAML_FILES_PATH})

configure_file (
        "${YAUAA_CPP_SOURCE_DIR}/Config.h.in"
        "${PROJECT_BINARY_DIR}/Config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

# Install headers.
set(HEADER_PATH "yauaacpp")
file(GLOB HEADERS
        "${YAUAA_CPP_SOURCE_DIR}/*.h*"
        "${TLS_SUB_DIR}/*.h"
        "${CXX_UTILS_DIR}/*.h"
        "${YAUAA_CPP_ASYNC_FUTURE_HEADER}/*.h"
        "${PROJECT_BINARY_DIR}/Config.h")

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${HEADER_PATH})
file(GLOB ANALYSE_HEADERS "${YAUAA_CPP_SOURCE_DIR}/analyze/*.h*")
install(FILES ${ANALYSE_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${HEADER_PATH}/analyze)

include(CMakePackageConfigHelpers)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp-config-version.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion)

configure_package_config_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/yauaacpp-config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp-config.cmake"
        INSTALL_DESTINATION ${YAUAA_CPP_CMAKE_DESTINATION})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp-config-version.cmake"
        DESTINATION ${YAUAA_CPP_CMAKE_DESTINATION})

export(EXPORT yauaacpp-targets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp-targets.cmake"
        NAMESPACE yauaacpp::)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/yauaacpp.pc.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp.pc" @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/cmake/yauaacpp.pc"
        DESTINATION "lib/pkgconfig")

# All the Debian-specific cpack defines.
if(${CMAKE_VERSION} VERSION_GREATER 3.6)
  SET(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS "ON")
endif()
if(NOT DEFINED CPACK_DEBIAN_PACKAGE_DEPENDS)
  SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6, libhiredis-dev")
endif()
SET(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
SET(CPACK_DEBIAN_PACKAGE_VERSION "${YAUAA_CPP_VERSION}")
SET(CPACK_DEBIAN_PACKAGE_SOURCE "http://gitlab.adtiming.internal/adtiming/yuaacpp.git")
message(STATUS "Debian package name: ${CPACK_PACKAGE_FILE_NAME}.deb")

# All the common cpack defines.
if(NOT DEFINED CPACK_PACKAGE_NAME)
    SET(CPACK_PACKAGE_NAME "libyauaacpp-dev")
endif()
SET(CPACK_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
SET(CPACK_PACKAGE_DESCRIPTION "A pure C++ client for Redis, based on hiredis.")
SET(CPACK_PACKAGE_CONTACT "anonymous")
SET(CPACK_GENERATOR "DEB")
INCLUDE(CPack)
