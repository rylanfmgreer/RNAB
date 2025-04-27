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

    std::vector< std::string > Ledger::get_text_representations() const
    {
        std::vector<std::string> vectors_to_return(m_transactions.size());
        std::transform(m_transactions.begin(), m_transactions.end(),
            vectors_to_return.begin(), [](TransactionPtr x){ return x->get_csv_row();} );
        return vectors_to_return;
    }


    void Ledger::text_representation_of_self() const
    {
        double sum  = get_sum_of_transactions();
        std::cout << get_name() << ": " << sum / 100.0 << '\n';
    
    }

    std::string BudgetLedger::get_name() const
    {
        return m_budget;
    }

    std::string AccountLedger::get_name() const
    {
        return m_account;
    }   


} // namespace RNAB
