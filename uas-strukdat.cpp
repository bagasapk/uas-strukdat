/*	Nama Program : Pemesanan Maskapai Penerbangan Internasional
	Nama		 : 	Anugerah Prima Bagaskara
					Archi Cantona Rusanggara
	NIK			 : 	140810180006 dan 140810180050
	Tanggal		 : 28/09/2019
	Deskripsi	 : Aplikasi untuk memesan tiket maskapai 
	************************************/
	
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Penumpang{
	char NIK[15];
	char nama[20];
	Penumpang* nextPenumpang;
};

struct Maskapai{
	char Pswt[20];
	Penumpang* FirstPswt;
	Maskapai* next;
};

typedef Maskapai* pointerPswt;
typedef Penumpang* pointerPenumpang;

typedef pointerPswt ListPswt;

void createListPswt(ListPswt& First);
void createElementPswt(pointerPswt& pBaru);
void createElementPenumpang(pointerPenumpang& pBaru);
void traversalPswt(ListPswt FirstPswt);
void linearSearch(ListPswt FirstPswt, char key[20], int& status, pointerPswt& pCari);
void insertFirstPswt(ListPswt& FirstPswt, pointerPswt pBaru);
void deleteFirstPswt(ListPswt& FirstPswt, pointerPswt& pHapus);
void insertFirstPswt(ListPswt& First, char key[20], pointerPenumpang pBaru);
void deleteFirstPswt(ListPswt& First, char key[20], pointerPenumpang& pHapus);
void traversalPenumpang(ListPswt FirstPswt);
void traversalMaskapai(ListPswt FirstPswt);

main(){
	ListPswt FirstPswt;
	pointerPswt pPswt, pHapus;
	pointerPenumpang qPenumpang, qHapus;
	char key[20],dari[20],tujuan[20],imel[100];
	int status,pilihan;
	createListPswt(FirstPswt);
	cout<<"=================================================================="<<endl;
	cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
	cout<<"=================================================================="<<endl;
	cout<<"Hey Kamu! Mau kemana? "<<endl;
	cout<<"Masukkan Tujuanmu sekarang!!"<<endl;
	cout<<"Email Pemesan 	: ";cin>>imel;
	cout<<"Dari 		: ";cin>>dari;
	cout<<"Tujuan 		: ";cin>>tujuan;
	do{
		system("pause");
		system("cls");
		cout<<"=================================================================="<<endl;
		cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
		cout<<"=================================================================="<<endl;
		cout<<setw(30)<<dari<<"-"<<tujuan<<endl;
		cout<<"1. Insert Maskapai"<<endl;
		cout<<"2. Delete Maskapai Terakhir "<<endl;
		cout<<"3. Insert Penumpang "<<endl;
		cout<<"4. Delete Penumpang Terakhir "<<endl;
		cout<<"5. Cetak Semua Maskapai"<<endl;
		cout<<"6. Cetak Tiket Per Maskapai"<<endl;
		cout<<"0. Keluar"<<endl;
		cout<<"Pilihan Menu \t: ";
		cin>>pilihan;
		switch(pilihan){
		case 1:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;
			createElementPswt(pPswt);
			insertFirstPswt(FirstPswt,pPswt);
			traversalPswt(FirstPswt);
			system("pause");
			break;
		case 2:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;
			deleteFirstPswt(FirstPswt, pHapus);
			traversalPswt(FirstPswt);
			system("pause");
			break;
		case 3:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;
			cout << "Nama Maskapai 	: "; 
			cin >> key;
			createElementPenumpang(qPenumpang);
			insertFirstPswt(FirstPswt, key, qPenumpang);
			traversalPenumpang(FirstPswt);
			system("pause");
			break;
		case 4:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;
			cout << "Nama Maskapai 	: "; 
			cin >> key;
			deleteFirstPswt(FirstPswt,key, qHapus);
			traversalPenumpang(FirstPswt);
			system("pause");
			break;			
		case 5:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;
			traversalPswt(FirstPswt);
			system("pause");
			break;
		case 6:
			system("CLS");
			cout<<"=================================================================="<<endl;
			cout<<"                 Selamat Datang di Arbag Tiket                    "<<endl;
			cout<<"=================================================================="<<endl;	
			traversalMaskapai(FirstPswt);
			system("pause");
			break;
		}
		cout<<endl<<endl;
		system("cls");
	}
	while(pilihan!=0);
	cout<<"Tiket anda sudah kami data! Silahkan cek email anda.";
}

void createListPswt(ListPswt& First){
	First = NULL;
}

void createElementPswt(pointerPswt& pBaru){
	pBaru = new Maskapai;
	cout << "\tMaskapai : "; cin.ignore(); cin.getline(pBaru->Pswt,20);
	cout << endl;
	pBaru->next = NULL;
	pBaru->FirstPswt = NULL;
}

void createElementPenumpang(pointerPenumpang& pBaru){
	pBaru = new Penumpang;
	cout << "\tNIK	    : "; cin >> pBaru->NIK;
	cout << "\tNama	    : "; cin.ignore(); cin.getline(pBaru->nama,20);
	cout << endl;
	pBaru->nextPenumpang = NULL;
}
void traversalPswt(ListPswt FirstPswt){
	int i = 1;
	pointerPenumpang pBantuPenumpang;
	pointerPswt pBantuPswt;
	pBantuPswt = FirstPswt;
	if (FirstPswt ==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		cout<<"\nDaftar Maskapai Semua"<<endl;
		cout<<setw(28)<<setfill('-')<<"-"<<endl;
		cout<<"| No | Nama Maskapai         |"<<endl;
		cout<<setw(28)<<setfill('-')<<"-"<<endl;
		while(pBantuPswt != NULL){
		pBantuPenumpang = pBantuPswt->FirstPswt;
		cout<<"| "<< i <<"  | ";
		cout<<left<<setw(20)<<setfill(' ')<<pBantuPswt->Pswt<<"| ";
	
		pBantuPswt = pBantuPswt->next;
		i = i+1;		
		cout << endl;
	}
	cout<<setw(28)<<setfill('-')<<"-"<<endl;
	}
}

void linearSearch(ListPswt FirstPswt, char key[20], int& status, pointerPswt& pPswt){
	status = 0;
	pPswt=FirstPswt;
	while(status == 0 && pPswt != NULL){
		if(strcmp(pPswt -> Pswt,key) == 0){
			status=1;
		}
		else
			pPswt=pPswt->next;
	}
}

void insertFirstPswt(ListPswt& FirstPswt, pointerPswt pBaru){
	if (FirstPswt == NULL){
		FirstPswt = pBaru;
	}
	else{
		pBaru->next = FirstPswt;
		FirstPswt = pBaru;
	}
}

void deleteFirstPswt(ListPswt& FirstPswt, pointerPswt& pHapus){
	if(FirstPswt == NULL){
		pHapus = NULL;
		cout << "LIST KOSONG \n";
	}
	else if(FirstPswt->next == NULL){
		pHapus = FirstPswt;
		FirstPswt = NULL;
	}
	else{
		pHapus = FirstPswt;
		FirstPswt = FirstPswt->next;
		pHapus->next = NULL;
	}
}

void insertFirstPswt(ListPswt& First, char key[20], pointerPenumpang pBaru){
	pointerPswt pRuru;
	int ketemu;
	cout<<"Insert First Penumpang"<<endl;
	pRuru = First;
	ketemu = 0;
	while(pRuru != NULL && ketemu == 0){
		if(strcmp(pRuru -> Pswt,key) == 0){
			ketemu = 1;
		}
		else
			pRuru = pRuru -> next;
	}
	if(ketemu){
		cout<<"Ditemukan"<<endl;
		if(pRuru->FirstPswt == NULL){
			pRuru->FirstPswt=pBaru;
			
		}
		else {
			pBaru -> nextPenumpang =pRuru->FirstPswt;
			pRuru -> FirstPswt=pBaru;
		}
	}
	else{
		cout<<"Tidak Ditemukan"<<endl;
	}
}

void deleteFirstPswt(ListPswt& First, char key[20], pointerPenumpang& pHapus){
	pointerPswt pRuru;
	int ketemu;
	
	cout<<"Delete First Penumpang"<<endl;
	
	pRuru=First;
	ketemu=0;
	while (pRuru !=NULL && ketemu ==0){
		if(strcmp(pRuru -> Pswt,key) == 0){
			ketemu=1;
		}
		else
			pRuru=pRuru->next;
	}
	
	if (ketemu){
		if (pRuru->FirstPswt==NULL){
			pHapus==NULL;
			cout<<"List kosong, tidak ada hapus"<<endl;
				
		}
		else if (pRuru->FirstPswt->nextPenumpang==NULL){
			pHapus=pRuru->FirstPswt;
			pRuru->FirstPswt=NULL;
		}
		else {
			pHapus=pRuru->FirstPswt;
			pRuru->FirstPswt=pRuru->FirstPswt->nextPenumpang;
			pHapus->nextPenumpang;
		}
	}
	else {
		cout<<"Tidak ditemukan"<<endl;
	
	}
}

void traversalPenumpang(ListPswt FirstPswt){
	int i = 1;
	pointerPenumpang pBantuPenumpang;
	pointerPswt pBantuPswt;
	pBantuPswt = FirstPswt;
	if (FirstPswt==NULL){
		cout<<"List kosong"<<endl;
	}
	else{
		cout<<"\nDaftar Penumpang"<<endl;
		cout<<setw(62)<<setfill('-')<<"-"<<endl;
		cout<<"| No | Nama Maskapai       | NIK           | Nama              |"<<endl;
		cout<<setw(62)<<setfill('-')<<"-"<<endl;
		while(pBantuPswt != NULL){
		pBantuPenumpang = pBantuPswt->FirstPswt;
		cout<<"| "<< i <<"  | ";
		cout<<left<<setw(18)<<setfill(' ')<<pBantuPswt->Pswt<<"| ";
		if(pBantuPenumpang != NULL){
			cout<<left<<setw(14)<<pBantuPenumpang->NIK<<"| ";
			cout<<left<<setw(18)<<pBantuPenumpang->nama<<"| "<< endl;
			if (pBantuPenumpang->nextPenumpang != NULL){
				pBantuPenumpang = pBantuPenumpang->nextPenumpang;
				while(pBantuPenumpang != NULL){
					cout<<"|    | ";
					cout<<left<<setw(18)<<setfill(' ')<<" "<<"| ";
					cout<<left<<setw(14)<<pBantuPenumpang->NIK<<"| ";
					cout<<left<<setw(18)<<pBantuPenumpang->nama<<"| "<< endl;
					pBantuPenumpang = pBantuPenumpang -> nextPenumpang;
				}
			}
		}
		pBantuPswt = pBantuPswt->next;
		i = i+1;
		cout<<endl;		
		}
	cout<<setw(62)<<setfill('-')<<"-"<<endl;
	}
}

void traversalMaskapai(ListPswt FirstPswt) {
	pointerPswt pBantuPswt = FirstPswt;
	pointerPenumpang pBantuPenumpang;
	int n=1;
	while (pBantuPswt != NULL) {
		cout << "Maskapai " << pBantuPswt -> Pswt << endl;
		if(pBantuPswt -> FirstPswt == NULL) {
			cout << "Maskapai belum terisi !" << endl;
		}
		else {
			pBantuPenumpang = pBantuPswt -> FirstPswt;
			cout << "--------------------------------------------------------" << endl;
			cout << "| NO |      NIK      |               NAMA              |" << endl;
			cout << "--------------------------------------------------------" << endl;
			while (pBantuPenumpang != NULL){
				cout<<left<<setfill(' ')<<"| "<<setw(2)<<n;
				cout<<left<<" | "<<setw(13)<<pBantuPenumpang -> NIK;
				cout<<left<<" | "<<setw(32)<<pBantuPenumpang -> nama;
				cout<< "|" <<endl;
				n++;
				pBantuPenumpang = pBantuPenumpang -> nextPenumpang;
			}
			cout << "--------------------------------------------------------" << endl;
			n = 1;
		}
		cout << endl << endl;
		pBantuPswt = pBantuPswt -> next;
	}
}

