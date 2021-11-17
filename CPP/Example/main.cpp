
#include <iostream>
#include <string>


class A {
	std::string str;
	public:
	A(std::string s) { str = s; }
		std::string getStr() {
			return str;
		}
};
class B {
	std::string str;
	public:
	B(std::string s) { str = s; }
		std::string& getStr() {
			return str;
		}
};
class C {
	std::string str;
	public:
	C(std::string s) { str = s; }
		const std::string& getStr() {
			return str;
		}
};

int main()
{

A a("test1");
	B b("test2");
	C c("test3");
	
	// c.setStr("gianni");
	std::cout << a.getStr() << ' ' << b.getStr() << ' ' << c.getStr() << std::endl;
	a.getStr() = "ciao";
	b.getStr() = "ciao";
	//c.getStr() = "ciao";
	std::cout << a.getStr() << ' ' << b.getStr() << ' ' << c.getStr() << ' ' << std::endl;
}