#pragma once
#ifndef RNAB_INSTANCE
#define RNAB_INSTANCE
#include <vector>
#include "../ledger/ledger.hpp"
#include "../transaction/transaction.hpp"

namespace RNAB
{
    class Instance
    {
        public:
        void add_transaction(Transaction& p_transaction);
        void print_accounts() const;
        void print_budgets() const;
        void dump_data() const;

        private:
        Ledger m_master_ledger;
        std::vector<AccountLedger> m_account_ledgers;
        std::vector<BudgetLedger> m_budget_ledgers;


    };
    
} // namespace RNAB


#endif