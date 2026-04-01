
# include "Task.hpp"

int	Task::common_id = 0;

Task::Task(std::string &u_desc) {
	id = common_id++;
	desc = std::move(u_desc);
	status = e_task_status::TODO;
	createdAt = std::chrono::system_clock::now();
	updatedAt = createdAt;
}

void	Task::update_desc(std::string &u_desc) {
	desc = std::move(u_desc);
	_update_time();
}

void	Task::update_status(enum e_task_status &u_status) {
	status = u_status;
	_update_time();
}

void	Task::_update_time( void ) {
	updatedAt = std::chrono::system_clock::now();
}

