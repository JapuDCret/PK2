#include <iostream>
#include "Matrix.h"

using namespace pk2;

template<class T>
std::ostream& operator<<(std::ostream& ausgabe, const Matrix<T>& matrix)
{
	int dimension = matrix.getDimension();
	
	int x;
	for(x=0; x < dimension; x++)
	{
		int y;
		for(y=0; y < dimension; y++)
		{
			ausgabe << matrix.get(x, y) << ", ";
		}
		ausgabe << std::endl;
	}
	
	return ausgabe;
}


template<class T>
Matrix<T>* operator*(const Matrix<T>& m1, const Matrix<T>& m2)
{
	int dimension = m1.getDimension();
	Matrix<T>* m = new Matrix<T>(dimension);
	
	int x;
	for(x=0; x < dimension; x++)
	{
		int y;
		for(y=0; y < dimension; y++)
		{
			T value = 0;
			int i;
			for(i=0; i < dimension; i++)
			{
				value += m1.get(x, i) * m2.get(i, y);
			}
			m->set(x, y, value);
		}
	}
	
	return m;
}