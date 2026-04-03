
#pragma once

#include "Errors.hpp"
#include "Json.hpp"
#include "Task.hpp"

#ifdef __TODO
#define MIN_ARGS 2
#define MAX_ARGS 4
#define OPERATION 1
#define ADD_ARGS_SIZE 2
#define UPDATE_ARGS_SIZE 3
#define DELETE_ARGS_SIZE 2
#define MARK_ARGS_SIZE 2
#define LIST_MAX_ARGS 2
#define VALID_ARGS (u_len >= MIN_ARGS && u_len <= MAX_ARGS)
#endif

class Todo
{

private:
	std::fstream file;
	std::vector<Task> tasks;
	std::string op;
	char **args;
	int len;
	bool expect(std::string &data, std::string expected);

public:
	Todo(char **u_args, int u_len);
	~Todo(void);
	void run(void);
	void add(void);
};
