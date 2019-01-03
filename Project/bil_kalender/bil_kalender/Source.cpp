#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


char *hari[] ={ "Jum'at", "Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis" };
char *pasar[] ={ "Kliwon", "Legi", "Paing", "Pon", "Wage" };// wage kliwon legi paing pon
int jumlah_hari_bulan[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; //jumlah ini dalam tahun yang bukan kabisat
int isi_kalender[50]= { };
char *isi_pasar[50] = {};

int jmlhari(int d, int m, int y) {
	int ht = y * 365; // mencarijumlah hari dalam 0 sampai tahu yang diinputkan
	//printf("%d\n", ht);
	
	int hs = jumlah_hari_bulan[m - 1] + d;//jumlah hari dari tanggal yang di inputkan dari tahun itu

	int kab = 0;// untuk menghitung jumlah tahun kabisat saat tahun di bagi
	
	// jika kabisat maka saat di bulan februari akan menjadi 29
	if (y % 100 == 0)
	{
		if (y % 400 == 0)
		{
			if (m > 2) {//jika bulan di atas februari
				hs++;
				//printf("tahun %d kabisat\n", y);
			}
		}
	}
	else if (y%4==0)
	{
		if (m > 2) {//jika bulan di atas februari
			hs++;
			//printf("tahun %d kabisat\n", y);
		}
	}

	//di sini tahun akan di looping untuk mencari berapa jumlah tahun kabisat dar 1800 sampai tahun yang telah di inputkan
	for (int i = 0; i < y; i++) {
		if (i % 100 == 0)
		{
			if (i % 400 == 0)
			{
				kab++;
			}
		}
		else if (i % 4 == 0)
		{
			kab++;
		}
	}
	int total = ht + hs + kab;
	//printf("%d %d %d\n",ht,hs,kab);
	return (total);
}

void nama_bulan(int bulan){
	printf("\t\t\t");
	switch (bulan)
	{
	case 1:
		printf("Januari");
		break;
	case 2:
		printf("Februari");
		break;
	case 3:
		printf("Maret");
		break;
	case 4:
		printf("April");
		break;
	case 5:
		printf("Mei");
		break;
	case 6:
		printf("Juni");
		break;
	case 7:
		printf("Juli");
		break;
	case 8:
		printf("Agustus");
		break;
	case 9:
		printf("September");
		break;
	case 10:
		printf("Oktober");
		break;
	case 11:
		printf("November");
		break;
	case 12:
		printf("Desember");
		break;
	default:
		printf("Bulan Tidak Valid");
		break;
	}
	
}

int hari_bulan_itu(int m, int y){
	int jml_bulan[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int hari = jml_bulan[m - 1];
	if (y % 100 == 0)
	{
		if (y % 400 == 0)
		{
			if (m == 2) {//jika bulan di atas februari
				hari++;
				//printf("tahun %d kabisat\n", y);
			}
		}
	}
	else if (y % 4 == 0)
	{
		if (m == 2) {//jika bulan di atas februari
			hari++;
			//printf("tahun %d kabisat\n", y);
		}
	}
	return hari;
}

void zodiak(int t, int b){

	if ((t >= 21 && t <= 31 && b == 12) || (t >= 1 && t <= 20 && b == 1)){
		printf("Capricorn");
	}
	else if ((t >= 21 && t <= 31 && b == 1) || (t >= 1 && t <= 20 && b == 2)){
		printf("Aquarius");
	}
	else if ((t >= 21 && t <= 28 && b == 2) || (t >= 1 && t <= 20 && b == 3)){
		printf("Pisces");
	}
	else if ((t >= 21 && t <= 31 && b == 3) || (t >= 1 && t <= 20 && b == 4)){
		printf("Aries");
	}
	else if ((t >= 21 && t <= 30 && b == 4) || (t >= 1 && t <= 20 && b == 5)){
		printf("Taurus");
	}
	else if ((t >= 21 && t <= 31 && b == 5) || (t >= 1 && t <= 20 && b == 6)){
		printf("Gemini");
	}
	else if ((t >= 21 && t <= 30 && b == 6) || (t >= 1 && t <= 20 && b == 7)){
		printf("Cancer");
	}
	else if ((t >= 21 && t <= 31 && b == 7) || (t >= 1 && t <= 20 && b == 8)){
		printf("Leo");
	}
	else if ((t >= 21 && t <= 31 && b == 8) || (t >= 1 && t <= 20 && b == 9)){
		printf("Virgo");
	}
	else if ((t >= 21 && t <= 30 && b == 9) || (t >= 1 && t <= 20 && b == 10)){
		printf("Libra");
	}
	else if ((t >= 21 && t <= 31 && b == 10) || (t >= 1 && t <= 20 && b == 11)){
		printf("Scorpio");
	}
	else if ((t >= 21 && t <= 30 && b == 11) || (t >= 1 && t <= 20 && b == 12)){
		printf("Sagitarius");
	}

}

int main() {
	int tg, bl, th, idxhari, idxpasar,tanggal_satu;
	char *hari_lahir, *pasar_lahir,verif='y';
	
	
	
		//inputan
		printf("Masukkan Tanggal [dd mm yyyy] : ");
		scanf_s("%d%d%d", &tg, &bl, &th);

		//mencari hari dan pasar
		idxhari = jmlhari(tg, bl, th) % 7;
		idxpasar = jmlhari(tg, bl, th) % 5;
		hari_lahir = hari[idxhari];
		pasar_lahir = pasar[idxpasar];

		//menampilkan hari dan pasaran data yang telah di inputkan
		//printf("%s %s\n",hari_lahir	 , pasar_lahir);

		//menampilkan header kalender
		printf("-----------------------------------------------------------------\n");
		nama_bulan(bl);
		printf(" %d\n", th);
		printf("-----------------------------------------------------------------\n");
		printf("       Minggu   Senin  Selasa   Rabu    Kamis  Jum'at  Sabtu  \n");
		printf("-----------------------------------------------------------------\n\n\n");

		//mencari banyak hari bulan itu
		int jumlah_hari_bulan_itu = hari_bulan_itu(bl, th);
		//printf("%d",jumlah_hari_bulan_itu);

		//mencari hari tanggal 1 nya
		tanggal_satu = (jmlhari(1, bl, th) % 7);// dari array senin di ubah ke tatanan senin yang di tampilkan sehingga harus di -2 supaya menjadi senin dan saat negatif akan di tambah 7
		switch (tanggal_satu)
		{
		case 0:
			tanggal_satu = 5;
			break;
		case 1:
			tanggal_satu = 6;
			break;
		case 2:
			tanggal_satu = 0;
			break;
		case 3:
			tanggal_satu = 1;
			break;
		case 4:
			tanggal_satu = 2;
			break;
		case 5:
			tanggal_satu = 3;
			break;
		case 6:
			tanggal_satu = 4;
			break;
		default:
			break;
		}
		
		//printf("%d", tanggal_satu);

		//mencari pasar tanggal 1 nya
		int pasar_satu = (jmlhari(1, bl, th) % 5);

		//deklarasi tanggal satu hari apa
		isi_kalender[tanggal_satu] = 1;

		//deklarasi tanggal satu pasar apa
		isi_pasar[tanggal_satu] = pasar[pasar_satu];

		//menginputkan tanggal dan weton ke dalam array
		int j = 2, k = pasar_satu + 1;
		for (int i = tanggal_satu + 1; i <= tanggal_satu + jumlah_hari_bulan_itu - 1; i++)
		{
			isi_kalender[i] = j;
			if (k == 5)
			{
				k = 0;
			}
			isi_pasar[i] = pasar[k];
			j++;
			k++;
		}




		//menampilkan isinya
		for (int i = 0; i < 43; i++)
		{
			//menampilkan tanggalnya
			if (i>0 && i % 7 == 0)
			{
				printf("\n");//menampilkan pasarannya
				for (int j = i - 7; j < i; j++)
				{
					if (isi_pasar[j] == NULL)
					{
						printf("\t  ");
					}
					else
					{
						printf("\t%s", isi_pasar[j]);
					}
				}
				printf("\n\n");
			}

			if (isi_kalender[i] == 0)
			{
				printf("\t  ");
			}
			else if (isi_kalender[i] > 0 && isi_kalender[i] <10)
			{
				printf("\t0%d", isi_kalender[i]);
			}
			else
			{
				printf("\t%d", isi_kalender[i]);
			}

		}
		printf("\n-----------------------------------------------------------------\n");
		//menampilkan hari dan pasaran data yang telah di inputkan
		printf("Weton  : %s %s\n", hari_lahir, pasar_lahir);
		printf("Zodiak : "); zodiak(tg, bl);
		printf("\n-----------------------------------------------------------------\n");

		
	

	system("pause");
	return 0;
}
