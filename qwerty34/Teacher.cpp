#include <iostream>  
#include <cstring> 
using namespace std;

class Teacher {
private:
    char* specialization;

public:
    Teacher(const string& spec) {
        specialization = new char[spec.length() + 1];
        strcpy(specialization, spec.c_str());
    }

    bool operator>(const Teacher& other) const {
        return strcmp(specialization, other.specialization) > 0;
    }

    bool operator<(const Teacher& other) const {
        return strcmp(specialization, other.specialization) < 0;
    }

    bool operator==(const Teacher& other) const {
        return strcmp(specialization, other.specialization) == 0;
    }

    bool operator!=(const Teacher& other) const {
        return !(*this == other);
    }
 
    friend ostream& operator<<(ostream& os, const Teacher& teacher) {
        os << "Teacher Specialization: " << teacher.specialization;
        return os;
    }

    friend istream& operator>>(istream& is, Teacher& teacher) {
        char buffer[256];
        is >> buffer;
        teacher.setSpecialization(buffer);
        return is;
    }

    ~Teacher() {
        delete[] specialization;
    }

    void setSpecialization(const string& spec) {
        delete[] specialization;
        specialization = new char[spec.length() + 1];
        strcpy(specialization, spec.c_str());
    }
};