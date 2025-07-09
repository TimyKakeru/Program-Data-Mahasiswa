#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string NIM;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* awal = NULL;
Mahasiswa* akhir = NULL;
Mahasiswa* baru;
Mahasiswa* bantu;

void tambahData(string nama,string NIM, float nilai) {
    baru = new Mahasiswa;
    baru->nama = nama;
    baru->NIM = NIM;
    baru->nilai = nilai;
    baru->next = NULL;
    baru->prev = NULL;
    if (awal == NULL) {
        awal = baru;
        akhir = baru;
    } else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
}

void tampilkanDataSiswa() {
    cout << "====================" << endl;
    bantu = awal;
    while (bantu != NULL) {
        cout << "Nama: " << bantu->nama << endl;
        cout << "NIM " << bantu->NIM << endl;
        cout << "IPK: " << bantu->nilai << endl;
		bantu = bantu->next;
        cout << "=====================" << endl;
    }
}
void bubbleSort(int permintaan) {
    if (awal == NULL) return;
    bool swapped;
    Mahasiswa* ptr1;
    Mahasiswa* lptr = NULL;
    
    do {
        swapped = false;
        ptr1 = awal;
        
        while (ptr1->next != lptr) {
            if ( permintaan == 1 && ptr1->nilai < ptr1->next->nilai) {
				swap(ptr1->nama, ptr1->next->nama);
				swap (ptr1->NIM,ptr1->next->NIM);
				swap(ptr1->nilai, ptr1->next->nilai);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
Mahasiswa* searching(string NIM){
	Mahasiswa* temp = head;
	while (temp){
		if (temp->NIM==NIM){
			return temp;
	}
	temp=temp->next;
	}
	return nullptr;
	
	
}
int main() {
    string nama;
    string NIM;
    float nilai;
    int pilihan;

    do {
        cout << "\tPROGRAM DATA MAHASISWA\n";
        cout << "1. Tambah Data MAHASISWA\n";
        cout << "2. Tampilkan Data MAHASISWA\n";
        cout << "3. Urutkan Data MAHASISWA (Descending)\n";
        cout << "4. Searching\n";
        cout << "5. Keluar\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukan NIM Mahasiswa:";
                cin>> NIM;
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                tambahData(nama,NIM,nilai);
                break;
            case 2:
                cout << "Daftar Data Siswa:\n";
                tampilkanDataSiswa();
                break;
            case 3:
                bubbleSort(1);
                cout << "Data diurutkan secara descending.\n";
                tampilkanDataSiswa();
                break;
            case 4:
            	cout << "Data Mahasiswa berdasarkan NIM :";
            	cin >> NIM;
            	break;
            case 5:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}

