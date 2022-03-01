#include<iostream>
using namespace std;

struct Tanggal_Lahir{
  string Bulan;
  int Tanggal, Tahun;

  Tanggal_Lahir*next;
};
  Tanggal_Lahir*head,*tail,*cur,*newNode,*del, *before;

void createSingleLinkedList(int Tanggal,string Bulan, int Tahun){
	head = new Tanggal_Lahir();
	head->Tanggal=Tanggal;
	head->Bulan=Bulan;
	head->Tahun=Tahun;
	head->next=NULL;
	tail=head;
}
	int countSingleLinkedList(){
		cur=head;
		int jumlah=0;
		while(cur!=NULL){
			jumlah++;
			cur=cur->next;
		}
		return jumlah;
}
void addFirst(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=head;
	head=newNode;
}
void addLast(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=NULL;
	tail->next=newNode;
	tail=newNode;	
}
void addMiddle(int Tanggal, string Bulan, int Tahun,int posisi){
	newNode=new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;

	cur=head;
	int nomor=1;
	while (nomor < posisi-1){
		cur=cur->next;
		nomor++;
	}
	
	newNode->next= cur->next;
	cur->next=newNode;
		
	}

void DeleteFirst(){
	
	del=head;
	head=head->next;
	delete del;
}
void DeleteLast(){
	del= tail;
	cur= head;
	while(cur->next != tail){
		cur=cur->next;
	}
	tail=cur;
	tail->next=NULL;
	delete del;
}

void DeleteMiddle(int posisi){
	if(posisi < 1||posisi > countSingleLinkedList() ){
		cout<<"Posisi diluar jangkauan"<<endl;
	}else if(posisi==1||posisi== countSingleLinkedList() ){
		cout <<"Posisi Bukan Posisi Tengah"<<endl;
	}else{
	int nomor=1;
		cur=head;
	while(nomor<=posisi){
		if(nomor== posisi -1){
			before=cur;				
			}
		if(nomor == posisi){
			del=cur;
			}
		cur= cur ->next;
		nomor++;
		}
		before->next=cur;
		delete del;	
	}
}

void printSingleLinkedList(){
	cout<<"Jumlah data ada:"<< countSingleLinkedList()<< endl;
	cur=head;
	while(cur!=NULL){
		cout<<"Tanggal Lahir:"<<cur->Tanggal<<endl;
		cout<<"Bulan Lahir:"<<cur->Bulan<<endl;
		cout<<"Tahun Lahir:"<<cur->Tahun<<endl;
		
		cur=cur->next;
	}
}
int main (){

  createSingleLinkedList(1,"April", 2003);
  printSingleLinkedList();
  
  cout<<"\n\n"<<endl;
  addFirst(11,"Maret",2004);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  

  addLast(19,"Desember",2003);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  addMiddle(9,"Januari",2003,2);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  DeleteFirst();
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  addLast(06,"Februari", 2021);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  DeleteLast();
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  cout<<"\n\n"<<endl;
  
  DeleteMiddle(1);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  
}
