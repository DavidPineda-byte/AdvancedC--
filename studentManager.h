#include "abstractManager.h"

class studentManager : public abstractManager {
public:
    void add(Student student) override;
    void display() override;
    Student search(int id) override;
    vector<Student> searchByName(string name) override;

private: 
    vector<Student> students; // Vector to store student records
};