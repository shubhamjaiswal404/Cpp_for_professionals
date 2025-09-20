#include<iostream>
using namespace std;

/*
   http://localhost/cgi-bin/CppWebForm.cgi
*/

void printWebForm()
{
   std::cout << "<div style=\"width: 100%; font-size : 36px; font-weight: bold; text-align: center; color: blue;\">\n ";
   std::cout << "<form action = \"/cgi-bin/MyWebAppGet.cgi\" method =\"get\">\n";
   std::cout << "Name: <input type = \"text\" name = \"name\"> <br /> \n";
   std::cout << "Gender: <input type = \"text\" name = \"gender\" /> <br /> <br /> \n";
   std::cout << "<input type = \"submit\" value = \"Submit\"> \n";
   std::cout << "</form> \n";
   std::cout << "</div>\n";
  
}	



void printWebHead()
{
   std::cout << "Content-type:text/html\n\n";
   std::cout << "<html>\n";
   std::cout << "<head>\n";
   std::cout << "<title> Hello World - First C++ Web Program </title> \n";
   std::cout << "</head> \n";
   std::cout << "<body>\n";
   std::cout << "<div style=\"width: 100%; font-size : 36px; font-weight: bold; text-align: center; color: blue;\">\n ";
   std::cout << "<h2> C++ Web Application  </h2> \n";
   std::cout << "This is my C++ Web Programming Test Form  Page  \n";
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
        printWebHead();
	printWebForm();
	printWebEnd();
        return 0;
}










