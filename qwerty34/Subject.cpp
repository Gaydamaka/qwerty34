#include <iostream>  
#include <cstring> 
using namespace std;

class Subject {
private:
    char* additionalMaterials;

public:
    Subject(const string& materials) {
        additionalMaterials = new char[materials.length() + 1];
        strcpy(additionalMaterials, materials.c_str());
    }
 
    bool operator>(const Subject& other) const {
        return strcmp(additionalMaterials, other.additionalMaterials) > 0;
    }

    bool operator<(const Subject& other) const {
        return strcmp(additionalMaterials, other.additionalMaterials) < 0;
    }

    bool operator==(const Subject& other) const {
        return strcmp(additionalMaterials, other.additionalMaterials) == 0;
    }

    bool operator!=(const Subject& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Subject& subject) {
        os << "Subject Additional Materials: " << subject.additionalMaterials;
        return os;
    }

    friend istream& operator>>(istream& is, Subject& subject) {
        char buffer[256];
        is >> buffer;
        subject.setAdditionalMaterials(buffer);
        return is;
    }

    ~Subject() {
        delete[] additionalMaterials;
    }

    void setAdditionalMaterials(const string& materials) {
        delete[] additionalMaterials;
        additionalMaterials = new char[materials.length() + 1];
        strcpy(additionalMaterials, materials.c_str());
    }
};