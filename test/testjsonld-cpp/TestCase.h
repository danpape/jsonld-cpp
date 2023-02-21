#ifndef LIBJSONLD_CPP_TESTCASE_H
#define LIBJSONLD_CPP_TESTCASE_H

#include <nlohmann/json.hpp>
#include "TestCaseOptions.h"

#include <string>
#include <set>
#include <jsonld-cpp/JsonLdOptions.h>

class TestCase {
public:
    explicit TestCase(const std::string &testsBase);

    static TestCase create(nlohmann::json o, const std::string& manifestUri, const std::string& manifestBase, const std::string& baseUri);



    std::string id;

    std::string name;

    std::string input;

    std::string context;

    std::string expect;

    std::string frame;

    std::string expectErrorCode;

    std::string baseUri;

    std::string uri;

    std::set<std::string> type;

    std::string testsBase;

    TestCaseOptions options;

    JsonLdOptions getOptions();

};


#endif //LIBJSONLD_CPP_TESTCASE_H
