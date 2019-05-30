//µ¥Àý
class Person{
private:
	static Person* instance;
	Person(){};
public:
	static Person* getInstance();
};