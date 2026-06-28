#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>

class Vect2 {
	private:
		int x;
		int y;
	public:
		Vect2();
		Vect2(int num1, int num2);
		Vect2(const Vect2& source);
		Vect2& operator=(const Vect2& source);

		int operator[](int index) const;
		int& operator[](int index);

		Vect2 operator-() const;
		Vect2 operator*(int num) const;

		Vect2& operator*=(int num);

		Vect2& operator+=(const Vect2& obj);
		Vect2& operator-=(const Vect2& obj);
		Vect2& operator*=(const Vect2& obj);

		Vect2 operator+(const Vect2& obj) const;
		Vect2 operator-(const Vect2& obj) const;
		Vect2 operator*(const Vect2& obj) const;

		Vect2& operator++();
		Vect2 operator++(int);
		Vect2& operator--();
		Vect2 operator--(int);

		bool operator==(const Vect2& obj) const;
		bool operator!=(const Vect2& obj) const;

		~Vect2();
};

#endif