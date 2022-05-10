#include "Fixed.hpp"
Fixed::Fixed(void)
{
    this->fv = 0;
    std::cout<< "default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& src)
{
    this->fv = src.fv;
    std::cout<< "copy constructor called"<<std::endl;
}
Fixed::Fixed(const int i)
{
    setRawBits(i << this->bits);
    std::cout << "Int const called" <<std::endl;
}
Fixed::Fixed(const float i)
{
    this->fv = roundf(i * (1 << this->bits));
    std::cout<<"float constructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& fx)
{
    this->fv = fx.getRawBits();
    std::cout<< "assignement called"<<std::endl;
    return(*this);
}
int Fixed::getRawBits(void) const
{
    return(this->fv);
}
void	Fixed::setRawBits(int const raw)
{
    this->fv = raw;
}
float		Fixed::toFloat(void)const
{
    return((float)getRawBits() / (1 << this->bits));
}
int			Fixed::toInt(void)const
{
    return((int)getRawBits() >> this->bits);
}
Fixed::~Fixed()
{
    std::cout<<"destructor called"<<std::endl;
}
std::ostream& operator<<(std::ostream &o, Fixed const &ref)
{
    return(o << ref.toFloat());
}

//operator overload
bool		Fixed::operator> (const Fixed& fix) const
{
	return (this->fv > fix.fv);
}
bool		Fixed::operator< (const Fixed& fix) const
{
	return (this->fv < fix.fv);
}
bool		Fixed::operator<= (const Fixed& fix) const
{
	return (this->fv <= fix.fv);
}
bool		Fixed::operator>= (const Fixed& fix) const
{
	return (this->fv >= fix.fv);
}
bool		Fixed::operator== (const Fixed& fix) const
{
	return (this->fv == fix.fv);
}
bool		Fixed::operator!= (const Fixed& fix) const
{
	return (this->fv != fix.fv);
}

Fixed&		Fixed::operator++ ()
{
	this->fv += 1;
	return (*this);
}
Fixed		Fixed::operator++ (int)
{
	Fixed	tmp;
    tmp = (*this);
	this->fv += 1;
	return (tmp);
}
Fixed&		Fixed::operator-- ()
{
	this->fv -= 1;
	return (*this);
}
Fixed		Fixed::operator-- (int)
{
	Fixed	tmp;
    tmp = (*this);
	this->fv -= 1;
	return (tmp);
}
Fixed		Fixed::operator+ (const Fixed& fix) const
{
	return (Fixed(this->toFloat() + fix.toFloat()));
}
Fixed		Fixed::operator- (const Fixed& fix) const
{
	return(Fixed(this->toFloat() - fix.toFloat()));
}
Fixed		Fixed::operator* (const Fixed& fix) const
{
	return(Fixed(this->toFloat() * fix.toFloat()));
}
Fixed		Fixed::operator/ (const Fixed& fix) const
{
	return(Fixed(this->toFloat() / fix.toFloat()));
}
const Fixed&		Fixed::max(const Fixed& f1,const Fixed& f2)
{
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    else
        return f2;
}
const Fixed&		Fixed::min(const Fixed& f1,const Fixed& f2)
{
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    else
        return f2;
}
Fixed&		Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    else
        return f2;
}
Fixed&		Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    else
        return f2;
}

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout <<a.max( a, b ) << std::endl;
return(0);
}