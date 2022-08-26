#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>

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
    SpreadSheetCell();
    ~SpreadSheetCell();

    // output the content of cell
    friend std::ostream &operator<<(std::ostream &os, const SpreadSheetCell &cell);

    // comparsion between two cells
    virtual bool operator<(const SpreadSheetCell &that) const;

    // get the type of this cell, returns either CellType::Number or CellType::String
    CellType GetType() const;

protected:
    CellType m_type; // stores the type of the cell (either CellType::Number or CellType::String)
};

// The `NumberSpreadSheetCell` class, which content is a double
class NumberSpreadSheetCell : public SpreadSheetCell
{
    // Your own implementation here
};

// The `StringSpreadSheetCell` class, which content is a string
class StringSpreadSheetCell : public SpreadSheetCell
{
    // Your own implementation here
};
