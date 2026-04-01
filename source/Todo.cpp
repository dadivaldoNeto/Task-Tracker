# define __TODO
# include "Todo.hpp"

Todo::Todo(char **u_args, int u_len, bool close_if_fail) {
	if (!VALID_ARGS) {
		how_to_use();
		if (close_if_fail)
			exit(EXIT_FAILURE);
	}
	op = u_args[OPERATION]; // Change with a hash_map
	len = --u_len;
	args = (u_args + 2); // It must change
	json_to_task();
};

void	Todo::json_to_task( void ) {

		file.open(FILE_NAME, std::fstream::in);
		file.close();
}

void	Todo::task_to_json( void ) {

	file.open(FILE_NAME, std::fstream::out | std::fstream::trunc);
	int 	i = 0;
	file << "[" << std::endl;
	for (; i < Task::len() - 1; i++) {
		Task &tmp = tasks[i];
		file << "\t{" << std::endl;
		file << "\t\t\"id\" : " <<  tmp.get_id() << ",\n";
		file << "\t\t\"description\" : " << PUT_IN_QUOTES(tmp.get_desc()) << ",\n";
		file << "\t\t\"status\" : " <<  PUT_IN_QUOTES(tmp.get_status()) << std::endl;	
		file << "\t}," << std::endl;
	}
	Task &tmp = tasks[i];
	file << "\t{" << std::endl;
	file << "\t\t\"id\" : " << tmp.get_id() << ",\n";
	file << "\t\t\"description\" : " << PUT_IN_QUOTES(tmp.get_desc()) << ",\n";
	file << "\t\t\"status\" : " <<  PUT_IN_QUOTES(tmp.get_status()) << std::endl;
	file << "\t}" << std::endl;
	file << "]" << std::endl;
	file.close();
}

Todo::~Todo( void ) {
	task_to_json();
}

void	Todo::run ( void ) {

		if (this->op == "add")
			return (add());
		if ( op == "update")
			return ;
		if ( op == "delete")
			return ;
		if ( op == "mark-in-progress")
			return ;
		if ( op == "mark-done")
			return ;
		if ( op == "list")
			return ;
		how_to_use();
		exit (EXIT_FAILURE);
}

void	task_to_json( void ) {
}

void	Todo::add ( void ) {
	if (len != ADD_ARGS_SIZE || std::string(*args).empty()) {
		how_to_use();
		exit (EXIT_FAILURE);
	}
	std::string desc(*args);
	Task task(desc);
	tasks.push_back(task);
	std::cout << "Task added successfully (ID: "; 
	std::cout << task.get_id() << ")" << std::endl;
}

