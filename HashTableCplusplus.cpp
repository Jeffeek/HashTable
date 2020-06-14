#include <iostream>
#include "HashTable.h"
#include "Referate.h"

using namespace std;
int main()
{
    setlocale(0, "");
    int _size;
    string _reloadInput;
    cin >> _size;
    system("cls");
    HashTable<Referate>* HT = new HashTable<Referate>(_size);
    while (true)
    {
        cout << "\n0. Выход.";
        cout << "\n1. Добавление элемента.";
        cout << "\n2. Поиск элемента по ключу и вывод всей информации.";
        cout << "\n3. Вывод содержимого хеш-таблицы с указанием хеш-адреса и всех хранящихся по этому адресу элементов.";
        cout << "\n4. Удаление элемента по значению ключа.\n";
        int answer;
        cin >> answer;
        switch (answer)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            getline(cin, _reloadInput);
            string Theme;
            int Year;
            int CountOfSheets;
            string Author;
            cout << "\nВведите тему: ";
            getline(cin, Theme);
            cout << "\nВведите автора реферата: ";
            getline(cin, Author);
            cout << "\nВведите год: ";
            cin >> Year;
            cout << "\nВведите количество страниц: ";
            cin >> CountOfSheets;
            auto item = new Referate(Theme, Year, CountOfSheets, Author);
            HT->Add(*item);
            cout << "Готово!";
            break;
        }

        case 2:
        {
            getline(cin, _reloadInput);
            cout << "Введите ключ: ";
            int searchKey;
            cin >> searchKey;
            auto searchCollection = HT->GetList();
            Referate *referateItem = new Referate();
            for(int i = 0; i < _size; i++)
                for(int j = 0; j < searchCollection[i]->Nodes.size(); j++)
                {
                    if (searchCollection[i]->Nodes[j].GetHashCode() == searchKey)
                    {
                        (*referateItem) = searchCollection[i]->Nodes[j];
                        break;
                    }
                }
                

            if (referateItem[0].GetAuthor() == "")
            {
                cout << "\nНет элементов с таким ключом (";
            }
            else
            {
                cout << "\n" << referateItem->ToString();
            }

            break;
        }

        case 3:
        {
            cout << "\nВывод всей информации: \n";
            HT->ShowTable();
            break;
        }

        case 4:
        {
            cout << "Введите ключ: ";
            int deleteKey;
            cin >> deleteKey;
            auto delCollection = HT->GetList();
            for(int i = 0; i < _size; i++)
                for(int j = 0; j < delCollection[i]->Nodes.size(); j++)
                if (delCollection[i]->Nodes[j].GetHashCode() % _size == deleteKey)
                {
                    HT->Remove(delCollection[i]->Nodes[j]);
                    break;
                }
            break;
        }
        default:
	    {
            exit(0);
	    }
        break;
        }
    }
}

