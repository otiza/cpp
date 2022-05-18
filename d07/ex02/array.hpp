#pragma once



class INDEX: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return " Invalid index";
	}
};

template< typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
	// Constructors
		Array(): _size(0)
		{
			std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
			this->_array = new T[this->_size];

		}

		Array(unsigned int size): _size(size)
		{
			std::cout << "Constructor for an Array of size " << size << " called" << std::endl;
			this->_array = new T[this->_size];

		}

		Array(const Array &src): _size(src.size())
		{
			std::cout << "Copy Constuctor called" << std::endl;
			this->_array = NULL;
			*this = src;
		}

		~Array()
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}

		Array &operator=(const Array &src)
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}

		T &operator[]( unsigned int index )
		{
			if (index >= this->_size || this->_array == NULL)
			{
				std::cout << "index: " << index << std::endl;
				throw INDEX();
			}
			return (this->_array[index]);
		}


		unsigned int size() const
		{
			return (this->_size);
		}


};

