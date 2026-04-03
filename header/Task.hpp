
#pragma once

#include <string>
#include <chrono>

typedef std::chrono::system_clock::time_point _task_time;

class Task
{

private:
	static int common_id;
	int id;
	std::string desc;
	std::string status;
	_task_time createdAt;
	_task_time updatedAt;

private:
	void _update_time(void);

public:
	Task();
	Task(std::string &u_desc);
	void update_status(const std::string &u_status);
	void update_desc(const std::string &u_desc);

	static int len(void);
	int get_id(void) const;
	std::string get_desc(void) const;
	std::string get_status(void) const;
};
