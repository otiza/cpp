#include "Span.hpp"

Span::Span(): sz(0), x(0)
{
}

Span::Span(unsigned int N): sz(N), x(0)
{
	std::cout << "Span constructor for size called" << std::endl;
	this->_storage.reserve(this->getSize());
}

Span::Span(const Span &src): sz(src.getSize()), x(src.getPos())
{
	std::cout << "Span copy Constructor called" << std::endl;
	*this = src;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span	&Span::operator=(const Span &src)
{
	std::cout << "Span assignation called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	Span::addNumber(int number)
{
	if ((this->x != 0 && this->_storage.empty() == true) || this->_storage.max_size() < this->getSize())
		throw (Span::VectorInvalidException());
	if (this->getPos() + 1 > this->getSize())
		throw (Span::ArrayFullException());
	else
	{
		this->x++;
		this->_storage.push_back(number);
	}
}

void	Span::addNumber(unsigned int range, time_t seed)
{
	srand(seed);
	for (size_t i = 0; i < range; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}

unsigned int	Span::shortestSpan(void) const
{
	if (this->x == 1 || this->_storage.size() == 1)
		throw (Span::ComparisonInvalidException());

	std::vector<int> v(this->_storage);

	std::sort (v.begin(), v.end());

	unsigned int ret = UINT_MAX;
	std::vector<int>::iterator temp_it = v.begin();
	std::vector<int>::iterator temp_it_next = v.begin() + 1;
	while (temp_it_next != v.end())
	{
		if ((unsigned int)(*temp_it_next - *temp_it) < ret)
		{
			ret = *temp_it_next - *temp_it;
		}
		++temp_it_next;
		++temp_it;
	}
	return (ret);
}

unsigned int	Span::longestSpan(void)const
{
	if (this->x == 1 || this->_storage.size() == 1)
		throw (Span::ComparisonInvalidException());
	std::vector<int> v(this->_storage);
	std::vector<int>::iterator low, high;
	std::sort (v.begin(), v.end());
	high = max_element(v.begin(),v.end());
	low =  min_element(v.begin(),v.end());
	return (std::abs(*high - *low));
}

unsigned int	Span::getSize() const
{
	return (this->sz);
}

unsigned int	Span::getPos() const
{
	return (this->x);
}

const char	*Span::VectorInvalidException::what() const throw()
{
	return ("Error: error in vector");
}

const char	*Span::ArrayFullException::what() const throw()
{
	return ("Error: array full");
}

const char	*Span::ComparisonInvalidException::what() const throw()
{
	return ("Error: one element");
}