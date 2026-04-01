#pragma once

# ifndef TASK_CLI_H
# define TASK_CLI_H

# include "Todo.hpp"
# include "Errors.hpp"
# include <iostream>


# define MAX_ARGS 3
# define MIN_ARGS 1

# define VALID_ARGS (argc--, argv++, (argc >= MIN_ARGS && argc <= MAX_ARGS))

# endif
