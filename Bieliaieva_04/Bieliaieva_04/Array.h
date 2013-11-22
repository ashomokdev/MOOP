#ifndef _ARRAY_
#define _ARRAY_
#include <string>
#include <iostream>
using namespace std;

//Масив з size елементів типу Elem
template <size_t n, typename Elem> class Array
{
private:
	size_t _size;
	Elem * _pElem;
	mutable Elem * _pCurrent;
	Elem * _pEnd;

public:
	class BadArray; //Клас для обробки помилкових ситуацій залежить від двох параметрів size і Elem, він вкладений, а тому теж параметризований тип
	explicit Array();
	~Array();
	Array(const Array&);
	Array& operator= (const Array&);

	Elem& operator[](size_t i); //Модифікатор елементу масива
	const Elem& operator[](size_t i) const; //Селектор елементу масива
	size_t size() const {return _size;} //Розмір масива (селектор)
	//iterators
	void start() const {_pCurrent=_pElem;}
	bool finish() const { return _pCurrent == _pEnd;}
	const Array& operator++() const { _pCurrent++; return *this;}
	const Elem& get() const { return *_pCurrent;}	
	bool operator== (const Array&) const;
	bool operator!= (const Array&) const;
};

 template<size_t n, typename Elem>
 ostream& operator<<(ostream &, const Array<n, Elem> &);

template<size_t n, typename Elem> class Array<n, Elem>::BadArray{
private:
	string _reason;
	size_t _index;
public:
	BadArray(string reason="", size_t index=0):_reason(reason), _index(index){cout << getReason() << " - index " << _index << endl << endl;}
	~BadArray(){}
	const string& getReason() const{return _reason;};
};

#include "Array.cpp"
#endif


