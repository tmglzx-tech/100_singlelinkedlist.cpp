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
     Node *START;


     public:
     LinkedList()
     {
        START = NULL;
     }

     void addNode()
     {
        int nim;
        cout << "/nMasukkan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;


     

     if (START == NULL || nim <= START->noMhs)
     {
        if (START != NULL && nim == START->noMhs)
        {
            cout << "/nDuplikasi noMhs tidak diijinkan\n";
            return;
        }

        nodeBaru->next =START;
        START = nodeBaru;
        return;
     }

     Node *previous =START;
     Node *current = START;

     while (current != NULL && nim > current->noMhs)
     {
        if (nim == current->noMhs)
        {
cout << "\nDuplikasi noMhs tidak dijinkan\n";
return;
        }
        previous = current;
        current = current->next;

     }
     nodeBaru-> next = current;
     previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search (int nim, Node *&previous, Node *&current)
    {
        previous = START;
        current = START;

        while (current != NULL && nim != current ->noMhs)
        {
            previous = current;
            current = current -> next;
        }

        return (current != NULL);
    }


    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!search(nim,previous,current))
        return false;

        if (current == START)
        START = START->next;
        else previous->next = current->next;
        delete current;
        return true;

    }

    void traverse (){
    if (listEmpty())
    {
        cout << "\nList Kosong\n";
    }
    else
    {
        cout << "\nData di dalam list adalah\n";
        Node *currentNode = START;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << endl;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
            case '1':
            mhs.addNode();
            break;
            
            case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong" << endl;
                break;
            }

            cout << "\nMasukkan no mahasiswa yang akan dihapus : ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
                cout << "\nData tidak ditemukan" << endl;
            else
                cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus\n";
            break;
            
            case '3':
            mhs.traverse();
            break;

            case '4':
            {
                if (mhs.listEmpty())
                {
                    cout << "\nList Kosong\n";
                    break;
                }

                 Node *previous, *current;
                 cout << "\nMasukkan no mahasiswa yang dicari : ";
                 cin >> nim;

                 if (mhs.search(nim, previous, current) == false)
                    cout << "\nData tidak ditemukan\n";
                 else
                {
                    cout << "\nData ditemukan\n";
                    cout << "NIM Mahasiswa : " << current->noMhs << endl;
                }
                break;
            }

            case '5':
                break;
            
            default:
                cout << "\nPilihan salah!\n";
        }

    } while (ch != '5');

    return 0;
}