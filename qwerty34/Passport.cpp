#include <iostream>  
#include <cstring> 
using namespace std; 

class Passport {
private:
    char* additionalInfo;

public:
    Passport(const string& info) {
        additionalInfo = new char[info.length() + 1];
        strcpy(additionalInfo, info.c_str());
    }
  
    bool operator>(const Passport& other) const {
        return strcmp(additionalInfo, other.additionalInfo) > 0;
    }

    bool operator<(const Passport& other) const {
        return strcmp(additionalInfo, other.additionalInfo) < 0;
    }

    bool operator==(const Passport& other) const {
        return strcmp(additionalInfo, other.additionalInfo) == 0;
    }

    bool operator!=(const Passport& other) const {
        return !(*this == other);
    }

    
    friend ostream& operator<<(ostream& os, const Passport& passport) {
        os << "Passport Info: " << passport.additionalInfo;
        return os;
    }

    friend istream& operator>>(istream& is, Passport& passport) {
        char buffer[256];
        is >> buffer;
        passport.setAdditionalInfo(buffer);
        return is;
    }

    ~Passport() {
        delete[] additionalInfo;
    }

    void setAdditionalInfo(const string& info) {
        delete[] additionalInfo;
        additionalInfo = new char[info.length() + 1];
        strcpy(additionalInfo, info.c_str());
    }
};