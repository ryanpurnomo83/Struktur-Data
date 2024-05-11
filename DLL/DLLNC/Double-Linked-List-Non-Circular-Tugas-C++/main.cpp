#include <iostream>

using namespace std;

int input,indeks,umur;
string name_mhs,nim_mhs;

struct Mahasiswa {
    string nama;
    string nim;
    int umur;
    Mahasiswa *prev;
    Mahasiswa *next;
};
Mahasiswa *mhsBaru,*head,*cur, *tail;

bool isEmpty(){
    if(head == NULL){
        return 1;
    }else{
        return 0;}
}

void cetak(){
    cur=head;
    while (cur!=NULL){
            if(cur!=NULL){
      cout << endl;
      cout << "NIM  : " << cur->nim<<endl;
      cout << "Nama : " <<cur->nama<<endl;
      cout << "Umur : " << cur->umur<< endl;
        cur = cur->next;
        cout << endl;
            }else{
      cout << "Data kosong";
            }
    }
}

void buatLinkedList(string nim,string nama,int umur){
    mhsBaru=new Mahasiswa();
    mhsBaru->nim=nim;
    mhsBaru->nama=nama;
    mhsBaru->umur=umur;
    mhsBaru->prev=NULL;
    mhsBaru->next=NULL;
    head=mhsBaru;
}

void tambahDepan(string nim,string nama,int umur){
    mhsBaru=new Mahasiswa();
    mhsBaru->nim=nim;
    mhsBaru->nama=nama;
    mhsBaru->umur=umur;
    mhsBaru->prev=NULL;
    mhsBaru->next=head;
    if(isEmpty() == 1){
        head=mhsBaru;
        head->prev=NULL;
        head->next=NULL;
    }else{
        mhsBaru->next=head;
        head->prev=mhsBaru;
        head=mhsBaru;
    }
}

void tambahBelakang(string nim,string nama,int umur){
    Mahasiswa *bantu;
    mhsBaru=new Mahasiswa();
    mhsBaru->nim=nim;
    mhsBaru->nama=nama;
    mhsBaru->umur=umur;
    mhsBaru->prev=NULL;
    mhsBaru->next=NULL;
    if(isEmpty()==1){
        head=mhsBaru;
        head->prev=NULL;
        head->next=NULL;
    }else{
        bantu=head;
        while(bantu->next!=NULL){
            bantu-bantu->next;
        }
        bantu->next=mhsBaru;
        mhsBaru->prev=bantu;
    }
}

void hapusDepan(){
    Mahasiswa *hapus;
    string d;
    string e;
    int f;
    if(isEmpty() == 0){
            hapus = head;
            d = hapus->nim;
            e = hapus->nama;
            f = hapus->umur;
            head=hapus->next;
            head->prev=NULL;
            hapus->next=NULL;
            delete hapus;
        cout << "data pada alamat " << hapus << " terhapus\n\n";
        }
    else cout << "data masih kosong";
}

void hapusBelakang(){
    Mahasiswa *bantu,*hapus;
    string d;
    string e;
    int f;
    if(isEmpty()==0){
        if(head->next != NULL){
            bantu = head;
            while(bantu->next->next != NULL){
                bantu = bantu->next;
            }
            hapus = bantu;
            bantu = bantu->prev;
            bantu->next = NULL;
            delete hapus;
        }else{
            d = head->nim;
            e = head->nama;
            f = head->umur;
            head = NULL;
        }
        cout << "data pada alamat " << bantu << " terhapus\n\n";
    } else cout << "Masih kosong\n";
}

void tambahSetelah(int x, string nim,string nama,int umur){
    Mahasiswa *after;
    if(x == 1){
        cout << "Bukan posisi tengah";
    }else{
    mhsBaru=new Mahasiswa();
    mhsBaru->nim=nim;
    mhsBaru->nama=nama;
    mhsBaru->umur=umur;

    cur = head;
    int i = 1;
    while(i<x-1){
        cur = cur->next;
        i++;
    }
    after = cur->next;
    mhsBaru->prev=after;
    mhsBaru->next=NULL;
    cur->next = after;
    after->next = mhsBaru;
    }
}

void tambahSebelum(int x, string nim,string nama,int umur){
    Mahasiswa *before;
    if(x == 1){
        cout << "Bukan posisi tengah";
    }else{
    mhsBaru=new Mahasiswa();
    mhsBaru->nim=nim;
    mhsBaru->nama=nama;
    mhsBaru->umur=umur;

    cur = head;
    int i = 1;
    while(i<x-1){
        cur = cur->next;
        i++;
    }
    before = cur->next;
    mhsBaru->prev=cur;
    mhsBaru->next=before;
    cur->next=mhsBaru;
    before->prev = mhsBaru;}
}

void hapustambahSS(int x){
    Mahasiswa *pass, *del;
    int i = 1;
    cur = head;
    while(i <= x){
            if(i == x-1){
        pass = cur;
    }if(i == x){
    del = cur;
    }
    cur = cur->next;
    i++;
    }
    pass->next = cur;
    delete del;
}

void hapusSemua(){
    Mahasiswa *bantu, *hapus;
    bantu = head;
    while(bantu!=NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
}


int main()
{
    int a = 0;
    int data;
    while (input!=11){

    cout << "DLLNC MAHASISWA\n";
    cout << "1.Input depan\n";
    cout << "2.Input belakang\n";
    cout << "3.Cetak\n";
    cout << "4.Jumlah data\n";
    cout << "5.Hapus depan\n";
    cout << "6.Hapus belakang\n";
    cout << "7.Tambah Setelah\n";
    cout << "8.Tambah Sebelum\n";
    cout << "9.Hapus tengah\n";
    cout << "10.Clear\n";
    cout << "11.Quit\n";
    cout << "Pilih Menu :";
    cin >> input;

        switch(input){
        case 1:
            indeks++;
            cout << "Masukan NIM  : ";
            cin >>nim_mhs;
            cout << "Masukan Nama : ";
            cin >> name_mhs;
            cout << "Masukan Umur : ";
            cin >> umur;cout << endl;
            if(indeks==1)
            {
                buatLinkedList(nim_mhs,name_mhs,umur);
            }else {
                tambahDepan(nim_mhs,name_mhs,umur);
            }
            a++;
        if(a == 0){
        case 2:
            indeks++;
            cout << "Masukan NIM  : ";
            cin >>nim_mhs;
            cout << "Masukan Nama : ";
            cin >> name_mhs;
            cout << "Masukan Umur : ";
            cin >> umur;cout<<endl;
            if(indeks==1)
            {
                buatLinkedList(nim_mhs,name_mhs,umur);
            }else {
                tambahBelakang(nim_mhs,name_mhs,umur);
            }
            a++;
        }
        if(a == 0){
        case 3:
            cetak();cout << endl;
        }
        if(a == 0){
        case 4:
            cout << endl;
            cout << "Terdapat : "<< indeks << " Data\n";
            cout << endl;
            }
        if(a == 0){
        case 5:
            hapusDepan();
            }
        if(a == 0){
        case 6:
            hapusBelakang();
            }
        if(a == 0){
        case 7:
            cout << "Masukkan nilai untuk memilih posisi node pada data ";
            cin >> data;
            indeks++;
            cout << "Masukan NIM  : ";
            cin >>nim_mhs;
            cout << "Masukan Nama : ";
            cin >> name_mhs;
            cout << "Masukan Umur : ";
            cin >> umur;cout<<endl;
                if(indeks==1)
                {
                buatLinkedList(nim_mhs,name_mhs,umur);}
                else {
                tambahSetelah(data, nim_mhs,name_mhs,umur);
                }
            }
         if(a == 0){
         case 8:
            cout << "Masukkan nilai untuk memilih posisi node pada data ";
            cin >> data;
            indeks++;
            cout << "Masukan NIM  : ";
            cin >>nim_mhs;
            cout << "Masukan Nama : ";
            cin >> name_mhs;
            cout << "Masukan Umur : ";
            cin >> umur;cout<<endl;
                if(indeks==1)
                {
                buatLinkedList(nim_mhs,name_mhs,umur);}
                else {
                tambahSebelum(data, nim_mhs,name_mhs,umur);
                }
            }
          if(a == 0){
            case 9:
            int data1;
            cout << "Masukkan posisi data tambah yang ingin dihapus ";
            cin >> data;
            hapustambahSS(data);
            cout << "\n";
         }
         if(a == 0){
         case 10:
            hapusSemua();
            cout << "\n";
            }
        }
    }
    return 0;
}
