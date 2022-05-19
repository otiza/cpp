#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>


template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {

public:
	MutantStack(): std::stack<T, Container>() {}
	~MutantStack() {}
	MutantStack<T, Container>(MutantStack<T, Container> const & src) {*this = src;}
	MutantStack<T, Container> & operator=(MutantStack<T, Container> const & rhs) {
		if (this != &rhs)
			this->c = rhs.c;
		return *this;
	}

	typedef typename Container::iterator iter;

	iter begin() {return this->c.begin();}
	iter end() {return this->c.end();}
};