#include "Task_Manager.h"
#include <iostream>

User* TaskManager::register_user(const std::string& uname, const std::string& passwd) {
    std::string id = "USER_" + std::to_string(m_users.size() + 1);
    User* user = new User(id, uname, passwd);
    m_users.push_back(user);
    return user;
}

User* TaskManager::login(const std::string& uname, const std::string& passwd) {
    for (auto* user : m_users)
        if (user->m_name == uname && user->login(passwd))
            return user;
    return nullptr;
}

void TaskManager::logout(User* user) {
    if (user) user->logout();
}

Task* TaskManager::add_task(User* user, const std::string& title, const std::string& desc,
                            const std::string& deadline, const std::string& category,
                            int prio, int status) {
    std::string tid = "TASK_" + std::to_string(m_all_tasks.size() + 1);
    Task* task = new Task(tid, user->m_id, title, desc, deadline, category, prio, status);
    user->add_task(task);
    m_all_tasks.push_back(task);
    return task;
}


