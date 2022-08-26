#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>

using namespace std;

// width of normal column and the row index column
const int DEFAULT_COLUMN_WIDTH = 7;
const int DEFAULT_ROW_IDX_WIDTH = 4;

// forward declaration of derived classes
class NumberSpreadSheetCell;
class StringSpreadSheetCell;

// types of spreadsheet cells
enum CellType
{
    Number,
    String
};

// The base SpreadSheetCell class
class SpreadSheetCell
{
public:
    // constructors and destructors.
    SpreadSheetCell() {}
    ~SpreadSheetCell() {}

    // output the content of cell
    friend std::ostream &operator<<(std::ostream &os, const SpreadSheetCell &cell)
    {
        if (cell.GetType() == CellType::Number)
        {
            std::cout << std::setprecision(3) << cell.num;
        }
        else
        {
            std::cout << std::setprecision(3) << cell.str;
        }
    }

    // comparsion between two cells
    virtual bool operator<(const SpreadSheetCell &that) const {}

    // get the type of this cell, returns either CellType::Number or CellType::String
    virtual CellType GetType() const
    {
        return m_type;
    }

protected:
    CellType m_type; // stores the type of the cell (either CellType::Number or CellType::String)
    double num;
    std::string str;
};

// The `NumberSpreadSheetCell` class, which content is a double
class NumberSpreadSheetCell : public SpreadSheetCell
{
public:
    // Your own implementation here
    NumberSpreadSheetCell(double n)
    {
        num = n;
        m_type = Number;
    }
    ~NumberSpreadSheetCell() {}
    bool operator<(const SpreadSheetCell &that) const
    {
        if (that.GetType() == CellType::Number)
        {
            const NumberSpreadSheetCell *ptr = (const NumberSpreadSheetCell *)(&that);
            if (this->num < ptr->num)
            {
                return true;
            }
            return false;
        }
        return true;
    }
};

// The `StringSpreadSheetCell` class, which content is a string
class StringSpreadSheetCell : public SpreadSheetCell
{
public:
    // Your own implementation here
    StringSpreadSheetCell(std::string s)
    {
        str = s;
        m_type = String;
    }
    ~StringSpreadSheetCell() {}
    bool operator<(const SpreadSheetCell &that) const
    {
        if (that.GetType() == CellType::String)
        {
            const StringSpreadSheetCell *ptr = (const StringSpreadSheetCell *)(&that);
            if (this->str < ptr->str)
            {
                return true;
            }
        }
        return false;
    }
};

class SpreadSheet
{
public:
    // constructors and destructors
    SpreadSheet(int rows, int cols);
    ~SpreadSheet();

    // "hide" a row or column in this sheet, hidden row or column
    // will not be shown in "ExportSheet" function
    void HideRow(int row);
    void HideColumn(int col);

    // re-show a hidden row or column in this sheet.
    // If the given row is not hidden, this does nothing.
    void ShowRow(int row);
    void ShowColumn(int col);

    // set a the pointer at (row, col) to `cell`,
    // if there is already be a cell, delete it and reset it to `cell`
    void UpdateCell(int row, int col, SpreadSheetCell *cell);

    /* print the sheet to the ostream `os`. You may assume that `os' is std::cout.
     * Each column has width = DEFAULT_COLUMN_WIDTH
     * It's guaranteed that length of all cell contents are less than DEFAULT_COLUMN_WIDTH
     * The width of the column of ROW INDEX has width = DEFAULT_ROW_IDX_WIDTH
     * row index and column index are all ints which starts from 1.
     * If your implementation is correct, the output of given "main" function will be similar to:
     *     |      1      2      3      4
     * ---------------------------------
     *    1|  0.658   qufk    vry   3.43
     *    2|     ld   fdkr    omx  0.892
     *    3|    mlg   uqpb   4.91      r
     *    4|   wneo   4.49   atdh   itbf
     */
    void ExportSheet(std::ostream &os);

    // PROBLEM 3: Sort all rows by the value in `col`, in accending order, and number < string < nullptr.
    void SortByColumn(int col);

private:
    std::vector<std::vector<SpreadSheetCell *>> m_cells;
    std::vector<int> hidden_row;
    std::vector<int> hidden_col;
    int m_row, m_col;
    // Add your own private variables and functions here
};

// PROBLEM 3: A functor class for sorting. It should have an operator() that takes 2 parameters.
class ColumnComparator
{
public:
    ColumnComparator(int col) : col(col) {}
    ~ColumnComparator() {}
    bool operator()(std::vector<SpreadSheetCell *> cell1, std::vector<SpreadSheetCell *> cell2)
    {
        if (cell1[col - 1] == nullptr)
        {
            return false;
        }
        else if (cell2[col - 1] == nullptr)
        {
            return true;
        }
        else
        {
            return *cell1[col - 1] < *cell2[col - 1];
        }
    }

private:
    int col;
};

SpreadSheet::SpreadSheet(int rows, int cols)
{
    m_row = rows;
    m_col = cols;
    m_cells.resize(m_row);
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            m_cells[i].push_back(nullptr);
        }
    }
    for (int i = 0; i < m_row; i++)
    {
        hidden_row.push_back(0);
    }
    for (int i = 0; i < m_col; i++)
    {
        hidden_col.push_back(0);
    }
}

SpreadSheet::~SpreadSheet()
{
    std::vector<std::vector<SpreadSheetCell *>>(m_cells).swap(m_cells);
    std::vector<int>(hidden_row).swap(hidden_row);
    std::vector<int>(hidden_col).swap(hidden_col);
}

void SpreadSheet::HideRow(int row)
{
    hidden_row[row - 1] = 1;
}

void SpreadSheet::HideColumn(int col)
{
    hidden_col[col - 1] = 1;
}

void SpreadSheet::ShowRow(int row)
{
    hidden_row[row - 1] = 0;
}

void SpreadSheet::ShowColumn(int col)
{
    hidden_col[col - 1] = 0;
}

void SpreadSheet::UpdateCell(int row, int col, SpreadSheetCell *cell)
{
    if (row <= m_row && col <= m_col && row >= 1 && col >= 1)
    {
        m_cells[row - 1][col - 1] = nullptr;
        m_cells[row - 1][col - 1] = cell;
    }
}

void SpreadSheet::ExportSheet(std::ostream &os)
{
    std::cout << std::setw(5) << '|';
    int temp_col = 0;
    for (int i = 0; i < m_col; i++)
    {
        if (hidden_col[i] == 0)
        {
            std::cout << std::setw(7) << i + 1;
            temp_col += 1;
        }
    }
    std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(5 + 7 * temp_col) << '-' << std::endl;
    for (int i = 0; i < m_row; i++)
    {
        if (hidden_row[i] == 0)
        {
            std::cout << std::setfill(' ') << std::setw(4) << i + 1 << '|';
            for (int j = 0; j < m_col; j++)
            {
                if (hidden_col[j] == 0)
                {
                    if (m_cells[i][j] == nullptr)
                    {
                        std::cout << std::setw(7) << ' ';
                    }
                    else
                    {
                        std::cout << std::setw(7) << *m_cells[i][j];
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

void SpreadSheet::SortByColumn(int col)
{
    sort(m_cells.begin(), m_cells.end(), ColumnComparator(col));
}

void test()
{
    SpreadSheet sheet(4, 4);
    sheet.UpdateCell(1, 1, new NumberSpreadSheetCell(1.1));
    sheet.UpdateCell(1, 3, new NumberSpreadSheetCell(3.4));
    sheet.UpdateCell(2, 4, new StringSpreadSheetCell("foo"));
    sheet.UpdateCell(3, 1, new StringSpreadSheetCell("bar"));
    sheet.UpdateCell(3, 2, new StringSpreadSheetCell("baz"));
    sheet.UpdateCell(4, 2, new NumberSpreadSheetCell(0));
    sheet.HideColumn(3);
    sheet.HideRow(2);
    sheet.ExportSheet(std ::cout);
}

int main()
{
    test();
    // srand(0);
    // SpreadSheet sheet(4, 4);
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = 1; j <= 4; j++)
    //     {
    //         if (rand() < 0.5f * RAND_MAX)
    //             sheet.UpdateCell(i, j, new NumberSpreadSheetCell((double)rand() / double(RAND_MAX) * 5.0f));
    //         else
    //         {
    //             std::string s;
    //             for (int k = 0; k < 1 + rand() % 5; k++)
    //                 s += ('a' + rand() % 26);
    //             sheet.UpdateCell(i, j, new StringSpreadSheetCell(s));
    //         }
    //     }
    // }
    // sheet.ExportSheet(std::cout);
}
