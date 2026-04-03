#define __TODO
#include "Todo.hpp"

Todo::Todo(char **u_args, int u_len)
{
	if (!VALID_ARGS)
		how_to_use();
	op = u_args[OPERATION]; // Can a hash_map(unordered_map)
	len = --u_len;
	args = (u_args + 2); // It must change
	tasks = Json_std::task_from_json();
	if (tasks.empty())
		Task::common_id = 0;
};

Todo::~Todo()
{
	Json_std::task_to_json(tasks);
}

void Todo::run(void)
{
	if (this->op == "add")
		return (add());
	if (op == "update")
		return (update());
	if (op == "delete")
		return (delete_task());
	if (op == "mark-in-progress")
		return (mark_in_progress());
	if (op == "mark-done")
		return (mark_done());
	if (op == "list")
		return (list());
	how_to_use();
}

void Todo::add(void)
{
	if (len != ADD_ARGS_SIZE || !*args)
		how_to_use();
	std::string desc(*args);
	Task task(desc);
	tasks.push_back(task);
	std::cout << "Task added successfully (ID: ";
	std::cout << task.get_id() << ")" << std::endl;
}

void Todo::list(void)
{
	if (len > MARK_ARGS_SIZE)
		how_to_use();
	std::string argument;
	if (*args)
	{
		argument = *args;
		if (!(argument == "done" || argument == "todo" || argument == "in-progress"))
		{
			std::cout << "Invalid Option" << std::endl;
			return;
		}
	}
	if (tasks.empty())
	{
		std::cout << "Is empty. Add a task" << std::endl;
		return;
	}
	for (size_t i = 0; i < tasks.size(); i++)
	{
		if (!(argument.empty() || argument == tasks.at(i).get_status()))
			continue;
		std::cout << "Id : " << tasks.at(i).get_id() << std::endl;
		std::cout << "Description : " << tasks.at(i).get_desc() << std::endl;
		std::cout << "Status : " << tasks.at(i).get_status() << std::endl;
	}
}

void Todo::delete_task(void)
{
	if (len != DELETE_ARGS_SIZE)
		how_to_use();
	int the_id = std::atoi(*args);
	for (size_t i = 0; i < tasks.size(); i++)
	{
		if (!(the_id == tasks.at(i).get_id()))
			continue;
		tasks.erase(tasks.begin() + i);
		std::cout << "Task deleted successfully (ID: " << the_id;
		std::cout << ")" << std::endl;
		return;
	}
	task_not_found();
}

void Todo::mark_done(void)
{
	if (len != MARK_ARGS_SIZE)
		how_to_use();
	int the_id = std::atoi(*args);
	for (size_t i = 0; the_id >= 0 && i < tasks.size(); i++)
	{
		if (!(the_id == tasks.at(i).get_id()))
			continue;
		tasks.at(i).update_status("done");
		std::cout << "Task marked-done successfully (ID: " << the_id;
		std::cout << ")" << std::endl;
		return;
	}
	task_not_found();
}

void Todo::mark_in_progress(void)
{
	if (len != MARK_ARGS_SIZE)
		how_to_use();
	int the_id = std::atoi(*args);
	for (size_t i = 0; the_id >= 0 && i < tasks.size(); i++)
	{
		if (!(the_id == tasks.at(i).get_id()))
			continue;
		tasks.at(i).update_status("in-progress");
		std::cout << "Task marked-in-progress successfully (ID: " << the_id;
		std::cout << ")" << std::endl;
		return;
	}
	task_not_found();
}

void Todo::update(void) {
	if (len != UPDATE_ARGS_SIZE)
		how_to_use();
	int the_id = std::atoi(*args++);
	for (size_t i = 0; the_id >= 0 && i < tasks.size(); i++)
	{
		if (!(the_id == tasks.at(i).get_id()))
			continue;
		tasks.at(i).update_desc(std::string(*args));
		std::cout << "Task updated successfully (ID: " << the_id;
		std::cout << ")" << std::endl;
		return;
	}
	task_not_found();
}