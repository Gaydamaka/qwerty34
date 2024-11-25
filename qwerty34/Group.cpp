#include <iostream>  
#include <cstring> 
using namespace std;
class Group {
private:
    char* groupDescription;

public:
    Group(const string& description) {
        groupDescription = new char[description.length() + 1];
        strcpy(groupDescription, description.c_str());
    }

    bool operator>(const Group& other) const {
        return strcmp(groupDescription, other.groupDescription) > 0;
    }

    bool operator<(const Group& other) const {
        return strcmp(groupDescription, other.groupDescription) < 0;
    }

    bool operator==(const Group& other) const {
        return strcmp(groupDescription, other.groupDescription) == 0;
    }

    bool operator!=(const Group& other) const {
        return !(*this == other);
    }

  
    friend ostream& operator<<(ostream& os, const Group& group) {
        os << "Group Description: " << group.groupDescription;
        return os;
    }

    friend istream& operator>>(istream& is, Group& group) {
        char buffer[256];
        is >> buffer;
        group.setGroupDescription(buffer);
        return is;
    }

    ~Group() {
        delete[] groupDescription;
    }

    void setGroupDescription(const string& description) {
        delete[] groupDescription;
        groupDescription = new char[description.length() + 1];
        strcpy(groupDescription, description.c_str());
    }
};