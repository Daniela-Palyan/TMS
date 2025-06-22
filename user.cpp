#include <iostream>
#include "user.h"

User::User(const std::string& id, const std::string& name, const std::string& psw) : m_id(id), m_name(name), m_passwd(psw) {}

User::User(const User& other) : m_id(other.m_id), m_name(other.m_name), m_passwd(other.m_passwd), is_logged(other.is_logged) {
	for (int i = 0; i < other.m_tasks.size(); ++i) {
		m_task.push_back(new Task(other.m_tasks[i]));
	}
}

User::User(User&& other) noexcept {
	m_id = std::move(other.m_id);
	m_name = std::move(other.m_name);
	m_passwd = std::move(other.m_passwd);
	m_tasks = std::move(other.m_tasks);
	is_logged = other.is_logged;
	other.m_tasks = {};
}

User::~User() {
	for (int i = 0; i < m_tasks.siez(); ++i) {
		delete m_tasks[i];
	}
	m_tasks = {};
}

User& User::operator=(const User& other) {
	if (this == &other) {
		return *this;
	}
	for (int i = 0; i < m_tasks.size(); ++i) {
		delete m_tasks[i];
	}
	m_tasks = {};

	m_id = other.m_id;
	m_name = other.m_name;
	m_passwd = other.m_passwd;
	is_logged = other.is_logged;

	for (int i = 0; i < other.m_tasks.size(); ++i) {
		m_tasks.pushback(new Task(*other.m_tasks[i]));
	}
	return *this;
}

User::operator bool() const {
	return is_logged;
}

std::ostream& operator<<(std::ostream&os, const User& other) {
	os << "Username: " << other.m_name << ", Tasks: " << other.m_tasks.size();
	return os;
}

void add_task(Task* task) {
	m_tasks.push_back(task);
}

void delete_task(const std::string& tid) {
	for (int i = 0; i < m_tasks.size(); ++i) {
		if (m_tasks[i]->get_task_id() == tid) {
			delete m_tasks[i];
			for (int j = i + 1; j < m_tasks.size(); ++j) {
				m_tasks[j - 1] = m_tasks[j];
			}
			m_tasks.pop_back();
			break;
		}
	}
}

bool login(const std::string& psw) {
	is_logged = (m_psw == psw);
	return is_logged;
}

void logout() {
	is_logged = false;
}

void list_tasks() const {
	for (int i = 0; i < m_tasks.size(); ++i) {
		m_tasks[i]->display_info();
	}
}

Task* searchTask(const std::string& title) {
	for (int i = 0; i < m_tasks.size(); ++i) {
		if(m_tasks[i]->m_title == title) {
			return m_tasks[i];
		}
	}
}




