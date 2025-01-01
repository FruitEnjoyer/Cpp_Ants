#include "field.hpp"

field::Field::Field(const unsigned int height, const unsigned int width)
{
    this->height = height;
    this->width = width;

    this->statuses[std::pair<int,int>(1,1)] = field::CELL_EMPTY;
}

field::Cell field::Field::GetCellStatus(std::pair<int,int> coord)
{
    if(this->statuses.count(coord) == 0)
    {
        return CELL_ERROR;
    }
    else
    {
        return this->statuses[coord];
    }

}