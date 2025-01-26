#include <iostream>
#include <string>
using namespace std;

// struktur untuk menyimpan data kontak
struct Contact {
    string nama;
    string tempat_tinggal;
    string alamat;
    string kekuatan;

    void addContact() {
        cout << "Nama: ";
        cin.ignore(); // bersihkan buffer sebelum input string
        getline(cin, nama);
        cout << "Tempat tinggal: ";
        getline(cin, tempat_tinggal);
        cout << "Alamat: ";
        getline(cin, alamat);
        cout << "Kekuatan: ";
        getline(cin, kekuatan);
    }

    void displayContact() const {
        cout << "Nama: " << nama << endl;
        cout << "Tempat tinggal: " << tempat_tinggal << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Kekuatan: " << kekuatan << endl;
        cout << "--------------------------" << endl;
    }
};

void searchContacts(const Contact contacts[], size_t count) {
    if (count == 0) {
        cout << "Belum ada kontak yang tersimpan!" << endl;
        return;
    }

    string searchName;
    cout << "Masukkan nama yang ingin dicari: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (size_t i = 0; i < count; i++) {
        if (contacts[i].nama == searchName) {
            cout << "\nKontak ditemukan:\n";
            contacts[i].displayContact();
            found = true;
            break; // hentikan pencarian setelah ditemukan
        }
    }

    if (!found) {
        cout << "Kontak dengan nama '" << searchName << "' tidak ditemukan." << endl;
    }
}

int main() {
    const size_t maxContacts = 8; // jumlah kontak maksimum
    Contact phoneBook[maxContacts]; // array statis untuk menyimpan kontak
    size_t contactCount = 0;        // jumlah kontak saat ini
    size_t nextIndex = 0;           // indeks untuk kontak berikutnya

    bool quit = false;

    do {
        int option;
        cout << "\nMENU" << endl;
        cout << "1 Add contacts" << endl;
        cout << "2 Search contacts" << endl;
        cout << "3 Quit" << endl;
        cout << "Enter: ";
        cin >> option;

        switch (option) {
            case 1: {
                // tambahkan kontak baru ke array
                phoneBook[nextIndex].addContact();
                
                // update indeks berikutnya (melingkar)
                nextIndex = (nextIndex + 1) % maxContacts;

                // update jumlah kontak (hanya jika belum penuh)
                if (contactCount < maxContacts) {
                    contactCount++;
                }

                cout << "\nKontak berhasil ditambahkan!" << endl;
                break;
            }
            case 2:
                searchContacts(phoneBook, contactCount); // cari kontak
                break;
            case 3:
                quit = true;
                break;
            default:
                cout << "Perintah tidak valid. Coba lagi." << endl;
                break;
        }
    } while (!quit);

    cout << "\nTerima kasih telah menggunakan program ini!" << endl;
    return 0;
}
