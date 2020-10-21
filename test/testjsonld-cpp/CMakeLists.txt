#
# Compile testrunner
#
add_executable(
        UnitTests_jsonld-cpp
        main.cpp
        test_IriUtils.cpp
        test_JsonLdApi.cpp
        test_JsonLdUtils.cpp
        test_DocumentLoader.cpp
        testHelpers.cpp
        testHelpers.h
        test_NodeComparisons.cpp
        test_ObjectComparisons.cpp
        test_UniqueNamer.cpp
        test_DoubleFormatter.cpp
        test_Permutator.cpp
        test_NormalizeUtils.cpp
        test_Sha1.cpp)

target_include_directories(
        UnitTests_jsonld-cpp
        PUBLIC
        ${PROJECT_SOURCE_DIR}/libjsonld-cpp)

target_link_libraries(UnitTests_jsonld-cpp
        jsonld-cpp
        Boost::filesystem
        gtest
        gmock
        rapidcheck_gtest)

add_test(
        NAME UnitTests_jsonld-cpp
        COMMAND UnitTests_jsonld-cpp)

####

set(ALGORITHMS "expand;toRDF;normalize")
foreach(ALGORITHM ${ALGORITHMS})
        message(STATUS "adding ${ALGORITHM}")
        add_executable(
                UnitTests_JsonLdProcessor_${ALGORITHM}_jsonld-cpp
                main.cpp
                test_JsonLdProcessor_${ALGORITHM}.cpp
                testHelpers.cpp
                testHelpers.h)

        target_include_directories(
                UnitTests_JsonLdProcessor_${ALGORITHM}_jsonld-cpp
                PUBLIC
                ${PROJECT_SOURCE_DIR}/libjsonld-cpp)

        target_link_libraries(
                UnitTests_JsonLdProcessor_${ALGORITHM}_jsonld-cpp
                jsonld-cpp
                Boost::filesystem
                gtest
                gmock
                rapidcheck_gtest)

        add_test(
                NAME UnitTests_JsonLdProcessor_${ALGORITHM}_jsonld-cpp
                COMMAND UnitTests_JsonLdProcessor_${ALGORITHM}_jsonld-cpp)
endforeach()
