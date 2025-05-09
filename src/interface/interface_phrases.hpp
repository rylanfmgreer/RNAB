#pragma once
#ifndef _INTERFACE_PHRASES
#define _INTERFACE_PHRASES
#include <string>

namespace RNAB_Phrases
{
    const std::string RNAB_INTRO = "\n\n\n          RNAB\n\n          Copyright Rylan\n          MMXXV\n\n\n";
    const std::string GREETING =  "\nHello woke bloke\n";
    const std::string ACT_QUESTION =  "\nWhat would you like to do now?\n";
    const std::string QUIT_GOODBYE =  "\nGoodbye bloke.\n";
    const std::string ADD_TRANSACTION_PHRASE =  "Well then bloke... Let's see what you've got!\n\n";
    const std::string ADD_TRANSACTION_AMOUNT =  "How much? \n";
    const std::string ADD_TRANSACTION_BUDGET =  "What budget? \n";
    const std::string ADD_TRANSACTION_ACCOUNT =  "What account? \n";
    const std::string OPTIONS = "  (1) Add a transaction \n  (2) Check accounts \n  (3) Check budgets. \n  (4) Quit\n\n";


}
#endif