#include <iostream>
#include <vector>
#include "13206_function.cpp"

int main() {
	int Codec_num, Q;
	std::cin >> Codec_num;
	BaseCodec** Codec = new BaseCodec*[Codec_num];
	for (int i = 0; i < Codec_num; i++) {
		std::string op; std::cin >> op;
		Codec[i] = getCodec(op);
	}
	std::cin >> Q;
	while (Q--) {
		int Codec_id;
		std::string input;
		std::cin >> Codec_id >> input;
		std::cout << Codec[Codec_id]->encode(input) << '\n';
	}
	delete[] Codec;
	return 0;
}
