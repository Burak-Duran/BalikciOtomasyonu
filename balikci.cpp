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
		
	cout << "Bal�k ismi giriniz: " ;
	cin >> balik.balikIsmi ; 
	
	cout << "L�tfen " << balik.balikIsmi << " bal���n�n sto�unu giriniz: " ;
	cin >> balik.stok ;
	
	cout << "L�tfen " << balik.balikIsmi << " bal���n�n fiyat�n� giriniz: " ;
	cin >> balik.fiyat ; 

	bilgiler << endl << balik.balikIsmi << setw(10) << balik.stok << setw(10) << balik.fiyat ; 
	
	cout << "Ba�ka bal�k girisi yapmak ister misiniz? (E/H): ";	
	secim=getche();	
	cout << endl;
	sayi++;
		
	}
	while(secim=='e' || secim=='E');
	cout << sayi << " Adet bal�k girisi yap�ld�." << endl;
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
	cout << "Hangi bal��� g�rmek istiyorsunuz?: " ;
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
		cout << "B�yle bir bal�k yoktur" << endl;
	}
}

void balikSilme()
{
	balikBilgileri balik;
	cout << "><(((�>   EL�M�ZDE OLAN BALIKLAR   <�)))><" << endl;
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
	cout << "Sto�u Olmad��� i�in Silinen Bal�klar " << endl;
	
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
	
	cout << sayac << " Adet Bal�k Silindi" << endl;
}
	else
	{
		cout << "Bal�k silinmedi" << endl;
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
	cout << "><(((�>   EL�M�ZDE OLAN BALIKLAR   <�)))><" << endl;
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
	cout << "Hangi Bal��� G�ncellemek �stiyorsunuz?" << endl;
	string isim;
	cin >> isim;
		while(!(okuma2.eof()))
	{
		okuma2 >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(isim==balik.balikIsmi)
		{
			cout << "Bal�k �smi Giriniz: " ;
			cin >> balik.balikIsmi ; 
	 
			cout << "L�tfen " << balik.balikIsmi << " Bal���n�n Sto�unu Giriniz: " ;
			cin >> balik.stok ;
	
			cout << "L�tfen " << balik.balikIsmi << " Bal���n�n Fiyat�n� Giriniz: " ;
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
	
	cout << "Ba�ka Bal�k Sat��� Yapmak �ster misiniz? (E/H)" << endl;	
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
	cout << setw(10) << "Bal�k" << setw(10) << "Fiyat" << setw(10) << "Adet" << setw(15) << "Toplam fiyat" << endl;	
	while(!(okuma.eof()))
	{
		okuma >> satislar.satilanBalik.balikIsmi >> satislar.satilanBalik.fiyat >> satislar.adet >> satislar.toplam;
		cout << setw(10) << satislar.satilanBalik.balikIsmi << setw(10) << satislar.satilanBalik.fiyat << setw(10) << satislar.adet << setw(15) << satislar.toplam << endl;
		toplam+=satislar.toplam;
	}
	cout << endl;
	cout << "G�nl�k Kazan�: " << toplam << endl;
}
void balikSatis()
{
	balikBilgileri balik;
	satisBilgileri satislar;
	cout << "><(((�>   EL�M�ZDE OLAN BALIKLAR   <�)))><" << endl;
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
	cout << "Hangi bal��� satmak istiyorsunuz?" << endl;
	string isim;
	cin >> isim;
	int sayi;
	float odenecekUcret;
		while(!(okuma2.eof()))
	{
		okuma2 >> balik.balikIsmi >> balik.stok >> balik.fiyat;
		if(isim==balik.balikIsmi)
		{
			cout << "Ka� tane satmak istiyorsunuz?" << endl;
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
			cout << "�demeniz Gereken �cret: " << odenecekUcret << endl;
			satis << endl<<satislar.satilanBalik.balikIsmi << setw(10) << satislar.satilanBalik.fiyat << setw(10) << satislar.adet << setw(10) << satislar.toplam;
			}
			else
			{
				cout << "Elimizde " << balik.stok << " kg " << balik.balikIsmi << " bal��� bulunmaktad�r." << endl;
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
	
	cout << "Ba�ka bal�k sat��� yapmak ister misiniz? (E/H)" << endl;	
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
	
	cout << " ><(((�> *BALIKCI OTOMASYONU* <�)))>< " << endl;
	cout << " /*            Ana Men�           *\\ " << endl;
	cout << " \\*        1.Bal�k Ekleme         */ " << endl;               
	cout << " /*       2.Bal�k G�ncelleme      *\\ " << endl;
	cout << " \\*      3.Stok G�r�nt�leme       */ " << endl;
	cout << " /*         4.Bal�k Sat���        *\\ " << endl;
	cout << " \\*         5.Bal�k Arama         */ " << endl;
 	cout << " /*        6.Sat�� Listeleme      *\\ " << endl;
 	cout << " \\*         7.Bal�k Silme         */ " << endl;
 	cout << " /*             8.��k��           *\\ " << endl;


	cout << "\nL�tfen yapmak istedi�iniz i�lemi girin: " ;
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
		cout << "Hatal� Se�im Yapt�n�z! 1-8" << endl;
	}
	if(secim!='8')
	{
	cout << "Ana menuye donmek ister misin?(E/H)" << endl;
	secim=getche();
	}
	
	} 
	while(secim=='e' || secim=='E');
	cout << "Programdan ��kt�n�z!" << endl;
	
	system("pause");
	return 0;
}
