#ifndef FIELD_HPP
#define FIELD_HPP

#include <map>
#include <vector>
#include <string>

namespace field
{

    enum Cell
    {
        CELL_EMPTY = 0,
        CELL_FULL,
        CELL_ERROR = -1
    };

    class Field
    {
    private:
        std::map<std::pair<int,int>, Cell> statuses;
        unsigned int height;
        unsigned int width; 
    public:
        Field(const unsigned int height, const unsigned int width);

        Cell GetCellStatus(std::pair<int,int> coord);
        void PrintCellStatus();
    };

} // namespace field

#endif // FIELD_HPP
