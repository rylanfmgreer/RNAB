#include "transaction.hpp"

namespace RNAB
{
    std::string Transaction::get_csv_row() const
    {
        return std::to_string(get_value()) + ',' + get_account() + ',' + get_budget();
    }
}