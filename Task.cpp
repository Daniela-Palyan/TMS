#include "task.h"

Task::Task(const std::string& title, const std::string& descrip, const std::string& deadline, const std::string& category, const std::string& tid, const std:string& uid, int priority, int status) : m_title(title), m_descrip(descrip), m_deadline(deadline), m_category(category), m_task_id(tid), m_uid(uid), m_priority(priority), m_status(status) {}

Task::Task(const Task& other) = default;

Task::Task(Task&& other) noexcept = default;






Task::Task& operator=(const Task& other) = default;


bool Task::operator==(const Task& other) {
    return (m_task_id == other.m_task_id);
}

bool Task::operator!=(const Task& other) {
     return (m_task_id != other.m_task_id);
}

bool Task::operator<(const Task& other) {
	 return (m_priority < other.m_priority);
}

bool Task::operator>(const Task& other) {
	 return (m_priority > other.m_priority);
}

Task& Task::operator++() {
	if (m_status < 2) {
		m_status++;
	}
	return *this;
}

const Task& Task::operator++(int) {
	Task tmp(*this);
	if (m_status < 2) {
		m_status++;
	}
	return tmp;
}

Task& Task::operator--() {
	if (m_ststus > 0) {
		m_status--;
	}
	return *this;
}

const Task& Task::operator--(int) {
	Task tmp(*this);
	if (m_status > 0) {
		m_status--;
	}
	return tmp;
}

friend ostream& Task::operator<<(ostream& os, const Task& other) {
	os << other.m_task_id << ", " << other.m_title << ", " << other.m_deadline;
	return os;
}

//friend ostream& operator>>(const ostream& os, Task& other);

void Task::edit(const std::string& newTitle, const std::string& newDescription, const std::string& newDeadline, const std::string& newCategory, int newPriority) {
	m_title = newTitle;
	m_descrip = newDescription;
	m_deadline = newDeadline;
	m_category = newCategory;
	m_priority = newPriority;
}

void Task::set_status(int status) {
	m_status = status;
}

void Task:: set_prio(int prio) {
	m_priority = prio;
}

void Task::displayTask() const {
	std::cout << "Task ID: " << m_task_id << std::endl << "Title: " << m_title << std::endl << "Description: " << m_description << std::endl << "Deadline: " << m_deadline << std::endl << "Category: " << m_category << std::endl << "Priority: " << m_prio << std::endl << "Status: " << m_status << std::endl;
}

std::string Task::get_task_id() const {
	return m_task_id;
}


