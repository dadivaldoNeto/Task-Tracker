# define __TODO
# include "Todo.hpp"


void	Todo::run ( char **args, int len) {

		std::string op(args[OPERATION]);
	
		if ( op == "add"  && len == ADD_ARGS_SIZE) {
			return ;	
		}
		if ( op == "update"  && len == UPDATE_ARGS_SIZE) {
			return ;	
		}
		if ( op == "delete"  && len == DELETE_ARGS_SIZE) {
			return ;	
		}
		if ( op == "mark-in-progress"  && len == MARK_ARGS_SIZE) {
			return ;
		}
		if ( op == "mark-done"  && len == MARK_ARGS_SIZE) {
			return ;
		}
		if ( op == "list"  && len <= LIST_MAX_ARGS) {
			return ;
		}
		how_to_use();
}

