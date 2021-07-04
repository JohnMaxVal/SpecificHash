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

    void insert(const string& value) {
        bool found = search(value);

        if(!found) {
            int index = getInsertIndex(value);
            m_entries[index].data = value;
            m_entries[index].status = "occupied";
        }
    }

    void remove(const string& value) {
        bool found = search(value);
    }

    void print() {
        for(int i = 0; i < size; ++i)
            cout << m_entries[i].data << " " << "(" << m_entries[i].status << ")" << endl;
    }

private:

    bool search(const string value) {
        int index = getTableIndex(value);
        
        for(;;) {

            if(m_entries[index].data == value)
                return true;

            if(m_entries[index].status == "never used")
                return false;
            
            index = (index + 1) % 25;
        }
    }

    int getTableIndex(const string& input) {
        return input.back() - 'a';
    }

    int getInsertIndex(const string& input) {
        int index = getTableIndex(input);

        for(;;) {
            if(m_entries[index].status == "never used" || m_entries[index].status == "tombstone")
                return index;

            index = (index + 1) % 25;
        }
    }

};

// input: Aapple Aorange Dapple Astrawberry
// output: orange strawberry

int main() {
    Hashtable table;

    string input;
    getline(cin, input);

    cout << "Input line: " << input << endl;

    stringstream ss(input);
    string token;
    
    while(ss >> token) {

        cout << "token: " << token << endl;

        if(token[0] == 'A')
            table.insert(&token[1]);
        else if(token[0] == 'D')
            table.remove(&token[1]);
            
    }

    table.print();

    return 0;
}