#pragma once

#include "Task.hpp"
#include <fstream>
#include <cctype>
#include <regex>
#include <vector>

#define MATCH_EXP "\"[^\"]*\"|[0-9]+|(\\S)"
#define PUT_IN_QUOTES(x) "\"" << (x) << "\""
#define JSON_FILE "file.json"

/*

PARSER_JSON GRAMMAR

PARSE = '[' <OBJECT> {, <OBJECT>} ']' ? EOI ?

OBJECT = '{' <ID>, <DESC>, <STATUS> '}'

ID = "id" : <NUM>
DESC = "description" : '"' <STRING> '"'
STATUS = "status" : '"' <STRING> '"'

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
