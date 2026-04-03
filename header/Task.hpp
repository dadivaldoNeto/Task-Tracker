
#pragma once

#include <string>
#include <chrono>
#include <ctime>

typedef std::chrono::system_clock::time_point _task_time;

class Task
{

private:
	int id;
	std::string desc;
	std::string status;
	std::string createdAt;
	std::string updatedAt;

private:
	std::string	get_time( void );

public:
	Task();
	Task(std::string &u_desc);
	Task(std::string &u_desc, const std::string &u_status,
		 const std::string &t_created, const std::string &t_update);
	void update_status(const std::string &u_status);
	void update_desc(const std::string &u_desc);

	const static int& len(void);
	const int& get_id(void) const;
	const std::string& get_desc(void) const;
	const std::string& get_status(void) const;
	const std::string& get_updated_at(void) const;
	const std::string& get_created_at(void) const;

public:
	static int common_id;
};
