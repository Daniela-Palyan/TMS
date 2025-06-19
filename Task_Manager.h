class TaskManager{

private:
    std::vector<User*> users; // List of all users.
	User* loggedInUser; 

public:
    TaskManager();
    TaskManager(const TaskManager& other);
    TaskManager(TaskManager&& other) noexcept;
    ~TaskManager();

public:
    void registerUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();

    void addTaskForUser(const Task& task);
    void deleteTaskForUser(const std::string& title);
    void editTaskForUser(const std::string& title, const Task& updatedTask);
    void displayTasksForUser() const;

};
