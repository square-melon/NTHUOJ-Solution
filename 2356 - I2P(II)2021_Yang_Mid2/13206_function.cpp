#include "13206.h"

class myCodec : public BaseCodec {
public:
    myCodec(std::string s) {
        if (s == "Reverse") op = 0;
        else if (s == "Compress") op = 1;
        else op = 2;
    };

    ~myCodec() {delete this;};

    std::string encode(const std::string& str) {
        std::string newStr = "";
        if (op == 0) {
            for (int i = str.size() - 1; i >= 0; i--) newStr += str[i];
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
                        while (cnt) {
                            num = char(cnt % 10 + '0') + num;
                            cnt /= 10;
                        }
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
                while (cnt) {
                    num = char(cnt % 10 + '0') + num;
                    cnt /= 10;
                }
                newStr += num;
                newStr += prev;
            }
        } else {
            newStr = encoded;
            encoded = str;
        }
        return newStr;
    };

    int op;
    std::string encoded;
};

BaseCodec* getCodec(const std::string &name) {
    myCodec *mycodec = new myCodec(name);
    mycodec->encoded = "None";
    BaseCodec *baseCodec = mycodec;
    return baseCodec;
}