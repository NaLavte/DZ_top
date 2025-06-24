#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Book {
	string name;
    string author;
    string publishingHouse;
    string genre;
};

void EditBook(Book* arr, int size) {
    string newBook;
    int choice;
    int INTchoice;
    cout << "Какую по книгу вы хотите отредактировать?\n";
    for (int i = 0; i < size; i++) {
        cout << i << ". " << arr[i].name << "\n";
    }
    cout << "Напишите индекс книги: ";
    cin >> choice;
    cout << "\nЧто вы хотите изменить\n"
        "1. имя\n"
        "2. автор\n"
        "3. издательский дом\n"
        "4. жанр: ";
    cin >> INTchoice;
    cout << "На что вы хотите изменить: ";
    cin >> newBook;
    switch (INTchoice) {
    case 1: arr[choice].name = newBook; break;
    case 2: arr[choice].author = newBook; break;
    case 3: arr[choice].publishingHouse = newBook; break;
    case 4: arr[choice].genre = newBook; break;
    }
}

void PrintBook(Book* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Книга " << i + 1;
        cout << "\n\t" << "Название: " << arr[i].name;
        cout << "\n\t" << "Автор: " << arr[i].author;
        cout << "\n\t" << "Издательство: " << arr[i].publishingHouse;
        cout << "\n\t" << "Жанр: " << arr[i].genre << "\n\n";
    }
}

int SearchAuthor(Book* arr, int size) {
    string SearchAuthor;
    
    cout << "Введите автора которого хотите найти: ";
    getline(cin, SearchAuthor);

    for (int i = 0; i < size; i++) {
        if (arr[i].author == SearchAuthor) {
            cout << "Автор найден под индексом " << i;
            return i;
        }
    }
    cout << "Автор не найден.";
    return -1;
}

int SearchName(Book* arr, int size) {
    string SearchName;

    cout << "Введите название книги которую хотите найти: ";
    getline(cin, SearchName);

    for (int i = 0; i < size; i++) {
        if (arr[i].name == SearchName) {
            cout << "Книга найдена под индексом " << i << endl;
            return i;
        }
    }
    cout << "Книга не найдена." << endl;
    return -1;
}

void SortBooksName(Book* arr, int size) {
    sort(arr, arr + size, [](const Book& a, const Book& b) {
        return a.name < b.name;
        });
}

void SortBookAuthor(Book* arr, int size) {
    sort(arr, arr + size, [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
}

void SortBookPublishingHouse(Book* arr, int size) {
    sort(arr, arr + size, [](const Book& a, const Book& b) {
        return a.publishingHouse < b.publishingHouse;
        });
}

int main()
{
	const int size = 10;
    int decision;
    Book arr[size] = {
        {"The Master and Margarita", "Mikhail Bulgakov", "ГИХЛ", "Фантастика"},
        {"War and Peace", "Leo Tolstoy", "Российская книжная палата", "Историческая литература"},
        {"Crime and punishment", "Fyodor Dostoevsky", "Аст", "Драма/Психологический роман"},
        {"One hundred years of solitude", "Gabriel Garcia Marquez", "Sudamericana", "Магический реализм"},
        {"Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Bloomsbury", "Фэнтези"},
        {"1984", "George Orwell", "Secker & Warburg", " dystopian"},
        {"The Three Musketeers", "Alexander Dumas", "Hetzel", "Приключение"},
        {"The Brothers Karamazov", "Fyodor Dostoevsky", "Русский книжный клуб", "Философский роман"},
        {"Ivanhoe", "Walter Scott", "Cadell & Davies", "Исторический роман"},
        {"Anna Karenina", "Leo Tolstoy", "Российский библиотечный институт", "Драма"}
    };

    do {
        cout << "\n\n\n1. Редактировать книгу\n"
            "2. Печать всех книг\n"
            "3. Поиск книг по автору\n"
            "4. Поиск книги по названию\n"
            "5. Сортировка массива по названию книг\n"
            "6. Сортировка массива по автору\n"
            "7. Сортировка массива по издательству\n"
            "8. Выйти\n"
            "Что вы хотите сделать: ";
        cin >> decision;
        cout << "\n\n\n";
        switch (decision) {
        case 1: EditBook(arr, size); break;
        case 2: PrintBook(arr, size); break;
        case 3: SearchAuthor(arr, size); break;
        case 4: SearchName(arr, size); break;
        case 5: SortBooksName(arr, size); break;
        case 6: SortBookAuthor(arr, size); break;
        case 7: SortBookPublishingHouse(arr, size); break;
        }
   
    } while (decision < 8);
}