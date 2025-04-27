#include "ledger.hpp"
#include <algorithm>
#include <numeric>

namespace RNAB
{
    void Ledger::add_transaction_if_belongs(TransactionPtr p_transaction)
    {
        if(transaction_belongs(p_transaction)) add_transaction(p_transaction);
    }

    int Ledger::get_sum_of_transactions() const
    {
        return std::accumulate(m_transactions.begin(), m_transactions.end(), 0, [](TransactionPtr x){ return x->get_value();});
    }

    void Ledger::filter_transactions()
    {
        std::vector<TransactionPtr> new_transactions;
        for(size_t i(0); i < m_transactions.size(); ++i)
        {
            if(transaction_belongs(m_transactions[i]))
                new_transactions.push_back(m_transactions[i]);
        }
        m_transactions = new_transactions;
    }

    
} // namespace RNAB
