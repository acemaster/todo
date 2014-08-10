#ifndef _TASK_CPP
#define _TASK_CPP

#include "include/task.h"

task_t::task_t (void) {
	this->m_state = 0;
	this->m_size = 0;
}

task_t::task_t (std::string s, bool state) {
	this->m_content = s;
	this->m_state = state;
	this->m_size = this->m_content.length();
}

task_t::task_t (std::string s) {
	this->m_state = (s[s.find_first_of("]") - 1] == 'x') ? true : false;
	this->m_content = s.substr (s.find_first_of("]") + 2);
	this->m_size = this->m_content.length();
}

std::string task_t::toString (void) {
	std::string t;
	t += (this->m_state == false) ? "[ ] " : "[x] ";
	t += this->m_content;
	return t;
}

std::string task_t::toStringFormatted (void) {
	std::string t;

	if (this->m_state)
		// green color
		t += "\x1b[1;32m✓  " + this->m_content;
	else
		// red color.
		t += "\x1b[1;31m✖  " + this->m_content;

	// reset color
	t += "\x1b[0m";
	return t;
}

bool task_t::equals (task_t* t) {
	if (not this->m_content.compare(t->m_content) and this->m_state == t->m_state) return true;
	else return false;
}

task_t::~task_t (void) {
	this->m_state = 0;
	this->m_content.clear();
	this->m_size = 0;
}


#endif
