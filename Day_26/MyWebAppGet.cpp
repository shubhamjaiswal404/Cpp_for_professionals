#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>

#include<cgicc/CgiDefs.h>
#include<cgicc/Cgicc.h>
#include<cgicc/HTTPHTMLHeader.h>
#include<cgicc/HTMLClasses.h>


using namespace std;
using namespace cgicc;


//   http://localhost/cgi-bin/CppWebForm.cgi
	

//   http://192.168.0.109/cgi-bin/MyWebAppGet.cgi?first_name=John&last_name=Collin
 
void printWebHead()
{
   std::cout << "Content-type:text/html\n\n";
   std::cout << "<html>\n";
   std::cout << "<head>\n";
   std::cout << "<title> C++ Web Program Test Get Page  </title> \n";
   std::cout << "</head> \n";
   std::cout << "<body>\n";
   std::cout << "<div style=\"width: 100%; font-size : 36px; font-weight: bold; text-align: center; color: blue;\">\n ";
   std::cout << "<h2> C++ Web Application  </h2> \n";
   std::cout << "This is my C++ Web Programming Test Get Page  \n";
   std::cout << "</div> \n";
   std::cout << "<br />\n";

}

void printWebEnd()
{

   std::cout << "</body>\n";
   std::cout << "</html>\n";

}

int main()
{
	Cgicc formData;
	form_iterator fi;

        printWebHead();
	std::cout << "<div style=\"width: 100%; font-size : 20px; font-weight: bold; text-align: center; color: red;\">\n ";

	fi = formData.getElement("name");
	std::cout << "Name    : ";
	if(!fi->isEmpty())
	{
	    std::cout << **fi;
	  
	}
	std::cout << "<br /> " << std::endl;



	fi = formData.getElement("gender");
        std::cout << "Gender    : ";
        if(!fi->isEmpty())
        {
            std::cout << **fi;

        }
        std::cout << "<br /> " << std::endl;


	std::cout << "</div>\n"; 
        printWebEnd();


        return 0;


}
























