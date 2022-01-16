class bb_str{
    char* p;

public:
    
    bb_str(const char* _p);
    bb_str(const bb_str& x);
    bb_str(bb_str&& x);
    bb_str& operator=(bb_str&& x);
    ~bb_str();
    const char * c_str(){return p;};
    void print_info();
};

class bb_str_nxt: bb_str {
    int i;
public:
    bb_str_nxt(const char* _p, int _i):bb_str(_p), i(_i) {};
    ~bb_str_nxt();



};
