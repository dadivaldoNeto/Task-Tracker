
#pragma once

# include "Errors.hpp"
# include "Task.hpp"
# include <fstream>

#ifdef __TODO
# 	define PUT_IN_QUOTES(x) "\"" << (x) << "\""
#	define FILE_NAME "file.json"
#	define MIN_ARGS 2
#	define MAX_ARGS 4
#	define OPERATION 1
#	define ADD_ARGS_SIZE 2
#	define UPDATE_ARGS_SIZE 3
#	define DELETE_ARGS_SIZE 2
#	define MARK_ARGS_SIZE 2
#	define LIST_MAX_ARGS 2
#	define VALID_ARGS (u_len >= MIN_ARGS && u_len <= MAX_ARGS)
# endif

class	Todo {

	private:
		std::fstream		file;
		std::vector<Task>	tasks;
		std::string			op;
		char				**args;
		int					len;
		void				task_to_json( void );
		void				json_to_task( void );

	public:
		Todo(char **u_args, int u_len, bool close_if_fail);
		~Todo (void);
		void	run ( void );
		void	add ( void );
};
