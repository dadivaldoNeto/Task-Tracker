
#pragma once

# include "Errors.hpp"
# include "Task.hpp"

#ifdef __TODO
#	define OPERATION 0
#	define ADD_ARGS_SIZE 2
#	define UPDATE_ARGS_SIZE 3
#	define DELETE_ARGS_SIZE 2
#	define MARK_ARGS_SIZE 2
#	define LIST_MAX_ARGS 2
# endif

class	Todo {

	private:
		
	public:
		void	run ( char **args, int len );
};
