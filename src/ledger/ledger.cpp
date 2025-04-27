#include "ledger.hpp"
#include <algorithm>
#include <numeric>
#include <iostream>

namespace RNAB
{
    void Ledger::add_transaction_if_belongs(TransactionPtr p_transaction)
    {
        if(transaction_belongs(p_transaction)) add_transaction(p_transaction);
    }

    int Ledger::get_sum_of_transactions() const
    {
        int this_sum(0);
        for(int i(0); i < m_transactions.size(); ++i)
            this_sum += m_transactions[i]->get_value();
        return this_sum;
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

    void AccountLedger::text_representation_of_self() const
    {
        double sum  = get_sum_of_transactions();
        std::cout << m_account << ": " << sum / 100.0 << '\n';

    }

    void BudgetLedger::text_representation_of_self() const
    {
        double sum  = get_sum_of_transactions();
        std::cout << m_budget << ": " << sum / 100.0 << '\n';

    }
    
} // namespace RNAB
