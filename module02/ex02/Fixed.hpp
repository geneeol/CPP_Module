#pragma once

#include <ostream>

class Fixed
{
  private:
    int val;
    static const int fracBits = 8;

  public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();
    Fixed(const int val);
    Fixed(const float val);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    static int fixedMul(long long a, long long b);
    static int fixedDiv(long long a, long long b);
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    // 후위증감연산자는 const로 반환하는게 타당하다. 복사한 값을 리턴하기 때문에
    // (a++)++같은 연산은 의미가 없다. 따라서 아예 const로 복사된 리턴값을
    // 변경하지 못하도록 하는 것이 타당하다
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    // const 매개변수라면 const 리턴타입을 갖는게 당연히 자연스럽다.
    // https://stackoverflow.com/questions/12696121/function-overloading-with-const-parameters
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);