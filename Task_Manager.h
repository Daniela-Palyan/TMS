#include <vector>
#include "user.h"

class TaskManager{

private:
    std::vector<User*> m_users; // List of all users.
	std::vector<Task*> m_all_tasks;

public:
    TaskManager();
    TaskManager(const TaskManager& other);
    TaskManager(TaskManager&& other) noexcept;
    ~TaskManager();

public:
	User* registre_user(const std::string& name, const std::string& psw);
	User* login(const std::string& name, const std::string& psw);
	void logout(User* user);
	Task* add_task (User* user,const std::string& title, const std::string& desc, const std::string& deadline, const std::strng& category, int prio, int status);

};
