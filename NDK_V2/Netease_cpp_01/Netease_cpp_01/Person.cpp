//µ¥ÀıÊµÏÖ
#include "Person.h"
Person* Person::instance = 0;

Person* Person::getInstance(){
	if (!instance){
		instance = new Person();
	}
	return instance;
}