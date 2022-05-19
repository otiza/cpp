#pragma once


#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>


class Span
{
	private:
		std::vector<int> _storage;
		unsigned int sz;
		unsigned int x;

		Span();

	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);
		void addNumber(int number);
		void addNumber(unsigned int range, time_t seed);
		unsigned int shortestSpan()const;
		unsigned int longestSpan()const;
		unsigned int getSize()const;
		unsigned int getPos()const;
	class	VectorInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	ArrayFullException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	ComparisonInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};
