#include <iostream>
#include <string>
#include <google/protobuf/arena.h>

using namespace google::protobuf;

/*
 *  What are protocol buffers?
 *  Protocol buffers are Google's language-neutral , platform-neutral,
 *  extensible mechanism for serializing structured data
 *
 *  cass Arena
 *  #include<google/protobuf/arena.h>
 *  namespace google::protobuf
 *
 *  Arena allocator.
 *  1) Replaces ordinary (heap-based)allocation with new/delete,
 *  2) Improves performance by aggregating allocations into larger blocks
 *  3) Freeing allocations all at once
 */

class MyClass
{
public:

    MyClass() : num(0) {};
    MyClass(int n) : num(n) {};
    int getNumber() { return num; }
    void setNumber(int n) { num = n;}

private:

    int num;
};

class MyString
{
public:

    MyString() : ptr(nullptr) {}
    MyString(std::string& str)
    {
        ptr = new std::string(str);
    }

    MyString(const MyString& x)
    {
        if(ptr != nullptr)
        {
            delete ptr;
        }
        ptr = new std::string(x.print());
    }

    const std::string& print() const
    {
        return *ptr;
    }
    ~MyString() {delete ptr;}

private:

    std::string *ptr;
};

/*
 * google::protobuf::ArenaOptions opt;
 * Arena(opt) : Creates a new arena that uses the specified allocation options.
 * arena.Arena::Init(opt);
 */

int main(int argc, char* argv[])
{
    int a = 999;
    google::protobuf::Arena arena;

    std::cout << "Initializion Allocation Space : " << arena.SpaceAllocated()
              <<" Used Space : "<< arena.SpaceUsed() << std::endl;

    std::string str0 = "Arena allocator: ";
    std::string str1 = "1) allocation replace ordinary (head-based) allocation with new/delete";
    std::string str2 = "2) Improves performance by aggregating allocations into larger blocks";
    std::string str3 = "3) Freeing allocations all at once";


    //MyClass* c1 = new MyClass(a);
    MyClass* c1 = google::protobuf::Arena::Create<MyClass>(&arena, a);

    std::cout << "Allocates add MyClass cl (999) : " << arena.SpaceAllocated()
              <<" Used Space : " << arena.SpaceUsed() << std::endl;

    // MyString mStr = new MyString("This is John Test");
    MyString* s0 = google::protobuf::Arena::Create<MyString>(&arena,str0);

    std::cout << "Allocated add MyString str : " <<arena.SpaceAllocated()
              <<" Used Spaced : " << arena.SpaceUsed() <<std::endl;

    MyString* s1 = google::protobuf::Arena::Create<MyString>(&arena, str1);

    std::cout<<"Allocated add MyString str1 : " << arena.SpaceAllocated()
              <<" Used Spaced : " << arena.SpaceUsed() << std::endl;

    MyString* s2 = google::protobuf::Arena::Create<MyString>(&arena, str2);

    std::cout<<"Allocated add MyString str2 : " << arena.SpaceAllocated()
              <<" Used Spaced : " << arena.SpaceUsed() << std::endl;

    MyString* s3 = google::protobuf::Arena::Create<MyString>(&arena, str3);

    std::cout <<"c1-getNumber() : "<< c1->getNumber() << std::endl;
    std::cout << s0->print() <<std::endl;
    std::cout << s1->print() <<std::endl;
    std::cout << s2->print() <<std::endl;
    std::cout << s3->print() <<std::endl;

    arena.Reset();

    std::cout << "Allocated after reset() : "<< arena.SpaceAllocated()
              <<" Used Spaced : "<< arena.SpaceUsed() << std::endl;

    return 0;

}
