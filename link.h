#ifndef LIAO_H
#define LIAO_H
#include <iomanip>
#include<iostream>
#include<string>
using namespace std;

class Node{     //����ڵ�
public:
	Node();
	string num;
	string name;
	string course;
	string grade;
	string term;
	Node *next;
};

void menu();            //������
void find(Node *head);  //��ѯ���ܵĽ���
Node *insert(Node *head);  //���ӹ��ܵĽ���
Node *del(Node *head);     //ɾ�����ܵĽ���
void tongji(Node *head); //ͳ�ƽ���
void update(Node *head); //�޸Ĺ��ܵĽ���
    
Node *fopen();                    //���ļ����ļ���������
void save(Node *head);            //д�ļ����������ݸ��µ��ļ�

#endif