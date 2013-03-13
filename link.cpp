#include"link.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;

Node::Node()
{
	next=NULL;
}
//�������������
void menu(){   
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"     "<<"1.��ѯ"<<"     "<<"2.����"<<"     "<<"3.ɾ��"<<"    "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl; 
	cout<<"*"<<"     "<<"4.�޸�"<<"     "<<"5.ͳ��"<<"     "<<"6.�˳�"<<"    "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"----����������Ч-----"<<endl;
	cout<<"��ѡ����:";
}

//���ļ�����ȡ��¼����,������������ͷ���
Node *fopen(){
	ifstream stu("d:\\Record.dat");
	if(!stu){                                    //���򿪾ɼ�¼ʧ��
		cout<<endl<<"----�����ڼ�¼�ļ���ϵͳ������һ���µļ�¼�ļ�----"<<endl<<endl;
	    ofstream stu("d:\\Record.dat");
		stu<<"**";
		stu.close();
        Sleep(5000);
        return NULL;
	}
	string a;
	stu>>a;
    if(a=="**")        //���ļ�����Ϊ��
	{
		return NULL;
	}
	Node *h=new Node();
    h->num=a;
	stu>>h->name ;
	stu>>h->course ;
	stu>>h->grade  ;
	stu>>h->term ;

	Node *p1,*p2;
	p1=p2=h;

	string tempnum;
	stu>>tempnum;
	while(tempnum!="**"){         //��¼תΪ����
		p2=new Node();
	    p2->num=tempnum;
      	stu>>p2->name ;
    	stu>>p2->course ;
        stu>>p2->grade  ;
    	stu>>p2->term ;	

        p1->next=p2;
		p1=p2;
		stu>>tempnum;
	}
    stu.close();	
    return h;
}

//�����ļ�����ͷ��㿪ʼ���������浽�ļ�
void save(Node *head)
{
	ofstream stu("d:\\Record.dat");
	if(!stu)
	{
		cout<<"�ļ�����ʧ��,���˳�ϵͳ"<<endl;
		system("pause");
		exit(1);
	}
     
	Node *p1;
	stu<<head->num <<" "<<head->name <<" "<<head->course <<" "<<head->grade <<" "<<head->term <<endl;
	p1=head->next ;
    while(p1!=NULL)
	{
		stu<<p1->num <<" "<<p1->name <<" "<<p1->course <<" "<<p1->grade <<" "<<p1->term <<endl;
		p1=p1->next;
	}
	stu<<"**";
	cout<<"----���³ɹ�----"<<endl;
}

//��ѯ������
void find(Node *head){ 
    void showAll(Node *head);       //���ȫ��ѧ���ɼ�
    void findByName(Node *head);              //��������ѯ
    void findByNum(Node *head);              //��ѧ�Ų�ѯ
    void findByCourse(Node *head);           //����Ŀ��ѯ

	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-��ѯ����-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"   "<<"1.����������ѯ"<<"   "<<"2.����ѧ�Ų�ѯ"<<"   "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"           "<<"5.����ϵͳ����"<<"            "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
    cout<<"*"<<"   "<<"3.���տ�Ŀ��ѯ"<<"   "<<"4.��ʾ���гɼ�"<<"   "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;

	cout<<"----����������Ч-----"<<endl;
    cout<<"��ѡ��";
  
	char choice;
	cin>>choice;
	switch(choice)
	{
    	case '1':findByName(head);break;
	    case '2':findByNum(head);break;
    	case '3':findByCourse(head);break;
     	case '4':showAll(head);break;
    	case '5':system("cls");menu();break;
        default:system("cls");find(head);break;
	}
}

void showAll(Node *head){  //���ȫ��ѧ���ɼ�
	system("cls");
	cout<<"---------���������гɼ���---------"<<endl<<endl;
	cout<<left<<setw(12)<<"  ѧ��"<<setw(8)<<"  ����"<<setw(12)<<"  ��Ŀ"<<setw(6)<<"  �ɼ�"<<setw(6)<<"  ѧ��"<<endl;
    Node *p3;
    p3=head;
    while(p3!=NULL)
	{		
		cout<<left<<setw(12)<<p3->num<<" "<<setw(8)<<p3->name <<" "<<setw(12)<<p3->course<<" "<<setw(6)<<p3->grade<<" "<<setw(6)<<p3->term <<endl;
	 	p3=p3->next;
	}
    cout<<endl<<"---------�ɼ���������---------"<<endl;
	find(head);    //���ز�ѯ����
}

//��������ѯ
void findByName(Node *head){
	Node *p1;
	p1=head;
	string name;
	cout<<"��������ѯ������������:";
	cin>>name;
	system("cls");
	cout<<"----������ѧ�� "<<name<<" �ĳɼ���----"<<endl<<endl;
	cout<<left<<setw(12)<<"  ѧ��"<<setw(12)<<" ��Ŀ"<<setw(6)<<" �ɼ�"<<setw(6)<<" ѧ��"<<endl;
	while(p1!=NULL){
		if(p1->name==name)
		{
			cout<<left<<setw(12)<<p1->num<<" "<<setw(12)<<p1->course<<" "<<setw(6) <<p1->grade<<" "<<setw(6) <<p1->term<<endl;
		}
		p1=p1->next;
	}
	cout<<endl<<endl<<"----��ѯ���,���ɼ���Ϊ�����ʾ�޴�ѧ��----"<<endl;
	find(head);    //���ز�ѯ����
}

//��ѧ�Ų�ѯ
void findByNum(Node *head){
	Node *p1;
	p1=head;
	string num;
	cout<<"��ѧ�Ų�ѯ,����ѧ��:";
	cin>>num;
	system("cls");
	cout<<"---����ѧ��Ϊ "<<num<<"  ��ѧ���ĳɼ���----"<<endl<<endl;
    cout<<left<<setw(8)<<" ����"<<setw(12)<<" ��Ŀ"<<setw(6)<<" �ɼ�"<<setw(6)<<" ѧ��"<<endl;
	while(p1!=NULL){
		if(p1->num==num)
		{
			cout<<left<<setw(8)<<p1->name<<" "<<setw(12)<<p1->course<<" "<<setw(6)<<p1->grade<<" "<<p1->term <<endl;
		}
		p1=p1->next;
	}
	cout<<endl<<endl<<"---��ѯ���,���ɼ���Ϊ�����ʾ�޴�ѧ��----"<<endl;
	find(head);    //���ز�ѯ����
}

//����Ŀ��ѯ
void findByCourse(Node *head){
	Node *p1;
	p1=head;
	string course,term;
	cout<<"�����Ŀ:";
	cin>>course;
	cout<<"����ѧ��:";
    cin>>term;
	
	system("cls");
	cout<<"---�����ǵ� "<<term<<"  ѧ�� "<<course<<" �εĳɼ���----"<<endl<<endl;
	cout<<left<<setw(12)<<" ѧ��"<<setw(8)<<" ����"<<setw(6)<<" �ɼ�"<<endl;
	while(p1!=NULL){
		if(p1->course==course && p1->term==term)
		{
			cout<<left<<setw(12)<<p1->num<<" "<<setw(8)<<p1->name<<" "<<setw(6) <<p1->grade<<endl;
		}
		p1=p1->next;
	}

	cout<<endl<<endl<<"----��ѯ���----"<<endl<<endl;
	find(head);    //���ز�ѯ����
}

//���ӹ��ܵ�������
Node *insert(Node *head){
	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-���Ӽ�¼-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    
	string tempNum,tempName,tempCourse,tempGrade,tempTerm;



	Node *p2;
	p2=head;
    cout<<"����ѧ�ţ�";
    cin >>tempNum ;  
	cout<<"����������";
	cin >>tempName  ;
	cout<<"�����Ŀ��";
	cin >>tempCourse ;
	cout<<"����ɼ���";
	cin >>tempGrade ;
	cout<<"����ѧ�ڣ�";
	cin >>tempTerm ;  


    while(p2!=NULL){           //���������Ϣ�Ѵ���,����������
		if(tempNum==p2->num && tempName==p2->name && tempCourse==p2->course && tempTerm==p2->term )
		{
			system("cls");
			cout<<endl<<"���������ѧ�š���������Ŀ��ѧ���Ѵ���!"<<endl;
			cout<<"----ϵͳ����������----"<<endl;
		    menu();
			return head;
		}
		else
			p2=p2->next;
	}

	Node *p1=new Node();     //����ͷ���
	p1->next=head;
	p1->num=tempNum;
	p1->name=tempName;
	p1->course=tempCourse;
	p1->term =tempTerm;
	p1->grade=tempGrade;


	system("cls");
	cout<<endl<<"������¼���µĳɼ���¼ "<<tempNum<<" "<<p1->name<<" "<<p1->course<<" "<<p1->grade<<" "<<p1->term<<endl;
	save(p1);      //�����ļ�
	menu();              //����������
	return p1;
}

//ɾ�����ܵĽ���
Node *del(Node *head){

	if(head==NULL)     //��Ϊ��
	{
		cout<<endl<<"----�޳ɼ���¼,�޷�����ɾ������----"<<endl;
		return head;
	}
	string tempName,tempCourse,tempTerm;
	Node *temp,*temp2;
    int isOrNot=0;     //0��ʾϵͳ���Ҳ�����ɾ����Ϣ
	system("cls");
	cout<<endl;
    cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-ɾ���ɼ�-"<<"                "<<"*"<<endl;	
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"��������:";
	cin>>tempName;
	cout<<"�����Ŀ:";
	cin>>tempCourse;
	cout<<"����ѧ��:";
	cin>>tempTerm;

	while(head->name ==tempName && head->course ==tempCourse && head->term==tempTerm) //ɾ�����ǵ�һ���ڵ�
	{
		head=head->next;
		isOrNot=1;
	}
	
	temp=temp2=head;       //ɾ���Ĳ��ǵ�һ���ڵ�
	temp2=temp2->next;
	while(temp2!=NULL){
		if(temp2->name==tempName && temp2->course ==tempCourse && temp2->term==tempTerm){
			temp->next=temp2->next;
			isOrNot=1;
		}
		temp=temp2;
		temp2=temp2->next;
	}
	system("cls");
	if(isOrNot==0)	{            //�Ҳ���Ҫɾ������Ϣ
		cout<<endl<<"----�������Ϣ���󣬷���ϵͳ������----"<<endl;
        menu();
		return head;
	}
	else{                 //ɾ���ɹ�
        cout<<"������ɾ��ѧ�� "<<tempName<<" �� "<<tempCourse<<" �ɼ�"<<endl;
    	save(head);         //�����ļ�
    	menu();
    	return head;
	}
}

//�޸Ĺ��ܵ�������
void update(Node *head){
    void updateName(Node *head);
    void updateNum(Node *head);
	void updateGrade(Node *head);

	char choice;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-�޸Ĺ���-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"*"<<"     "<<"1.�޸�����"<<"      "<<"2.�޸�ѧ��"<<"      "<<"*"<<endl;
    cout<<"*"<<"                                     "<<"*"<<endl; 
	cout<<"*"<<"     "<<"3.�޸ĳɼ�"<<"      "<<"4.����ϵͳ"<<"      "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"����������Ч����ѡ����:";

	cin>>choice;
	switch(choice){
    	case '1':system("cls");updateName(head);break;
		case '2':system("cls");updateNum(head);break;
		case '3':updateGrade(head);break;
		case '4':system("cls");menu();break;
		default:
			system("cls");update(head);break;
	}
}

//�޸���������
void updateName(Node *head){
	string name1,name2;
	int isOrNot=0;      //0��ʾҪ�޸ĵ�����������
	Node *p1;
	p1=head;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-�޸�����-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"����ԭ����:";
	cin>>name1;
	cout<<"����������:";
	cin>>name2;
    while(p1!=NULL)
	{
        if(p1->name ==name1){
			p1->name=name2;
			isOrNot=1;
		}
		p1=p1->next ;
	}
	system("cls");
	if(isOrNot==0){         //�޸�ʧ��
		cout<<endl<<"----��ɾ�����������ڣ������޸Ľ���----"<<endl;
		update(head);

	}
    else{                  //�޸ĳɹ�

    	cout<<endl<<"��������ѧ�� "<<name1<<" ����������Ϊ��"<<name2<<endl;
    	save(head);             //�����ļ�
    	update(head);
	}
}

//�޸�ѧ�ź���
void updateNum(Node *head){
	int isOrNot=0;      //0��ʾҪ�޸ĵ�ѧ�Ų�����
	string num1,num2;
	Node *p1;
	p1=head;
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-�޸�ѧ��-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"����ԭѧ��:";
	cin>>num1;
	cout<<"������ѧ��:";
	cin>>num2;
    while(p1!=NULL)
	{
        if(p1->num ==num1){
			p1->num=num2;
			isOrNot=1;
		}
		p1=p1->next ;
	}
	system("cls");
	if(isOrNot==0){         //�޸�ѧ��ʧ��
		cout<<endl<<"----���޸�ѧ�Ų����ڣ������޸Ľ���----"<<endl;
		update(head);

	}

    else{
	    cout<<endl<<"����:ѧ�� "<<num1<<" ����Ϊ:"<<num2<<endl;
    	save(head);             //�����ļ�
    	update(head); 
	}
}

//�޸ĳɼ�����
void updateGrade(Node *head){
	string numOrName,course,term,grade;
	Node *p1,*temp;
	temp=NULL;
	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"           "<<"-�޸ĳɼ�-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
	cout<<"����������ѧ��:";
	cin>>numOrName;
	cout<<"����γ̣�";
	cin>>course;
	cout<<"����ѧ��:";
	cin>>term;
    
	p1=head;
	while(p1!=NULL)
	{
		if((p1->num==numOrName || p1->name ==numOrName) && p1->course==course && p1->term==term){
			temp=p1;
			break;
		}
		p1=p1->next;
	}
	if(temp==NULL){   //����������
    	system("cls");
		cout<<endl<<"----���޸���Ϣ�����ڣ������޸Ľ���----"<<endl;
		update(head);
	}
	else{
    	cout<<"����ԭ��������:"<<temp->grade <<endl;
    	cout<<"�����µķ���:";
    	cin>>grade;
    	temp->grade=grade;
    	system("cls");
    	cout<<endl<<"��������ѧ�� "<<temp->num <<" �� "<<term<<" ѧ�� "<<course<<" �εĳɼ���Ϊ: "<<grade<<endl;
    	save(head);
    	update(head);
	}
}

//ͳ�ƽ���
void tongji(Node *head){
	void tongjiAver(Node *head);

    if(head==NULL){       //�ɼ���¼Ϊ��
		cout<<endl<<"----�޳ɼ���¼���޷�ͳ��----"<<endl;
		menu();
	}
    else{            //�гɼ���¼
    	char choice;
    	cout<<endl;
    	cout<<"***************************************"<<endl;
    	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
    	cout<<"*"<<"          "<<"-ͳ�ƹ���-"<<"                 "<<"*"<<endl;
    	cout<<"*"<<"                                     "<<"*"<<endl;
    	cout<<"*"<<"     "<<"1.ͳ��ƽ����"<<"     "<<"2.����ϵͳ"<<"     "<<"*"<<endl;
    	cout<<"*"<<"                                     "<<"*"<<endl;
    	cout<<"***************************************"<<endl;
        cout<<"����������Ч����ѡ����:";
    	cin>>choice;
 
    	switch(choice){
	    	 case '1':tongjiAver(head);break;
	    	 case '2':system("cls");menu();break;
	    	 default:system("cls");tongji(head);break;
		}
	}
}

void tongjiAver(Node *head){
	Node *p1;
	p1=head;
	string term,course;
	double grade;
	int count=0;
	double sum=0;

	system("cls");
	cout<<endl;
	cout<<"***************************************"<<endl;
	cout<<"*"<<"       "<<"ѧ���ɼ�����ϵͳ v1.0"<<"         "<<"*"<<endl;
	cout<<"*"<<"         "<<"-ͳ��ƽ����-"<<"                "<<"*"<<endl;
	cout<<"*"<<"                                     "<<"*"<<endl;
	cout<<"***************************************"<<endl;
    cout<<"����ѧ�ڣ�";
	cin>>term;
	cout<<"����γ�:";
	cin>>course;
    
	while(p1!=NULL){
		if(p1->term==term && p1->course==course)
		{
			count++;
			grade=atof( (p1->grade).c_str() );
            sum=sum+grade;
		}
		p1=p1->next;
	}
	system("cls");
	if(count==0){
		cout<<endl<<"----���������޷�ͳ��----"<<endl;
	}
	else{
        cout<<endl<<"----ƽ����ͳ��----"<<endl<<endl;
    	cout<<"�� "<<term<<" ѧ�� "<<course<<" �γ̵�ƽ������:"<<endl;
    	cout<<"        "<<sum/count<<endl<<endl;
    	cout<<"----ͳ�����----"<<endl;
	}
	tongji(head);
}