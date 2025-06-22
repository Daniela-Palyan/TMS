#include <vector>
#include <string>
#include "Task.h"


class User{
private:
    std::string m_id;
    std::string m_name;
    std::string m_passwd;
    std::vector<Task*> m_tasks;
    bool is_logged;

public:
    User(const std::string& id, const std::string& name, const std::string& psw);
    User(const User& other);
    User(User&& other) noexcept;
    ~User();

public:
    User& operator=(User& other);
    friend ostream& operator<<(ostream& os, const User& other);
//    friend ostream& operator>>(const ostream& os, User& other);
    bool operator bool() const;

public:
    void addTask(Task* task);
    void deleteTask(const std::string& tid);
    bool login(const std::string& psw);
    void logout();
    void listTasks() const;
    Task* searchTask(const std::string& title);
};
