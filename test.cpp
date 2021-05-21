#include <iostream>
#include <string>

class BaseCodec {
public:
    virtual ~BaseCodec() {}
    virtual std::string encode(const std::string&) = 0;
};

class myCodec : public BaseCodec {
public:
    myCodec(std::string s) {
        if (s == "Reverse") op = 0;
        else if (s == "Compress") op = 1;
        else op = 2;
    };

    ~myCodec() {};

    std::string encode(const std::string& str) {
        std::string newStr;
        if (op == 0) {
            for (int i = str.size(); i >= 0; i--) newStr += str[i];
        } else if (op == 1) {
            int cnt = 0;
            char prev = str[0];
            for (int i = 0; i < str.size(); i++) {
                if (prev == str[i]) cnt++;
                else {
                    if (cnt == 1) newStr += prev;
                    else if (cnt == 2) newStr += prev, newStr += prev;
                    else {
                        std::string num = "";
                        while (cnt) num = char(cnt % 10 + '0') + num;
                        newStr += num;
                        newStr += prev;
                    }
                    cnt = 1;
                    prev = str[i];
                }
            }
            if (cnt == 1) newStr += prev;
            else if (cnt == 2) newStr += prev, newStr += prev;
            else {
                std::string num = "";
                while (cnt) num = char(cnt % 10 + '0') + num;
                newStr += num;
                newStr += prev;
            }
        } else {
            if (encoded == "") newStr = "None";
            else newStr = encoded;
            encoded = str;
        }
        return newStr;
    }

    int op;
    std::string encoded;
};

int main() {
    BaseCodec *BC;
    myCodec co("Reverse");
    BC = &co;
    std::cout << BC->encode("sr");
}