class Test3
{
public: 
	int i;
	Test3 operator+(const Test3& t){
		Test3 temp;
		temp.i = this->i + t.i;
		return temp;
	}
};