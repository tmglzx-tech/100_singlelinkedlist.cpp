#include <iostream>
#include <string> 
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
private:
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;
        nodeBaru->next = NULL;

        if (START == NULL || nim < START->noMhs)
        {
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *current = START;
        Node *previous = NULL;

        while (current != NULL && nim > current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL && nim == current->noMhs)
        {
            cout << "\nDuplikasi tidak diizinkan!\n";
            delete nodeBaru;
            return;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current)
    {
        previous = NULL;
        current = START;

        while (current != NULL && current->noMhs != nim)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!search(nim, previous, current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList kosong\n";
            return;
        }

        cout << "\nData dalam list:\n";
        Node *current = START;

        while (current != NULL)
        {
            cout << current->noMhs << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char pilihan;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah data\n";
        cout << "2. Hapus data\n";
        cout << "3. Tampilkan data\n";
        cout << "4. Cari data\n";
        cout << "5. Keluar\n";
        cout << "Pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            mhs.addNode();
            break;

        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList kosong\n";
                break;
            }

            cout << "\nMasukkan NIM yang akan dihapus: ";
            cin >> nim;

            if (mhs.delNode(nim))
                cout << "\nData berhasil dihapus\n";
            else
                cout << "\nData tidak ditemukan\n";
            break;

        case '3':
            mhs.traverse();
            break;

        case '4':
        {
            if (mhs.listEmpty())
            {
                cout << "\nList kosong\n";
                break;
            }

            Node *prev, *curr;
            cout << "\nMasukkan NIM yang dicari: ";
            cin >> nim;

            if (mhs.search(nim, prev, curr))
            {
                cout << "\nData ditemukan\n";
                cout << "NIM: " << curr->noMhs << endl;
            }
            else
            {
                cout << "\nData tidak ditemukan\n";
            }
            break;
        }

        case '5':
            cout << "\nKeluar program...\n";
            break;

        default:
            cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != '5');

    return 0;
}