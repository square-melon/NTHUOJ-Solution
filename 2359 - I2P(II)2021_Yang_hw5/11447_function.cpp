#include "11447.h"
#include <iostream>
#include <vector>

namespace oj {
    
    void insert(std::map<int,String> &ma,int key,const std::string &str) {
        std::string tmp;
        if (ma.find(key) != ma.end()) {
            tmp = ma.find(key)->second.str;
            tmp = str + tmp;
            ma.erase(key);
        } else
            tmp = str;
        ma.insert(std::pair<int, String>(key, String(tmp)));
    }

    void output(const std::map<int,String> &ma,int begin,int end) {
        for (auto it : ma) {
            if (it.first >= begin && it.first <= end)
                std::cout << it.second << ' ';
        }
    }

    void erase(std::map<int,String> &ma,int begin,int end) {
        std::vector<int> toerase;
        for (auto it : ma) {
            if (it.first >= begin && it.first <= end)
                toerase.push_back(it.first);
        }
        for (auto it : toerase)
            ma.erase(it);
    }

    std::ostream& operator<<(std::ostream &os, const std::map<int, String> &ma) {
        for (auto it : ma) {
            os << it.second << ' ';
        }
        return os;
    }
}