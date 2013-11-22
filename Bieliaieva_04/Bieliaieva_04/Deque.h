#pragma once
#ifndef _DEQUE_
#define _DEQUE_
#include <iostream>
#include <vector>

using namespace std;

template <typename Elem> class DequeIterator;

template <typename Elem>
class Deque {
public:
    typedef DequeIterator<Elem> iterator;

    Deque(): vecOne(), vecTwo(), isReversed(false) { }
    Deque(unsigned int size, Elem & initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
    Deque(Deque<Elem> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }

    Elem& operator[](unsigned int);
    Elem& front();//
    Elem& back();//
    bool empty(){ return vecOne.empty() && vecTwo.empty(); }
    iterator begin() { return iterator(this,0); }
    iterator end() { return iterator(this, size ()); }
    void erase(const iterator &);
    void erase(const iterator &, const iterator &);
    void insert(const iterator &, const Elem&);
    int size() { return vecOne.size() + vecTwo.size(); }
    void push_front(const Elem& value) { vecOne.push_back(value); }
    void push_back(const Elem& value) {vecTwo.push_back(value); }
	void pop_front();
	void pop_back();
	
	
	
protected:
	bool isReversed;

    vector<Elem> vecOne;
    vector<Elem> vecTwo;
};


template <typename Elem>
class DequeIterator {
    friend class Deque<Elem>;
    typedef DequeIterator<Elem> iterator;
public:
    DequeIterator(): theDeque(0), index(0) { }
    DequeIterator(Deque<Elem> * d, int i): theDeque(d), index(i) { }
    DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

    Elem & operator*() { return (*theDeque)[index]; }
    iterator & operator++(int) { ++index; return *this; }
	iterator operator++() { Deque<Elem>::iterator clone(theDeque, index); index++; return clone;}
    iterator operator--(int) { --index; return *this; }
    iterator & operator--();
    bool operator==(const iterator & r) { return theDeque == r.theDeque && index == r.index; }
    bool operator!=(const iterator & r) { return theDeque == r.theDeque && index != r.index; }
    bool operator< (const iterator & r) { return theDeque == r.theDeque && index < r.index; }
    Elem & operator[](unsigned int i) { return (*theDeque) [index + i]; }
    iterator operator=(const iterator & r) { theDeque = r.theDeque; index = r.index; return *this; }
    iterator operator+(int i) { return iterator(theDeque, index + i); }
    iterator operator-(int i) { return iterator(theDeque, index - i); }
protected:
    Deque<Elem> * theDeque;
    int index;
};

#include "Deque.cpp"
#endif

