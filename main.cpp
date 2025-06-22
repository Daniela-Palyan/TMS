#include "task_manager.h"

int main() {
    TaskManager manager;
    User* user = manager.register_user("alice", "123");

    user = manager.login("alice", "123");
    if (user) {
        manager.add_task(user, "Do Homework", "Finish math and CS", "2025-07-01", "Study", MID, NOT_STARTED);
        user->listTasks();
    } else {
        std::cout << "Login failed!" << std::endl;
    }

    return 0;
}

