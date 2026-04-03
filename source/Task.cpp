
#include "Task.hpp"

int Task::common_id = 0;

Task::Task(std::string &u_desc)
{
	id = common_id++;
	desc = std::move(u_desc);
	status = "todo";
	createdAt = get_time();
	updatedAt = createdAt;
}

Task::Task(std::string &u_desc, const std::string &u_status,
		   const std::string &t_created, const std::string &t_update)
{
	id = common_id++;
	desc = std::move(u_desc);
	status = std::move(u_status);
	createdAt = t_created;
	updatedAt = t_update;
}

std::string	Task::get_time( void ) {
	_task_time	current = std::chrono::system_clock::now();

	std::time_t currentTime = std::chrono::system_clock::to_time_t(current);
	std::string time = std::ctime(&currentTime);
	size_t	i = time.find_last_of("\n");
	if (i != time.npos)
		time.erase(i, 1);
	return (time);
}

Task::Task()
{
	id = -1;
}

void Task::update_desc(const std::string &u_desc)
{
	desc = std::move(u_desc);
	updatedAt = get_time();
}

void Task::update_status(const std::string &u_status)
{
	status = std::move(u_status);
	updatedAt = get_time();
}

const int& Task::get_id(void) const
{
	return id;
}

const std::string& Task::get_desc(void) const
{
	return (desc);
}

const std::string& Task::get_status(void) const
{
	return (status);
}

const std::string& Task::get_updated_at(void) const
{
	return (updatedAt);
}

const std::string& Task::get_created_at(void) const
{
	return (createdAt);
}


const int& Task::len(void)
{
	return (common_id);
}
