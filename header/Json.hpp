#pragma once

#include "Task.hpp"
#include <fstream>
#include <cctype>
#include <regex>
#include <vector>

#define MATCH_EXP "\"[^\"]*\"|[0-9]+|(\\S)"
#define PUT_IN_QUOTES(x) "\"" << (x) << "\""
#define JSON_FILE "db/file.json"

# define KEY(x) std::string("\t\t\"") + (x) + std::string("\" : ")

# define CREATED_AT (char *)"\"created_at\""
# define UPDATED_AT (char *)"\"updated_at\""


/*

PARSER_JSON GRAMMAR

PARSE = '[' <OBJECT> {, <OBJECT>} ']' ? EOI ?

OBJECT = '{' <ID>, <DESC>, <STATUS>, <CREATED_AT>, <UPDATED_AT> '}'

ID = "id" : <NUM>
DESC = "description" : '"' <STRING> '"'
STATUS = "status" : '"' <STRING> '"'
CREATED_AT = "created_at" : <AnyThing>
UPDATED_AT = "updated_at" : <AnyThing>


NUM = ANY INT NUMBER
STRING = ANY NON EMPTY STRING
*/

namespace Json_std
{
	std::vector<std::string> get_tokens(void);

	bool expect(std::vector<std::string> &tokens, std::string chars, size_t &index);

	int id(std::vector<std::string> &tokens, size_t &index);

	void erse_start_quotes(std::string &str);

	std::string description(std::vector<std::string> &tokens, size_t &index);

	std::string status(std::vector<std::string> &tokens, size_t &index);

	Task objects(std::vector<std::string> &tokens, size_t &index);

	std::vector<Task> task_from_json(void);

	void task_to_json(std::vector<Task> &tasks);

}
