#include <iostream>
#include <vector>
#include <cassert>
#include "13199_function.cpp"
using std::size_t;

const int MAX_VAL = 1000000000;
const int MOD = 888888887; 
int cntnew1, cntnew2;
unsigned int seed, hash;
unsigned int z1, z2, z3, z4;

void setRand(unsigned int);
unsigned int Rand();
void updateHash(unsigned int);

struct Test{
	oj::Vector v;
	std::vector<oj::value_type> stdv;
	Test() = default;
	~Test() = default;
	void compareVector() {
		updateHash(v.size());
		assert(v.size() == stdv.size());
		assert(v.empty() == stdv.empty());
		for (size_t i = 0; i < v.size(); i++) assert(v[i] == stdv[i]);
	}
	void testCopy(int rnd) {
		oj::Vector tmp(v);
		oj::Vector tmp2(tmp);
		if (rnd % 10 == 0) tmp.clear();
		tmp.insert(0, rnd, rnd % 100);
		tmp2 = tmp;
		assert(tmp2.size() == tmp.size());
		assert(tmp2.empty() == tmp.empty());
		for (size_t i = 0; i < tmp.size(); i++) assert(tmp2[i] == tmp[i]);
	}
	void testfrontback(oj::value_type val) {
		v.front() += val;
		v.back() += val;
		stdv.front() += val;
		stdv.back() += val;
		compareVector();
	}
	void testerase(size_t pos) {
		v.erase(pos);
		stdv.erase(stdv.begin() + pos);
		compareVector();
	}
	void testinsert(size_t pos, size_t cnt, const oj::value_type& val) {
		v.insert(pos, cnt, val);
		stdv.insert(stdv.begin() + pos, cnt, val);
		compareVector();
	}
	void testpopback() {
		v.pop_back();
		stdv.pop_back();
		compareVector();
	}
	void testpopfront() {
		v.pop_front();
		stdv.erase(stdv.begin());
		compareVector();
	}
	void testpushback(const oj::value_type& val) {
		v.push_back(val);
		stdv.push_back(val);
		compareVector();
	}
	void testpushfront(const oj::value_type& val) {
		v.push_front(val);
		stdv.insert(stdv.begin(), 1, val);
		compareVector();
	}
	void testreserve(size_t new_cap) {
		size_t old_cap = v.capacity();
		v.reserve(new_cap);
		stdv.reserve(new_cap);
		if (new_cap > old_cap) assert(v.capacity() == new_cap); 
		compareVector();
	}
	void testshrinktofit() {
		v.shrink_to_fit();
		assert(v.size() == v.capacity());
		stdv.shrink_to_fit();
		compareVector();
	}
	void clear() {
		v.clear();
		v.clear();
		stdv.clear();
		assert(v.empty() == stdv.empty());
		assert(v.size() == stdv.size());
	}
};

int main() { 
	{
		std::cin >> seed;
		setRand(seed);
		Test test;
		int T = 2000;
		while(T--) {
			int op;
			do{
				op = Rand() % 11;
			} while (test.stdv.empty() and (op == 3 or op == 5 or op == 6 or op == 2));
			switch(op) {
				case 0: test.clear(); break;
				case 1: test.testCopy(Rand() % 10000); break;
				case 2: test.testfrontback(Rand() % MAX_VAL); break;
				case 3: test.testerase(Rand() % test.v.size()); break;
				case 4: test.testinsert(Rand() % (test.v.size() + 1), Rand() % 1000, Rand() % MAX_VAL); break;
				case 5: test.testpopback(); break;
				case 6: test.testpopfront(); break;
				case 7: test.testpushback(Rand() % MAX_VAL); break;
				case 8: test.testpushfront(Rand() % MAX_VAL); break;
				case 9: test.testreserve((test.v.size() == 0 ? 0 : Rand() % test.v.size()) + (test.v.size() >> 1)); break;
				case 10: test.testshrinktofit(); break;
			}
		}
	}
	assert(!cntnew1 and !cntnew2);
	std::cout << hash << " AC\n";
	return 0;
}


void setRand(unsigned int seed) {
	z1 = seed;
	z2 = seed << 10;
	z3 = seed << 20;
	z4 = seed << 30;
}
unsigned int Rand () {
   unsigned int b;
   b  = ((z1 << 6) ^ z1) >> 13;
   z1 = ((z1 & 4294967294U) << 18) ^ b;
   b  = ((z2 << 2) ^ z2) >> 27; 
   z2 = ((z2 & 4294967288U) << 2) ^ b;
   b  = ((z3 << 13) ^ z3) >> 21;
   z3 = ((z3 & 4294967280U) << 7) ^ b;
   b  = ((z4 << 3) ^ z4) >> 12;
   z4 = ((z4 & 4294967168U) << 13) ^ b;
   return (z1 ^ z2 ^ z3 ^ z4);
}
void updateHash(unsigned int x) {
	hash ^= x ^ (x << 10) ^ (x << 20) ^ (x << 30);
}

void* operator new(std::size_t count) {
	cntnew1++;
	void* p = malloc(count);
	return p;
}
void* operator new[](std::size_t count) {
	cntnew2++;
	void* p = malloc(count);
	return p;
}
void operator delete(void *p) noexcept {
	if (!p) return;
	cntnew1--;
	free(p);	
}
void operator delete[](void *p) noexcept {
	if (!p) return;
	cntnew2--;
	free(p);
}

