#include <iostream>
#include <string>

enum Prio {LOW, MID, HIGH, URGENT};
enum Stat {NOT_STARTED, IN_PROGRESS, COMPLETED};


class Task{

private:
	std::string m_title;
	std::string m_descrip;
	std::string m_deadline; //(format: YYYY-MM-DD)
	std::string m_category;
	std::string m_task_id;
	std::string m_uid;
	int m_priority; //(1 = Low, 2 = Medium, 3 = High)
	int m_status;

public:
    Task(const std::string& title, const std::string& descrip, const std::string& deadline, const std::string& category, std::string tid, std::string uid, int priority, int status);
    Task(const Task& other) = default;
    Task(Task&& other) noexcept = default;
    ~Task() = default;

public:
    Task& operator=(const Task& other);

    bool operator==(const Task& other);
    bool operator!=(const Task& other);
    bool operator<(const Task& other);
    bool operator>(const Task& other);

    Task& operator++();
    const Task& operator++(int);
    Task& operator--();
    const Task& operator--(int);

    friend std::ostream& operator<<(std::ostream& os, const Task& other);
    //friend ostream& operator>>(const ostream& os, Task& other);

public:

    void edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, int newPriority);
    void set_status(int status);
    void set_prio(int prio);
    void display_info() const;
    std::string get_task_id() const;

};
