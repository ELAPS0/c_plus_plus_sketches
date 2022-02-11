#include <iostream>
#include <string>

using namespace std;

void info(string& bb )
{
	cout<<"object address "<<(void*)&bb<<"\t";
    cout<<"buffer address "<<(void*)bb.c_str()<<"\t";
    cout<<"value "<<bb<<endl;
}
string foo(int i)
{
    string b1 (i, '-');
    info(b1);
    return b1;
}

int main(int argc, char* argv[])
{
	string b0 (22, '+');
	info(b0);
    b0 = foo(10);
    info(b0);
}
