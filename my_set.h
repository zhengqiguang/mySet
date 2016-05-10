#pragma once
#include <iostream>
#include <set>
#include<string>



using namespace std;
class MySet
{
protected:
	
	const int id;//�����ţ��������޸ģ���ʼ��ʱ��ֵ
	static int count;//��¼һ���Ķ�����
	set<string>* element = 0;//ָ��Ԫ��Ϊ�ַ����ļ��ϵ�ָ��
	set<MySet>* set = 0;//ָ��Ԫ��Ϊ���ϵļ��ϵ�ָ��
	bool isbasic;//����Ԫ��Ϊ�ַ���ʱ��Ϊtrue;
	
public:
	const string name;//���������������޸ģ���ʼ��ʱ��ֵ

	MySet(): id(count++){}//�޲ι��캯����ֻ��ID
	MySet(string name) : name(name), id(count++){}//�����Ǽ������Ĺ��캯��
	//���캯��������Ԫ���ɵ�һ�������������������ɵڶ�����������
	MySet(const MySet s, string name) : MySet(name)
	{
		this->isbasic = s.isbasic;
		if (s.element)
		{
			this->element = new std::set<string>;
			*this->element = *s.element;
		}
		if (s.set)
		{
			this->set = new std::set<MySet>;
			*this->set = *s.set;
		}
	}

	MySet add(const string& elementName);//����������ַ���Ԫ��
	MySet add(const MySet& newSet);//��������Ӽ���Ԫ��
	MySet remove(string name);//ɾ���ַ���Ԫ��
	MySet remove(const MySet& s);//ɾ������Ԫ��
	MySet without(const string& name);//�������ų�ĳԪ�أ������ų���ļ���

	bool has(string name) const;//����ĳԪ���Ƿ����
	bool has(MySet set) const;//����ĳԪ���Ƿ����
	int size() const;//���ؼ���Ԫ�ظ���
	bool isEmpty() const;//�ж��Ƿ��ǿռ�

	~MySet() {}

	MySet operator+(const MySet& set);//���ϵĲ���
	MySet operator*(const MySet& set);//���ϵĽ���
	MySet& operator=(const MySet& set);//��ֵ�����(������)
	MySet operator-(const MySet& set);//���������������A-B�Ǵ�A�г�ȥB�к��е�Ԫ��
	bool operator<(const MySet& s) const;//С���������Ϊset����������ã�����ID����
	friend ostream& operator<<(ostream& cout, const MySet& e);//���
};