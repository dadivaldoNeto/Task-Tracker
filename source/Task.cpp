
# include "Task.hpp"

int	Task::common_id = 0;

Task::Task(std::string &u_desc) {
	id = common_id++;
	desc = std::move(u_desc);
	status = "TODO";
	createdAt = std::chrono::system_clock::now();
	updatedAt = createdAt;
}

void	Task::update_desc(const std::string &u_desc) {
	desc = std::move(u_desc);
	_update_time();
}

void	Task::update_status(const std::string &u_status) {
	status = std::move(u_status);
	_update_time();
}

void	Task::_update_time( void ) {
	updatedAt = std::chrono::system_clock::now();
}

int	Task::get_id( void ) const {
	return id;
}

std::string	Task::get_desc ( void ) const {
	return (desc);
}

std::string	Task::get_status ( void ) const {
	return (status);
}

int	Task::len( void ) {
	return (common_id);
}