#pragma once
template <typename T, typename S, typename U>
class Triple {
public:
	Triple(T f, S s, U t) {
		this->first = f;
		this->second = s;
		this->third = t;
	}
	T getFirst() { return this->first; }
	S getSecond() { return this->second;  }
	U getThird() { return this->third; }
	void modifyFirst(T f) { this->first = f; }
	void getSecond(S s) { this->second = s; }
	void getThird(U t) { this->third = t; }
protected:
	T first;
	S second;
	U third;
};