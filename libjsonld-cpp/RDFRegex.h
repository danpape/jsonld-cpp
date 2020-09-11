#ifndef LIBJSONLD_CPP_RDFREGEX_H
#define LIBJSONLD_CPP_RDFREGEX_H

#include <string>

namespace RDFRegex {
    const std::string EOLN(R"((?:\r\n)|(?:\n)|(?:\r))");
    const std::string WS(R"([ \t]+)");
    const std::string WSO(R"([ \t]*)");
    const std::string EMPTY("^" + WSO + "$");

    const std::string IRI(R"((?:<([^>]*)>))");
    const std::string BNODE(R"((_:(?:[A-Za-z][A-Za-z0-9]*)))");
    const std::string PLAIN(R"lit("([^"\\]*(?:\\.[^"\\]*)*)")lit");
    const std::string DATATYPE("(?:\\^\\^" + IRI + ")");
    const std::string LANGUAGE("(?:@([a-z]+(?:-[a-zA-Z0-9]+)*))");
    const std::string LITERAL("(?:" + PLAIN + "(?:" + DATATYPE + "|" + LANGUAGE + ")?)");

    const std::string SUBJECT("(?:" + IRI + "|" + BNODE + ")" + WS);
    const std::string PROPERTY(IRI + WS);
    const std::string OBJECT("(?:" + IRI + "|" + BNODE + "|" + LITERAL + ")" + WSO);
    const std::string GRAPH("(?:\\.|(?:(?:" + IRI + "|" + BNODE + ")" + WSO + "\\.))");

    const std::string QUAD("^" + WSO + SUBJECT + PROPERTY + OBJECT + GRAPH + WSO + "$");

    const std::string HEX("[0-9A-Fa-f]");
    const std::string UCHAR_MATCHED(R"(\u005C(?:([tbnrf\"'])|(?:u()" + HEX + "{4}))|(?:U(" + HEX + "{8})))");


}

#endif //LIBJSONLD_CPP_RDFREGEX_H
