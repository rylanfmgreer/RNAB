#include "instance.hpp"
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../data/csv_reader/csv_reader.hpp"


namespace RNAB
{


    std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
    {
        std::vector<std::string> result;
        std::string line;
        std::getline(str,line);

        std::stringstream lineStream(line);
        std::string cell;

        while(std::getline(lineStream,cell, ','))
        {
            result.push_back(cell);
        }
        // This checks for a trailing comma with no data after it.
        if (!lineStream && cell.empty())
        {
            // If there was a trailing comma then add an empty element.
            result.push_back("");
        }
        return result;
    }
    

    void Instance::dump_data() const
    {
        std::ofstream output_csv("MyCSV.csv");
        output_csv << "amount,account,budget\n";
        std::vector<std::string> rows = m_master_ledger.get_text_representations();
        for(int i(0); i < rows.size(); ++i) output_csv << rows[i] << '\n';
        output_csv.close();
    }

    void Instance::read_data(const std::string& p_filename)
    {
        std::ifstream myfile;
        myfile.open(p_filename);

        int c = 0;
        for(CSVIterator loop(myfile); loop != CSVIterator(); ++loop)
        {
            
            auto x = (*loop)[0];
            int amount = 10;
            std::string account = "1";
            std::string budget = "2";

            TransactionPtr this_transaction(new Transaction(amount, account, budget));
            add_budget_if_not_exists(budget);
            add_account_if_not_exists(account);
            add_transaction(this_transaction);

        }


    }
}