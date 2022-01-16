#include <iostream>
#include <cstring>
#include "bb_str.h"

using namespace std;

bb_str::bb_str(const char* _p){
    p = new char[strlen(_p)];
    strcpy(p, _p);
    print_info();
    cout<<"bb_str constructor done" << endl;
}

//конструктор копирования 
bb_str::bb_str(const bb_str& x){
    p = new char[strlen(x.p)];
    strcpy(p, x.p);
    print_info();
    cout<<"bb_str copy constructor done" << endl;
}
//конструктор перемещения
bb_str::bb_str(bb_str&& x):p(x.p){
    cout << "original object was:\n";
    x.print_info();
    x.p = nullptr;
    
    cout << "this object:\n";
    print_info();
    
    cout<<"bb_str move constructor done" << endl;
}
//оператор присваивания перемещением
bb_str& bb_str::operator=(bb_str&& x){
    if(this == &x){
        cout<<"self moving ))\n";
        return *this;
    }

    cout << "original object was:\n";
    x.print_info();

    p = x.p;
    x.p = nullptr;

    cout << "this object:\n";
    print_info();
    cout<<"bb_str move operator done" << endl;
    return *this;
}


bb_str::~bb_str(){
    cout<<"bb_str destructor run ("<<p<<")" << endl;
    if (p)
        delete[] p;
}

void bb_str::print_info(){
    cout<<(void*)this<<"\t"<<"buffer address "<<(void*)p<<" : "<<p<<endl;
}

bb_str_nxt::~bb_str_nxt(){
    cout<<"bb_str_nxt destructor run ("<<i<<")" << endl;
}
