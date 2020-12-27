//
//  main.cpp
//  29
//
//  Created by Admin on 27.12.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

std::string exams_arr[] = { "math", "phys", "hist", "prog" };

struct Student {
    std::string name;
    int group;
    
    std::map<std::string, int> exams;
    std::map<std::string, int>::iterator examsInit;
    int n;

    void init() {
        std::cout << "Student name: ";
        std::cin >> name;
        std::cout << "Student group: ";
        std::cin >> group;

        for (int i = 0; i < 4; i++) {
            std::cout << "Enter a " << exams_arr[i] << " grade: ";
            std::cin >> exams[exams_arr[i]];
        }
        std::cout << '\n';
    }

};

std::ostream& operator<<(std::ostream& out, Student st) {
    out << "+------------+-------+------+------+------+------+\n";
    out << "| Name       | Group |";

    for (int i = 0; i < 4; i++) {
        out << std::setw(6) << exams_arr[i] << "|";
    }
    out << '\n';

    out << "+------------+-------+------+------+------+------+\n";
    out << '|' << std::setw(12) << st.name << '|' << std::setw(7) << st.group << '|';
    for (st.examsInit = st.exams.begin(); st.examsInit != st.exams.end(); st.examsInit++) {
        out << std::setw(6) << st.examsInit->second << '|';
    }
    out << '\n';
    out << "+------------+-------+------+------+------+------+\n";

    return out;
}


int main() {
    int n;
    std::cout << "How many students do you want to enroll?\n";
    std::cin >> n;

    std::vector<Student> students(n);
    for (auto& student : students)
        student.init();

    std::cout << students[0];
}
