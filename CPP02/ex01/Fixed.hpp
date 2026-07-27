#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

    private:

    public:

    Fixed(const int );
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);

    float toFloat(void) const;
    int toInt(void) const;
};

#endif