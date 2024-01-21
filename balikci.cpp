#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <locale.h>
using namespace std;



//BUARAK DURAN
//2312721019
//BALIKCI OTOMASYONU



struct balikBilgileri
{
	string balikIsmi;
	float stok;
	float fiyat;	
};

struct satisBilgileri
{
	balikBilgileri satilanBalik;
	float toplam;
	int adet;	
};

void balikEkle()
{
	ofstream bilgiler("balik.txt", ios::app);
	char secim;
	int sayi=0;
	balikBilgileri balik;

	do
	{
		
	cout << "Balýk ismi giriniz: " ;
	cin >> balik.balikIsmi ; 
	
	cout << "Lütfen " << balik.balikIsmi << " balýðýnýn stoðunu giriniz: " ;
	cin >> balik.stok ;
	
	cout << "Lütfen " << balik.balikIsmi << " balýðýnýn fiyatýný giriniz: " ;
	cin >> balik.fiyat ; 

	bilgiler << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 
	
	cout << "Baþka balýk girisi yapmak ister misiniz? (E/H): ";	
	secim=getche();	
	cout << endl;
	sayi++;
		
	}
	while(secim=='e' || secim=='E');
	cout << sayi << " Adet balýk girisi yapýldý." << endl;
	bilgiler.close();		
	
}

void balikListeleme()
{
	balikBilgileri balik;
	ifstream okuma("balik.txt");
	cout << setw(10) << "BALIK" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
	while(!(okuma.eof()))
	{
		okuma >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
	}
}

void balikArama()
{
	balikBilgileri balik;
	ifstream okuma("balik.txt");
	cout << "Hangi balýðý görmek istiyorsunuz?: " ;
	string isim;
	cin >> isim;
	int sayac=0;
	cout << setw(10) << "BALIK" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(balik.balikIsmi==isim){
		cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
		sayac++;
		}
	}
	if(sayac==0)
	{
		cout << "Böyle bir balýk yoktur" << endl;
	}
}

void balikSilme()
{
	balikBilgileri balik;
	cout << "><(((º>   ELÝMÝZDE OLAN BALIKLAR   <º)))><" << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("balik.txt");
	char secim;
	int sayac=0;
	
	while(!(okuma.eof()))
	{
		okuma >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
	}
	ifstream okuma2("balik.txt");
	cout << "Stoðu Olmadýðý için Silinen Balýklar " << endl;
	
	while(!(okuma2.eof()))
	{
		
		okuma2 >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(balik.stok==0)
		{
			cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
			sayac++;
		}
		else
		{
			yedek << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 		
		}
	}
	if(sayac>0)
	{
	
	cout << sayac << " Adet Balýk Silindi" << endl;
}
	else
	{
		cout << "Balýk silinmedi" << endl;
	}
	okuma2.close();
	okuma.close();
	yedek.close();
	
	
	remove("balik.txt");
	rename("yedek.txt", "balik.txt");
}


void balikGuncelleme()
{
	balikBilgileri balik;
	cout << "><(((º>   ELÝMÝZDE OLAN BALIKLAR   <º)))><" << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("balik.txt");
	char secim;
	do
	{
	while(!(okuma.eof()))
	{
		okuma >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
	}
	ifstream okuma2("balik.txt");
	cout << "Hangi Balýðý Güncellemek Ýstiyorsunuz?" << endl;
	string isim;
	cin >> isim;
		while(!(okuma2.eof()))
	{
		okuma2 >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(isim==balik.balikIsmi)
		{
			cout << "Balýk Ýsmi Giriniz: " ;
			cin >> balik.balikIsmi ; 
	 
			cout << "Lütfen " << balik.balikIsmi << " Balýðýnýn Stoðunu Giriniz: " ;
			cin >> balik.stok ;
	
			cout << "Lütfen " << balik.balikIsmi << " Balýðýnýn Fiyatýný Giriniz: " ;
			cin >> balik.fiyat ; 
		
			yedek << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 
		
		}
		else
		{
			yedek << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 		
		}
	}
	
	

	okuma2.close();
	okuma.close();
	yedek.close();
	
	cout << "Baþka Balýk Satýþý Yapmak Ýster misiniz? (E/H)" << endl;	
	secim=getche();	 
	}
	while(secim=='e' || secim=='E');
		
	remove("balik.txt");
	rename("yedek.txt", "balik.txt");
}
    
void satisListeleme()
{
	float toplam=0;
	satisBilgileri satislar;
	ifstream okuma("satis.txt");
	cout << setw(10) << "Balýk" << setw(10) << "Fiyat" << setw(10) << "Adet" << setw(15) << "Toplam fiyat" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> satislar.satilanBalik.balikIsmi >> satislar.satilanBalik.fiyat >> satislar.adet >> satislar.toplam;
		cout << setw(10) << satislar.satilanBalik.balikIsmi << setw(10) << satislar.satilanBalik.fiyat << setw(10) << satislar.adet << setw(15) << satislar.toplam << endl;
		toplam+=satislar.toplam;
	}
	cout << endl;
	cout << "Günlük Kazanç: " << toplam << endl;
}
void balikSatis()
{
	balikBilgileri balik;
	satisBilgileri satislar;
	cout << "><(((º>   ELÝMÝZDE OLAN BALIKLAR   <º)))><" << endl;
	cout << setw(10) << "BALIK" << setw(10) << "STOK" << setw(10) << "FIYAT" << endl;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("balik.txt");
	ofstream satis("satis.txt",ios::app);
	char secim;
	do
	{
	while(!(okuma.eof()))
	{
		okuma >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		cout << setw(10) << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat << endl;
	}
	ifstream okuma2("balik.txt");
	cout << "Hangi balýðý satmak istiyorsunuz?" << endl;
	string isim;
	cin >> isim;
	int sayi;
	float odenecekUcret;
		while(!(okuma2.eof()))
	{
		okuma2 >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(isim==balik.balikIsmi)
		{
			cout << "Kaç tane satmak istiyorsunuz?" << endl;
			cin >> sayi;
			if(sayi<=balik.stok)
			{
			balik.stok-=sayi;
			
			yedek << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 
			odenecekUcret=sayi*balik.fiyat;
			satislar.satilanBalik.balikIsmi=balik.balikIsmi;
			satislar.satilanBalik.fiyat=balik.fiyat;
			satislar.adet=sayi;
			satislar.toplam=satislar.adet*satislar.satilanBalik.fiyat;
			cout << "Ödemeniz Gereken Ücret: " << odenecekUcret << endl;
			satis << endl<<satislar.satilanBalik.balikIsmi << setw(10) << satislar.satilanBalik.fiyat << setw(10) << satislar.adet << setw(10) << satislar.toplam;
			}
			else
			{
				cout << "Elimizde " << balik.stok << " kg " << balik.balikIsmi << " balýðý bulunmaktadýr." << endl;
			}
		}
		else
		{
			yedek << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 		
		}
	}

	okuma2.close();
	okuma.close();
	yedek.close();
	
	cout << "Baþka balýk satýþý yapmak ister misiniz? (E/H)" << endl;	
	cin >> secim;
	}
	while(secim=='e' || secim=='E');
	
	
	remove("balik.txt");
	rename("yedek.txt", "balik.txt");
}

int main()
{
	setlocale(LC_ALL,"Turkish");
	char secim=' ';
	
	do{
	
	system("cls");       
	
	cout << " ><(((º> *BALIKCI OTOMASYONU* <º)))>< " << endl;
	cout << " /*            Ana Menü           *\\ " << endl;
	cout << " \\*        1.Balýk Ekleme         */ " << endl;               
	cout << " /*       2.Balýk Güncelleme      *\\ " << endl;
	cout << " \\*      3.Stok Görüntüleme       */ " << endl;
	cout << " /*         4.Balýk Satýþý        *\\ " << endl;
	cout << " \\*         5.Balýk Arama         */ " << endl;
 	cout << " /*        6.Satýþ Listeleme      *\\ " << endl;
 	cout << " \\*         7.Balýk Silme         */ " << endl;
 	cout << " /*             8.Çýkýþ           *\\ " << endl;


	cout << "\nLütfen yapmak istediðiniz iþlemi girin: " ;
	secim=getche();
	cout<<endl;
	switch(secim)
	{
		case '1':
		{
			balikEkle();	
			break;
		}	
		
		case '2':
		{
			balikGuncelleme();
			break;
		}
		
		case '3':
		{
			balikListeleme();
			break;
		}
		
		case '4':
		{
			balikSatis();
			break;
		}
		
		case '5':
		{
			balikListeleme();
			balikArama();
			break;
		}
		
		case '6':
		{
		 	satisListeleme();
			break;
		}
		
		case '7':
		{
			balikSilme();
			break;
		}
		
		case '8':
		{
			break;
		}
		
		default:
		cout << "Hatalý Seçim Yaptýnýz! 1-8" << endl;
	}
	if(secim!='8')
	{
	cout << "Ana menuye donmek ister misin?(E/H)" << endl;
	secim=getche();
	}
	
	} 
	while(secim=='e' || secim=='E');
	cout << "Programdan Çýktýnýz!" << endl;
	
	system("pause");
	return 0;
}
