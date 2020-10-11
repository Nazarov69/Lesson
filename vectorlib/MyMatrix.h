#pragma once
#include"MyVector.h"
#include <iostream>
using namespace std;

template <class ValType>
class TMatrix : public TVector <TVector<ValType> >
{
public:
	TMatrix(int Size);
	TMatrix(const TMatrix<ValType>& mt);
	virtual ~TMatrix();
	TMatrix<ValType>& operator==(const TMatrix<ValType>& mt);
	TMatrix<ValType>& operator=(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator+(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator-(const TMatrix<ValType>& mt);
	TMatrix<ValType> operator*(const TMatrix<ValType>& mt);
	template <class ValType1>
	friend ostream& operator<< (ostream& out, const TMatrix<ValType1>& mt);
	template <class ValType1>
	friend istream& operator>> (istream& in, TMatrix<ValType1>& mt);
};


