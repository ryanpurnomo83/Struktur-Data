#include <iostream>

using namespace std;

struct Mahasiswa{
    string NIM;
    string Nama;
    string Jurusan;
    int Umur;

    Mahasiswa *nexdt;
};

Mahasiswa *head, *tail, *cur, *baru;

void BuatSLLC(string NIM, string Nama, String Jurusan, int Umur){
    head = new Mahasiswa();
    head->NIM = NIM;
    head->Nama=Nama;
    head->Jurusan=Jurusan;
    head->Umur=Umur;
    tail=head;
    tail->next=head;
}

void Cetak(){
    cur = head;
    while(cur->next!=head){
        cout << "NIM : " << cur->Nim << "\n";
        cout << "Nama : " << cur->Nama << "\n";
        cout << "Jurusan : " << cur->Jurusan << "\n";
        cout << "Umur : " << cur->Umur << "\n";
        cur = cur->next;
    }
}

void tambahDepan(string NIM, string Nama, String Jurusan, int Umur){
    baru = new Mahasiswa();
    baru->NIM=NIM;
    baru->Nama=Nama;
    baru->Jurusan=Jurusan;
    baru->Umur=Umur;
    baru->next=head;
    tail->next=baru;
    head=baru;
}

void tambahBelakang(string NIM, string Nama, String Jurusan, int Umur){
    baru = new Mahasiswa();
    baru->NIM=NIM;
    baru->Nama=Nama;
    baru->Jurusan=Jurusan;
    baru->Umur=Umur;
    baru->next=head;
    tail->next=baru;
    tail=baru;
}


int main()
{

    return 0;
}
