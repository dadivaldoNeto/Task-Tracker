#define __TODO
#include "Todo.hpp"

Todo::Todo(char **u_args, int u_len)
{
	if (!VALID_ARGS)
		how_to_use();
	op = u_args[OPERATION]; //Can Change with a hash_map
	len = --u_len;
	args = (u_args + 2); // It must change
	tasks = Json_std::task_from_json();
};

Todo::~Todo() {
	if (tasks.size() > 0)
		Json_std::task_to_json(tasks);
}

void Todo::run(void)
{
	if (this->op == "add")
		return (add());
	if (op == "update")
		return;
	if (op == "delete")
		return;
	if (op == "mark-in-progress")
		return;
	if (op == "mark-done")
		return;
	if (op == "list")
		return;
	how_to_use();
	exit(EXIT_FAILURE);
}

void Todo::add(void)
{
	if (len != ADD_ARGS_SIZE || std::string(*args).empty())
	{
		how_to_use();
		exit(EXIT_FAILURE);
	}
	std::string desc(*args);
	Task task(desc);
	tasks.push_back(task);
	std::cout << "Task added successfully (ID: ";
	std::cout << task.get_id() << ")" << std::endl;
}
