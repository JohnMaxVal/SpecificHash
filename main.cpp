#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Hashtable {

private:
    struct Entry {
        string data;
        string status;
    };

public:
    const static int size = 26;
    Entry m_entries[size];

public:
    Hashtable() {
        for(int i = 0; i < size; ++i)
            m_entries[i].status = "never used";
    }

    void print() {
        for(int i = 0; i < size; ++i)
            cout << m_entries[i].data << " " << "(" << m_entries[i].status << ")" << endl;
    }

};

// input: Aapple Aorange Dapple Astrawberry
// output: orange strawberry

int main() {
    Hashtable table;
    //table.print();

    string input;
    getline(cin, input);

    cout << "Input line: " << input << endl;

    stringstream ss(input);
    string token;
    
    while(ss >> token) {
        
        if(token[0] == 'A')
            cout << &token[1] << endl;
        else if(token[0] == 'D')
            cout << &token[1] << endl;
            
    }

    return 0;
}