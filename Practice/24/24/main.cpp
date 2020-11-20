//
//  main.cpp
//  24
//
//  Created by Admin on 20.11.2020.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    json in;
    json out = json::array();
    std::ifstream rd("in.json");
    
    rd >> in;
    
    int count_users = in.back().back();
    
    int* complited_task = new int[count_users] {0};

    for (int i = 0; i < in.size(); i++) {
        for (int j = 0; j < count_users; j++) {
            if (in[i]["userId"] == j && in[i]["completed"]) {
                complited_task[j]++;
            }
        }
    }
    json tmp;

    for (int i = 0; i < count_users; i++) {
        tmp[i]["task_completed"] = complited_task[i];
        tmp[i]["userId"] = i;
    }
    out.push_back(tmp);

    std::ofstream append("out.json");
    append << std::setw(2) << out;

    delete[] complited_task;
    return 0;
}
