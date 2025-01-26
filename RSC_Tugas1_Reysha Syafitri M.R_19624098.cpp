#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact { 
    public:
        string nama;
        string tempat_tinggal;
        string alamat;
        string kekuatan;
        
        void addContact() {
            cout << "Nama: ";
            cin.ignore(); 
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

void searchContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "Belum ada kontak yang tersimpan!" << endl;
        return;
    }

    string searchName;
    cout << "Masukkan nama yang ingin dicari: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.nama == searchName) {
            cout << "\nKontak ditemukan:\n";
            contact.displayContact();
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Kontak dengan nama '" << searchName << "' tidak ditemukan." << endl;
    }
}

int main() {
    vector<Contact> phoneBook; 
    const size_t maxContacts = 8;
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
                Contact newContact;
                newContact.addContact(); 
                
                if (phoneBook.size() >= maxContacts) {
                    phoneBook.erase(phoneBook.begin()); 
                }
                
                phoneBook.push_back(newContact);
                cout << "\nKontak berhasil ditambahkan!" << endl;
                break;
            }
            case 2:
                searchContacts(phoneBook); 
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
