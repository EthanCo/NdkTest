//��ֹ��ͷ�ļ����ظ�����
#ifndef Student_H

#define Student_H
class Student{
	//��Ԫ����
	friend void studentFriendMethod(Student*);
	//��Ԫ�� (��Ԫ�����κζ��������Ե��ã���Ԫ��������Ƶ�������)
	friend class Teacher;
	int i;
public:
	Student(int i,int j);
	~Student(); //��������
	void setJ(int j) const; /*����const���ǳ��������������޸ģ����ӾͿ����޸�*/
	int getJ(){
		return j;
	}
private:
	int j;
protected:
	int k;
public:
	int l;
};
class Teacher{
public:
	void call(Student* s){
		s->j =10086;
	}
};
#endif
