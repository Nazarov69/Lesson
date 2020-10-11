#include <iostream>
using namespace std;

template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int size;
	int index;
public:
	TVector();
	TVector(int s);
	TVector(int s, int si);
	TVector(const TVector<ValType>& v);
	~TVector();
	int GetSize() {
		return size;
	}
	ValType& operator[](int pos);
	int operator==(const TVector<ValType>& v);
	TVector<ValType>& operator=(const TVector<ValType>& v);
	TVector<ValType> operator+(const TVector<ValType>& v);
	TVector<ValType> operator-(const TVector<ValType>& v);
	TVector<ValType> operator*(const TVector<ValType>& v);

	template <class ValType1>
	friend istream& operator>>(istream& in, TVector<ValType1>& v);
	template <class ValType1>
	friend ostream& operator<<(ostream& out, const TVector<ValType1>& v);
	void Resize(int s);
};





