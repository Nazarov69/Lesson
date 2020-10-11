#include <math.h>
#include "MyVector.h"
#ifndef _MY_VECTOR_
#define _MY_VECTOR_
#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)
using namespace std;

template<class ValType>
TVector<ValType>::TVector(int s) {
	if (s > 0) {
		pVector = new TVector[s];
		for (int i = 0; i < s; i++)
			pVector[i].Resize(i + 1);
		size = s;
	}
	else throw - 1;
}

template<class ValType>
TVector<ValType>::TVector(int s, int si) {
	if (s > 0 && si > 0) {
		pVector = new TVector[s];
		for (int i = 0; i < s; i++)
			pVector[i].Resize(i + 1);
		size = s;
		delete[] pVector;
		pVector = new TVector[si];
		for (int i = 0; i < si; i++)
			pVector[i].Resize(i + 1);
		index = si;
	}
	else throw - 1;
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v) {
	size = v.size;
	pVector = new ValType[size];
	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector() {
	size = 0;
	if (pVector != 0)
		delete[] pVector;
	pVector = 0;
}

template <class ValType>
ValType& TVector<ValType>::operator[] (int pos)
{
	if ((pos >= 0) && (pos < size))
		return pVector[pos];
	return pVector[0];
}

template<class ValType>
int TVector<ValType>::operator==(const TVector<ValType>& v) {
	if (size == v.size) {
		for (int i = 0; i < size; i++) {
			if ((*this)[i] != v[i])
				return 0;
		}
		return 1;
	}
	return 0;
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector<ValType>& v) {
	if (this == &v)
		return *this;
	size = v.size;
	delete[] pVector;
	pVector = new ValType[size];
	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];
	return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v) {
	TVector<ValType> res;
	res.size = MIN(size, v.size);
	res.pVector = new ValType[res.size];
	for (int i = 0; i < res.size; i++)
		res.pVector[i] = pVector[i] + v.pVector[i];
	return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v) {
	TVector<ValType> res;
	res.size = MIN(size, v.size);
	res.pVector = new ValType[res.size];
	for (int i = 0; i < res.size; i++)
		res.pVector[i] = pVector[i] - v.pVector[i];
	return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const TVector<ValType>& v) {
	TVector<ValType> res;
	res.size = MIN(size, v.size);
	res.pVector = new ValType[res.size];
	for (int i = 0; i < res.size; i++)
		res.pVector[i] = pVector[i] * v.pVector[i];
	return res;
}

template <class ValType1>
istream& operator>> (istream& in, TVector<ValType1>& v) {
	for (int i = 0; i < v.size; i++) {
		in >> v.pVector[i];
	}
	return in;
}

template <class ValType1>
ostream& operator<< (ostream& out, const TVector<ValType1>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.pVector[i] << endl;
	}
	return out;
}

template<class ValType>
void TVector<ValType>::Resize(int s)
{
	if (s > 0) {
		TVector<ValType> tmp(*this);
		if (pVector != 0)
			delete[] pVector;
		pVector = 0;
		this->GetSize() = s;
		pVector = new ValType[size];
		for (int i = 0; i < size; i++)
			pVector[i] = tmp[0];
	}
	else throw - 1;
}

#endif