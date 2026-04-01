
# pragma once

# include <string>
# include <cstdint>
# include <chrono>


typedef std::chrono::system_clock::time_point _task_time; 

enum class e_task_status {
    TODO,
    IN_PROGRESS,
    DONE
};

class Task {

    private:
		static	int			common_id;
        int					id;
        std::string         desc;
        enum e_task_status    status;
        _task_time          createdAt;
        _task_time          updatedAt;
		void	_update_time ( void );
		Task();

    public:
		Task	(std::string &u_desc);
		void	update_status(enum e_task_status &u_status);
        void    update_desc(std::string &u_desc);

};

