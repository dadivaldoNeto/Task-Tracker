
#include "task_cli.hpp"

int main(int argc, char **argv)
{

	Todo todo_cli(argv, argc);
	todo_cli.run();
	return (EXIT_SUCCESS);
}
