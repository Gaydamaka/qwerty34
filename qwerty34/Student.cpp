#include <iostream>  
#include <cstring> 
using namespace std;

class Student {
private:
    char* researchTopic;

public:
    Student(const string& topic) {
        researchTopic = new char[topic.length() + 1];
        strcpy(researchTopic, topic.c_str());
    }
  
    bool operator>(const Student& other) const {
        return strcmp(researchTopic, other.researchTopic) > 0;
    }

    bool operator<(const Student& other) const {
        return strcmp(researchTopic, other.researchTopic) < 0;
    }

    bool operator==(const Student& other) const {
        return strcmp(researchTopic, other.researchTopic) == 0;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

   
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Student Research Topic: " << student.researchTopic;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        char buffer[256];
        is >> buffer;
        student.setResearchTopic(buffer);
        return is;
    }

    ~Student() {
        delete[] researchTopic;
    }

    void setResearchTopic(const string& topic) {
        delete[] researchTopic;
        researchTopic = new char[topic.length() + 1];
        strcpy(researchTopic, topic.c_str());
    }
};