
# include "task_cli.hpp"

int	main( int argc, char **argv) {

    if (!VALID_ARGS)
		how_to_use();
	Todo	todo_cli;
	todo_cli.run( argv, argc);
	return (EXIT_SUCCESS);
}
