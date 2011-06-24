//============================================================================
// Name        : sortnsearch.cpp
// Author      : Ankgi Sukarmana (soekarmana@gmail.com)
// Version     : 0.0.1
// License     : GPL
// Description : Program Sorting & Searching
// Git Repo    : https://github.com/soekarmana/sortnsearch
//============================================================================

#include <iostream>

#ifdef linux
	#include "linuxconio.h"
#else
	#include <conio.h>
#endif

using namespace std;

int jum_elm=0;
int angka[sizeof(jum_elm)];

int pil_menu = 0;
bool selesai = false;
	
void show_menu()
{
	cout<<"<<<< Program Sorting & Searching >>>>\n\n";
	cout<<"      1. Bubble Sort\n";
	cout<<"      2. Insertion Sort\n";
	cout<<"      3. Selection Sort\n";
	cout<<"      4. Sequential Search\n";
	cout<<"      5. Binary Search\n";
	cout<<"      6. Keluar\n\n";
}

int* get_user_input()
{	
	cout<<"Masukan jumlah elemen array : "; cin>>jum_elm;
	cout<<"\n";
	for(int i = 0; i < jum_elm; i++){
			cout<<"Masukan nilai elemen array ke "<<i<<" : ";
			cin>>angka[i];
		}
	return angka;
}

void tampil_array(int arr[])
{
	for(int i=0; i<jum_elm; i++){
		cout<<arr[i]<<" ";
	}
}

void bubble_sort()
{
	int *angka = get_user_input();
	int counter = 0;

	cout<<"\n";
	for(int i=0; i<jum_elm; i++){
			for (int j=jum_elm-1; j>i; j--){
				if(angka[j] < angka[j-1]){
						int temp = angka[j-1];
						angka[j-1] = angka[j];
						angka[j] = temp;
						cout<<"Langkah ke : "<<counter+1<<" => ";
						counter++;
						tampil_array(angka);
						cout<<"\n";
				}
		}
	}
		cout<<"\nHasil Akhir : "; tampil_array(angka);

		cout<<"\n\nProses selesai dalam "<<counter<<" langkah";

}

void insertion_sort()
{
	int *angka = get_user_input();
	int counter=0, itemp;

	cout<<"\n";
	for(int i = 1; i < jum_elm; i++){
		itemp = angka[i];
		int j = i;

		while(j > 0 && angka[j-1] > itemp){
			angka[j] = angka[j-1];
			j--;
		}
		cout<<"Langkah ke : "<<counter+1<<" => ";
		counter++;
		tampil_array(angka);
		cout<<" dan Temp = "<<itemp;
		cout<<"\n";
		angka[j] = itemp;
	}

	cout<<"\nHasil Akhir : "; tampil_array(angka);
	cout<<"\n\nProses selesai dalam "<<counter<<" langkah";
}

void selection_sort()
{
	int *angka = get_user_input();
	cout<<"\n";
	int min,tmp,counter=0;
	for(int i=0; i<jum_elm - 1; i++){
		min = i;
		for(int j = i + 1; j<jum_elm; j++){
			if(angka[j] < angka[min]){
				min=j;
			}
		if(min != i){
			tmp = angka[i];
			angka[i] = angka[min];
			angka[min] = tmp;

			cout<<"Langkah ke : "<<counter+1;
			cout<<" => ";
			counter++;
			tampil_array(angka);
			cout<<"\n";
			}
		}
	}
	cout<<"\nHasil Akhir : "; tampil_array(angka);
	cout<<"\n\nProses selesai dalam "<<counter<<" langkah";
}

void sequential_search()
{
	int *angka = get_user_input();
	int cari;

	cout<<"\nMasukan angka yg dicari : ";
	cin>>cari;

	for(int i = 0; i < jum_elm; i++){
			if(cari == angka[i]){
				cout<<"Data "<<angka[i]<<" ditemukan pada index "<<i<<" !\n";
			}
	}
}

void binary_search()
{
	bool ketemu = false;
	int *angka = get_user_input();
	int awal=0, akhir=jum_elm-1, cari;

	for(int i=0; i<jum_elm; i++){
			for (int j=jum_elm-1; j>i; j--){
				if(angka[j] < angka[j-1]){
						int temp = angka[j-1];
						angka[j-1] = angka[j];
						angka[j] = temp;;
				}
		}
	}

	cout<<"\nMasukan angka yg dicari : ";
	cin>>cari;

		while(awal <= akhir){
			int tengah = (awal+akhir)/2;
			if(cari == angka[tengah] ){
				cout<<"\nData "<<angka[tengah]<<" ditemukan pada index "<<tengah<<" !\n";
				ketemu = true;
				break;
			}else if(cari < angka[tengah] ){
				akhir = tengah - 1;
			}else{
				awal = tengah + 1;
			}
			
		}
		if(ketemu == false){
			cout<<"\n\nData tidak ditemukan !\n\n";
		}
}


int main()
{
awal:
	do{
		show_menu();
		cout<<"Masukan pilihan anda : ";
		cin>>pil_menu;

		switch (pil_menu)
		{
			case 1:
				bubble_sort();
				getch();
				clrscr();
				break;

			case 2:
				insertion_sort();
				getch();
				clrscr();
				break;

			case 3:
				selection_sort();
				getch();
				clrscr();
				break;

			case 4:
				sequential_search();
				getch();
				clrscr();
				break;

			case 5:
				binary_search();
				getch();
				clrscr();
				break;

			case 6:
				cout<<"Goodbye ! ";
				getch();
				break;
				
			default:
				cout<<"\n\nPilihan Tidak Tersedia !\n\n";
				getch();
				clrscr();
				goto awal;
		}
	}while (pil_menu <= 6 && pil_menu != 6);
	return 0;
}
