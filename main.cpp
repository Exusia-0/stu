#include"link.h"
#include <iostream>
#include<string>
using namespace std;
	
int main(){
	Node *head=fopen();    //�򿪼�¼�ļ�,תΪ����
//	cout<<endl<<"----���ڽ���ѧ���ɼ�����ϵͳ�����Ե�----"<<endl;
//	Sleep(2000);
    system("cls");

	menu();                //��������
    char choice;
    cin>>choice;
	while(choice!='6'){        //�����湦�ܴ���
		switch(choice)
		{
	    	case '1':system("cls");find(head);break;
			case '2':head=insert(head);break;
			case '3':head=del(head);break;
			case '4':system("cls");update(head);break;
			case '5':system("cls");tongji(head);break;
            default:system("cls");menu();break;
		}
		cin>>choice;
	}
  
    system("cls");
    cout<<endl<<"�Ѱ�ȫ�˳�ϵͳ"<<endl<<endl;;
    system("pause");
	return 0;
}














