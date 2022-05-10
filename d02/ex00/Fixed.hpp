#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

class Fixed
{
private:
    int fv;
    static const int bits=8;
public:
    Fixed(void);
	Fixed(const Fixed& src);
    Fixed(const int i);
	Fixed(const float i);
	Fixed& operator= (const Fixed& as);
    ~Fixed(void);
bool		operator> (const Fixed& fix) const;
bool		operator< (const Fixed& fix) const;
bool		operator<= (const Fixed& fix) const;
bool		operator>= (const Fixed& fix) const;
bool		operator== (const Fixed& fix) const;
bool		operator!= (const Fixed& fix) const;

Fixed&		operator++ ();
Fixed		operator++ (int i);
Fixed&		operator-- ();
Fixed		operator-- (int);
Fixed		operator+ (const Fixed& fix) const;
Fixed		operator- (const Fixed& fix) const;
Fixed		operator/ (const Fixed& fix) const;
Fixed		operator* (const Fixed& fix) const;
const Fixed &max(const Fixed &f1, const Fixed &f2);
Fixed&		max(Fixed& f1, Fixed& f2);
const Fixed &min(const Fixed &f1, const Fixed &f2);
Fixed&		min(Fixed& f1, Fixed& f2);
int			getRawBits(void) const;
void		setRawBits(int const raw);
float		toFloat(void)const;
int			toInt(void)const;
};
std::ostream& operator<<(std::ostream &o, Fixed const &ref);



