#ifndef LIBJSONLD_CPP_JSONLDUTILS_H
#define LIBJSONLD_CPP_JSONLDUTILS_H

#include "jsonld-cpp/jsoninc.h"

namespace JsonLdUtils {

    /**
     * Is str a reserved JSON-LD keyword?
     *
     * See: https://www.w3.org/TR/json-ld11/#keywords
     */
    bool isKeyword(const std::string& str);

    /**
     * Is str in the form of a reserved JSON-LD keyword?
     *
     * Ex: does str start with '@'?
     *
     * See: https://www.w3.org/TR/json-ld11/#keywords
     */
    bool isKeywordForm(const std::string& str);

    /**
     * Is str possibly an IRI?
     *
     * Note: also checks that str is not a keyword
     */
    bool isIri(const std::string& str);


    /**
     * Is str an absolute IRI?
     */
    bool isAbsoluteIri(const std::string& str);


    /**
     * Is str possibly a relative IRI?
     *
     * Note: also checks that str is not a keyword
     */
    bool isRelativeIri(const std::string& str);

    /**
     * Check if the given IRI ends with a URI general delimiter character.
     *
     * See https://tools.ietf.org/html/rfc3986#section-2.2
     */
    bool iriEndsWithGeneralDelimiterCharacter(const std::string& iri);

    /**
     * Is j a list object?
     *
     * A list object is a map that has a \@list key. It may also have an \@index key, but no other entries.
     *
     * See: https://www.w3.org/TR/json-ld11/#dfn-list-object
     */
    bool isListObject(const nlohmann::ordered_json& j);

    /**
     * Is j a graph object?
     *
     * A graph object must have an \@graph entry, and may also have \@id and \@index entries.
     *
     * See: https://www.w3.org/TR/json-ld11/#dfn-graph-object
     */
    bool isGraphObject(const nlohmann::ordered_json& j);

    /**
     * Is name in the form of a graph name?
     *
     * A graph name must either be an IRI or a blank node name.
     *
     * See: https://www.w3.org/TR/rdf11-concepts/#dfn-graph-name
     */
    bool isGraphNameForm(const std::string& name);

    /**
     * Is j a value object?
     *
     * A value object is a map that has an \@value key.
     *
     * See: https://www.w3.org/TR/json-ld11/#dfn-value-object
     */
    bool isValueObject(const nlohmann::ordered_json& j);

    /**
     * Is j a JSON object?
     *
     * A object in this sense is a JSON object, or a map. Not to be confused with an RDF object.
     */
    bool isObject(const nlohmann::ordered_json& j);

    /**
     * Is j an empty object?
     *
     * An empty object is an empty map.
     */
    bool isEmptyObject(const nlohmann::ordered_json& j);

    /**
     * Is j a default object?
     *
     * A default object is a map that has an \@default key.
     *
     * https://www.w3.org/TR/json-ld11/#dfn-default-object
     */
    bool isDefaultObject(const nlohmann::ordered_json& j);

    /**
     * Is j a node object?
     *
     * https://www.w3.org/TR/json-ld11/#dfn-node-object
     */
    bool isNodeObject(const nlohmann::ordered_json& j);

    /**
     * Is j a JSON array?
     */
    bool isArray(const nlohmann::ordered_json& j);

    /**
     * Is j an empty JSON array?
     */
    bool isEmptyArray(const nlohmann::ordered_json& j);

    /**
     * Is j a JSON array of JSON strings?
     */
    bool isArrayOfStrings(const nlohmann::ordered_json& j);

    /**
     * Is j a JSON scalar?
     */
    bool isScalar(const nlohmann::ordered_json& j);

    /**
     * Is j a JSON array of JSON scalars?
     */
    bool isArrayOfScalars(const nlohmann::ordered_json& j);

    /**
     * Does JSON structure values contain the JSON structure value within it?
     */
    bool deepContains(const nlohmann::ordered_json& values, const nlohmann::ordered_json& value);

    /**
     * Merges value into the array at obj[key], if array at obj[key] does not yet contain it. If
     * array at obj[key] does not exist, create it and add value.
     *
     * @param obj the JSON "object"
     * @param key the key
     * @param value the value to store in array at obj[key]
     */
    void mergeValue(nlohmann::json & obj, const std::string& key, const nlohmann::ordered_json& value);

    /**
     * Add a value to an entry in a JSON object using a specified key.
     *
     * This function is somewhat different than mergeValue() as it may possibly operate
     * recursively if value is an array.
     *
     * See: https://w3c.github.io/json-ld-api/#dfn-add-value
     *
     * @param object the object to add the value to
     * @param key the key
     * @param value the value
     * @param asArray if true, and value of key in the object doesn't exist or is not an
     *                array, set key to a new array containing the value
     */
    void addValue(nlohmann::ordered_json & object, const std::string& key, const nlohmann::ordered_json& value, bool asArray);

    /**
     * Returns whether a json variable contains or equals a given string. We need this
     * function because the json library requires slightly different syntax if the json
     * object is an "object", "array" or "string".
     *
     * @param j the json variable
     * @param value the value to compare with
     * @return true if the object contains or equals the given value
     */
    bool containsOrEquals(nlohmann::ordered_json & j, const std::string& value);
}

#endif //LIBJSONLD_CPP_JSONLDUTILS_H
