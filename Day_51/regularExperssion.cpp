#include <boost/regex.hpp>
#include <iostream>
#include <string>

// verify credut card number : 1234-5678-9012-3456

using namespace std;

int main( int argc , char* argv[])
{
/*  // run1:
 
    std::string line;
    boost::regex pattern( "(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})" );
    boost::smatch matches;

    std::getline(std::cin, line);
    if(boost::regex_match(line,matches,pattern) )
    {
        std::cout << " --> Match Credit Card Pattern " << std::endl;
        for( auto it = matches.begin(); it != matches.end(); it++)
        {
            std::cout << " Number : " << *it << std::endl;
        }
    }
    else{
        std::cout << " --> Not Match Credit Card Pattern " << std::endl;
    }
*/


/*
 * To test subject extraction , we'll filter the following text file.
 * save following text int ex1_testing.txt
 * --------------------------------
 * To: George Shmidlap
 * From: Rita Marlowe
 * Subject: Will Success Spoil Rock Hunter?
 * ---
 * See Subject.
 * ------------------
 * Run:
 *      ./boost_filter_ex1 < ex1_testing.txt
 */


    // run2:

    std::string line;
    boost::regex pattern( "^Subject: (Re: |Aw: )*(.*)");

    while(std::cin)
    {
        std::getline(std::cin,line);
        boost::smatch matches;

        if(boost::regex_match(line,matches,pattern ))
        {
            std::cout << matches[2] << std::endl;
        }

    }


    return 0;
}
