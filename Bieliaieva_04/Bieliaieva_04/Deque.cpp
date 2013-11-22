#pragma once
#ifndef _DEQUE_CPP_
#define _DEQUE_CPP_
#include "Deque.h"
#include <iostream>
#include <algorithm>    // std::reverse
using namespace std;


template <typename Elem>
Elem & Deque<Elem>::front() //returns the first element in the deque
{
	if (vecOne.empty())
		return vecTwo.front();
	else
		return vecOne.back();
}

template <typename Elem>
Elem & Deque<Elem>::back() //returns the last element in the deque
{
	if (vecTwo.empty())
		return vecOne.back();
	else
		return vecTwo.back();
}


template <typename Elem>//
Elem & Deque<Elem>::operator[] (unsigned int index)
{
	int n = vecOne.size();
	if (index < n)
		return vecOne [ (n-1) - index ];
	else
		return vecTwo [ index - n ];
}


template <typename Elem>
void Deque<Elem>::pop_front()
{
	if (vecOne.empty())
		return vecTwo.pop_back();
	else
		return vecOne.pop_back();
}

template <typename Elem>
void Deque<Elem>::pop_back()
{
	if (vecTwo.empty())
	{
		if (isReversed == false)
		{
			std::reverse(vecOne.begin(),vecOne.end());
			isReversed = true;
			vecOne.pop_back();

		}
		else 
			vecOne.pop_back();
	}
	else 
		vecTwo.pop_back();
}

template <typename Elem>
void Deque<Elem>::erase (const iterator & itr)
{
	int index = itr.index;
	int n = vecOne.size();
	if (index < n)
		vecOne.erase (vecOne.begin() + ((n-1) - index));
	else
		vecTwo.erase (vecTwo.begin() + (n - index));
}

template <typename Elem>
void Deque<Elem>::erase (const iterator &, const iterator &)
{

}

template <typename Elem>
void Deque<Elem>::insert(const iterator &, const Elem &)
{

}

#endif