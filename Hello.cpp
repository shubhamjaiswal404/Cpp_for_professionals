/*
// This is Hello world program 
#include<iostream>

int main(){
	std::cout<<" Hello World " << std::endl;
	return 0;
}
*/


// printing the arguments received from command line 
#include<iostream>

int main( int argc , char* argv[] ){
        std::cout<<" Total args are  :  " << argc << std::endl;
	std::cout<<" Each arg is   :  " ;

	for(int i = 0 ; i< argc ; i++)
	{
		std::cout<< i << " -->   " << argv[i]<< "   "  ;
	}
	std::cout<<std::endl;
        


        return 0;
}












