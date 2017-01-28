#ifndef MATRIX_H_
#define MATRIX_H_

namespace pk2
{
	template<class T>
	class Matrix
	{
	private:
		int dimension;
		T **m;
	
    public:
		Matrix(int d) : dimension { d }
		{
			m = new T*[d];
			
			int i;
			for(i=0; i < d; i++)
			{
				m[i] = new T[d];
			}
		}
		
		Matrix(const Matrix& matrix)
		{
			//TODO
		}
		
		~Matrix()
		{
			int i;
			for(i=0; i < dimension; i++)
			{
				delete[] m[i];
			}
			
			delete[] m;
		}
		
		void set(int x, int y, T value)
		{
			m[x][y] = value;
		}
		
		T get(int x, int y) const
		{
			return m[x][y];
		}
		
		int getDimension() const
		{
			return dimension;
		}
	};
}
#endif