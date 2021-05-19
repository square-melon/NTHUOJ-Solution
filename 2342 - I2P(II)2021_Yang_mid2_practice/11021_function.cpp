#include "11021.h"

void RleCodec::encode() {
    std::string newString;
    char prev = code_str[0];
    int cnt = 0;
    for (char c : code_str) {
        if (c != prev || cnt == 26) {
            newString = newString + "Q" + char(cnt - 1 + 'A');
            newString += prev;
            cnt = 1;
        } else cnt++;
        prev = c;
    }
    newString = newString + "Q" + char(cnt - 1 + 'A');
    newString += prev;
    
    code_str = newString;

    encoded = true;
}

void RleCodec::decode() {
    std::string newString;
    int cnt = 0, phase = 0;
    for (char c : code_str) {
        if (phase == 0) phase = 1;
        else if (phase == 1) {
            cnt = c - 'A' + 1;
            phase = 2;
        } else {
            while (cnt--) newString += c;
            phase = 0;
        }
    }
    code_str = newString;

    encoded = false;
}