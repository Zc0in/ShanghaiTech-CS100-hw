#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols, const T &value = T());

    T &operator()(unsigned int r, unsigned int c);

    void Print();

    void GaussJordan();

private:
    // Your implementation here.
    unsigned int m_rows;
    unsigned int m_cols;
    std::vector<std::vector<T>> m_value;
};

template <typename T>
Matrix<T>::Matrix()
{
    m_rows = 0;
    m_cols = 0;
}

template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const T &value)
{
    m_value.resize(rows);
    for (int i = 0; i < rows; i++)
    {
        m_value[i].resize(cols);
    }
    m_rows = rows;
    m_cols = cols;
}

template <typename T>
T &Matrix<T>::operator()(unsigned int r, unsigned int c)
{
    return m_value[r][c];
}

template <typename T>
void Matrix<T>::Print()
{
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            std::cout << m_value[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void Matrix<T>::GaussJordan()
{
    int h = 0;
    int k = 0;
    int i_max, i_min;
    while (h < m_rows && k < m_cols)
    {
        i_max = h;
        i_min = h;
        for (int i = h; i < m_rows; i++)
        {
            if (m_value[i_max][k] < m_value[i][k])
            {
                i_max = i;
            }
            if (m_value[i][k] < m_value[i_min][k])
            {
                i_min = i;
            }
        }
        if (m_value[i_max][k] == 0)
        {
            i_max = i_min;
        }
        if (m_value[i_max][k] == 0)
        {
            k += 1;
        }
        else
        {
            std::swap(m_value[h], m_value[i_max]);
            for (int i = h + 1; i < m_rows; i++)
            {
                T f = m_value[i][k] / m_value[h][k];
                m_value[i][k] = 0;
                for (int j = k + 1; j < m_cols; j++)
                {
                    m_value[i][j] = m_value[i][j] - m_value[h][j] * f;
                }
            }
            h += 1;
            k += 1;
        }
    }
}
#endif
