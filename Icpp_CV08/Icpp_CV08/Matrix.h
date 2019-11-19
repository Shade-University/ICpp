#pragma once

#include <exception>
#include <iostream>

template <class T>
class Matrix
{
private:
	int rows, columns;
	T** array;
	bool IsInvalidIndex(int row, int col) const;
	void Init(int rows, int columns);
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& m);
	~Matrix();

	void Set(int row, int col, T value);
	void SetZ(T* array);
	T& Get(int row, int col);
	const T& Get(int row, int col) const;

	template <class R>
	Matrix<R> TypeCast() const;

	Matrix Transposition() const;
	Matrix Multiply(const Matrix& m) const;
	Matrix Multiply(T scalar) const;
	Matrix Sum(const Matrix& m) const;
	Matrix Sum(T scalar) const;

	bool IsEqual(const Matrix& m) const;
	void Print() const;

	int GetRows() const { return this->rows; }
	void SetRows(int rows) { this->rows = rows; }
	int GetColumns() const { return this->columns; }
	void SetColumns(int columns) { this->rows = columns; }
};

template<class T>
void Matrix<T>::Init(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	this->array = new T*[rows];

	for (int i = 0; i < rows; i++)
		array[i] = new T[columns];
}

template<class T>
bool Matrix<T>::IsInvalidIndex(int row, int col) const
{
	return row < 0 && row >= this->rows
		|| col < 0 && col >= this->columns;
}

template<class T>
Matrix<T>::Matrix(int rows, int columns)
{
	Init(rows, columns);
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	Init(m.GetRows(), m.GetColumns()); //V c++ se nedá volat vlastní konstruktor :(

	for (int i = 0; i < m.GetRows(); i++)
		for (int j = 0; j < m.GetColumns(); j++)
			array[i][j] = m.Get(i, j);
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] array[i];
	delete[] array;
}

template<class T>
void Matrix<T>::Set(int row, int col, T value)
{
	if(IsInvalidIndex(row, col))
		throw std::out_of_range("Index not valid");

	array[row][col] = value;
}

template<class T>
void Matrix<T>::SetZ(T* array)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			this->array[i][j] = array[(columns * i) + j];
}

template<class T>
T& Matrix<T>::Get(int row, int col)
{
	if (IsInvalidIndex(row, col))
		throw std::out_of_range("Index not valid");

	return array[row][col];

}

template<class T>
const T& Matrix<T>::Get(int row, int col) const
{
	if (IsInvalidIndex(row, col))
		throw std::out_of_range("Index not valid");

	return array[row][col];
}

template <class T>
template <class R>
Matrix<R> Matrix<T>::TypeCast() const
{
	Matrix<R> output(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			output.Set(i, j, (R)(array[i][j]));

	return output;
}

template<class T>
Matrix<T> Matrix<T>::Transposition() const
{
	Matrix output(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			output.Set(j, i, array[i][j]);
	
	return output;
}

template<class T>
Matrix<T> Matrix<T>::Multiply(const Matrix& m) const
{
	if(columns != m.GetRows())
		throw std::exception("Bad matrix size");

	Matrix<T> output(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < m.GetColumns(); j++)
		{
			T temp = T();
			for (int k = 0; k < columns; k++)
				temp += array[i][k] * m.Get(k, j);
			output.Set(i, j, temp);
		}

	return output;
}

template<class T>
Matrix<T> Matrix<T>::Multiply(T scalar) const
{
	Matrix<T> output;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			output.Set(i,j, array[i][j] * scalar);

	return output;
}

template<class T>
Matrix<T> Matrix<T>::Sum(const Matrix& m) const
{
	if (m.GetColumns() != columns && m.GetRows() != rows)
		throw std::exception("Bad matrix size");

	Matrix<T> output(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			output.Set(i,j) = array[i][j] + m.Get(i, j);

	return output;
}

template<class T>
Matrix<T> Matrix<T>::Sum(T scalar) const
{
	Matrix<T> output(rows, columns);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			output.Set(i,j, array[i][j] + scalar);

	return output;
}

template<class T>
bool Matrix<T>::IsEqual(const Matrix& m) const
{
	if (m.GetColumns() != columns && m.GetRows() != rows)
		throw std::exception("Bad matrix size");

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			if (array[i][j] != m.Get(i, j))
				return false;
	return true;
}

template<class T>
void Matrix<T>::Print() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << array[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}




