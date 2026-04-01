
# include "Errors.hpp"

void    how_to_use() {

    std::cout << "Invalid Arguments" << std::endl;
    std::cout << "Usage:" << std::endl << std::endl;
    std::cout << "./task-cli add \"<Content>\"" << std::endl;
    std::cout << "./task-cli update <task-id> \"<Content>\"" << std::endl;
    std::cout << "./task-cli delete <task-id> " << std::endl;
    std::cout << "./task-cli [mark-done | mark-in-progress] <task-id>" << std::endl;
    std::cout << "./task-cli [list | list todo | list done | list in-progress]" << std::endl;
	exit(EXIT_FAILURE);
}
