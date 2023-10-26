// Matrix

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<int>> elements;

public:
    Matrix(int numRows, int numCols);
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    ~Matrix();

    friend ostream &operator<<(ostream &out, const Matrix &matrix);

    bool IsEchelonForm() const;
    bool IsReducedEchelonForm() const;
    void RowOperation(int targetRow, int sourceRow, int multiplier, int additionRow);

    Matrix operator+(const Matrix &other) const;
    Matrix &operator+=(const Matrix &other);
    Matrix operator*(const Matrix &other) const;
    Matrix &operator*=(const Matrix &other);

private:
    void InitializeRandomElements();
};

Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols)
{
    InitializeRandomElements();
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), elements(other.elements) {}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        elements = other.elements;
    }
    return *this;
}

Matrix::~Matrix() {}

ostream &operator<<(ostream &out, const Matrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            out << matrix.elements[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

bool Matrix::IsEchelonForm() const
{
    // Your implementation for Echelon form check goes here
}

bool Matrix::IsReducedEchelonForm() const
{
    // Your implementation for Reduced Echelon form check goes here
}

void Matrix::RowOperation(int targetRow, int sourceRow, int multiplier, int additionRow)
{
    // Your implementation for row operations goes here
}

Matrix Matrix::operator+(const Matrix &other) const
{
    // Your implementation for matrix addition goes here
}

Matrix &Matrix::operator+=(const Matrix &other)
{
    // Your implementation for matrix addition and assignment goes here
}

Matrix Matrix::operator*(const Matrix &other) const
{
    // Your implementation for matrix multiplication goes here
}

Matrix &Matrix::operator*=(const Matrix &other)
{
    // Your implementation for matrix multiplication and assignment goes here
}

void Matrix::InitializeRandomElements()
{
    srand(static_cast<unsigned>(time(0)));
    elements.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            elements[i][j] = rand() % 10; // Random integers in the range [0, 9]
        }
    }
}

int main()
{
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);

    cout << "Matrix 1:\n"
         << matrix1 << endl;
    cout << "Matrix 2:\n"
         << matrix2 << endl;

    Matrix matrix3 = matrix1 + matrix2;
    cout << "Matrix 1 + Matrix 2:\n"
         << matrix3 << endl;

    Matrix matrix4 = matrix1 * matrix2;
    cout << "Matrix 1 * Matrix 2:\n"
         << matrix4 << endl;

    return 0;
}
