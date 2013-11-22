#ifndef _ARRAY_CPP_
#define _ARRAY_CPP_
#include "Array.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

template <size_t n, typename Elem> Array<n, Elem>::Array(): _size(n), _pElem (new Elem[_size]), _pCurrent(_pElem), _pEnd(_pElem+_size){
#ifndef NDEBUG
	cout << "Array of size (" << _size << ')' << " created" << endl;
#endif
	assert(_pElem != 0);
	return;
}

template<size_t n, typename Elem> Array<n, Elem>::~Array(){
#ifndef NDEBUG
	delete [] _pElem;
	cout << "Array of size (" << _size << ')' << " deleted" << endl;
#endif
}

template<size_t n, typename Elem> 
Array<n, Elem>::Array(const Array<n, Elem> & a): _size(n), _pElem(new Elem[_size]), _pCurrent(_pElem), _pEnd(_pElem+_size){
#ifndef NDEBUG
	for (size_t i=0; i<n; i++){
		this->_pElem[i]=a[i];
	}
	cout << "Array of size (" << _size << ')' << " created as a copy" << endl << endl;
#endif
}

template<size_t n, typename Elem>
Array <n, Elem>& Array<n, Elem>::operator= (const Array<n, Elem>& a){
#ifndef NDEBUG
	for (size_t i=0; i<n; i++){
		this->_pElem[i]=a[i];
	}
	cout << "Array of size (" << _size << ')' << " created using operator=" << endl << endl;
#endif
	return *this;
}

template<size_t n, typename Elem>
Elem& Array<n,Elem>::operator[](size_t i){
	if (i<0 || i>=_size)
	throw BadArray("Bad index", i);
	return _pElem[i];
}

template<size_t n, typename Elem>
const Elem& Array<n,Elem>::operator[](size_t i)const{
	if (i<0 || i>=_size)
	throw BadArray("Bad index", i);
	return _pElem[i];
}

template<size_t n, typename Elem>
bool Array<n,Elem>::operator== (const Array<n, Elem>& ar) const{
	if (this->size()==n){
		for (size_t i=0; i<n; i++){
			if (this->_pElem[i]!=ar[i])
				return false;
		}
		return true;
	}
	else return false;
}

template<size_t n, typename Elem>
bool Array<n,Elem>::operator!= (const Array<n, Elem>& ar) const{
	return !(*this==ar);
}

template<size_t n, typename Elem>
ostream& operator<<(ostream &os, const Array<n, Elem>& ar)
{
	char chr=' ';
	cout<<"Array of "<<ar.size();
	ar.start();
	while (!ar.finish())
	{
		cout<<chr<<ar.get();
		++ar;
		if (chr=' ') chr=',';
	}
	cout<<endl;
	return os;
}

#endif
