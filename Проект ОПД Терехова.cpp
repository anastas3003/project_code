#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <random>

using namespace std;

class Menu
{
private:
    int a;
    int b;
public:
    int OpenMenu()
    {
        cout<<"Меню:\n";
        cout<<"1.Теория\n";
        cout<<"2.Практика\n";
        cout<<"3.Выход\n";
        cout<<"Выберите пункт меню: ";
        cin>>a;
        if((a=1)||(a=2))
        {
            cout<<"1.Правописание корней;\n";
            cout<<"2.Правописание приставок;\n";
            cout<<"3.Правописание суффиксов различных частей речи (кроме -Н-/-НН-);\n";
            cout<<"4.Правописание личных окончаний глаголов;\n";
            cout<<"5.Правописание НЕ и НИ (слитное и раздельное написание);\n";
            cout<<"6.Слитное, дефисное, раздельное написание слов;\n";
            cout<<"7.Правописание –Н- и –НН- в различных частях речи;\n";
            cout<<" Назад.\n";
            cout<<"Выберите раздел: ";
            cin>>b;
        }
    }

    int Filename()
    {
        string filename;

        switch(b)
        {
        case 1:
            filename="D:\\Korni.txt";
            break;
        case 2:
            filename="D:\\Pristavki.txt";
            break;
        case 3:
            filename="D:\\Suffiksy.txt";
            break;
        case 4:
            filename="D:\\Okonchaniya.txt";
            break;
        case 5:
            filename="D:\\Neini.txt";
            break;
        case 6:
            filename="D:\\Napisanie.txt";
            break;
        case 7:
            filename="D:\\Ninn.txt";
            break;
        case 8:
            cout<<"Меню:\n";
            cout<<"1.Теория\n";
            cout<<"2.Практика\n";
            cout<<"3.Выход\n";
           break;
    }


    }


int OpenFiles(){
int length;
char * buffer;
string filename;
ifstream is;
is.open (filename, ios::binary );

// get length of file:
is.seekg (0, ios::end);
length = is.tellg();
is.seekg (0, ios::beg);

// allocate memory:
buffer = new char [length];

// read data as a block:
is.read (buffer,length);
is.close();

cout.write (buffer,length);

delete[] buffer;
}

int FilesT()
{

    string filename1;
    switch(b)
    {
    case 1:
        filename1="D:\\project\\Korniz.txt";
        break;
    case 2:
        filename1="D:\\project\\Pristavkiz.txt";
        break;
    case 3:
        filename1="D:\\project\\Suffiksyz.txt";
        break;
    case 4:
        filename1="D:\\project\\Okonchaniyaz.txt";
        break;
    case 5:
        filename1="D:\\project\\Neiniz.txt";
        break;
    case 6:
        filename1="D:\\project\\Napisaniez.txt";
        break;
    case 7:
        filename1="D:\\project\\Ninnz.txt";
        break;
    }
}
};


class Tasks
{
private:
    char words[54000][25];
    int k;
    int i, j;
    char word[25];
    char *filename=new char[15];
    size_t cnt, n;
public:
    int Answers()
    {

        cout<<"Напишите слова с пропущенными буквами через пробел:\n";
        for(k=1;k<=3;k++)
        { 
        FILE *file;                           
        srand(time(NULL));

        //
        //{
            file = fopen("D:\\project\\Korniz.txt", "r");
        if (file == NULL){
            cout<<"Файл не может быть открыт\n";
            return 1;
        }

        cnt = 0;
        while(1==fscanf(file, "%24s", word)){
            if(cnt == 54000)
                break;
            strcpy(words[cnt++], word);
        }
        fclose(file);
        n = cnt;
        if(n > RAND_MAX){
            int part;
            size_t random = 0;
            i = n / RAND_MAX;
            part = rand() % (i+1);
            if(part == i){
                j = n % RAND_MAX;
                if(j != 0)
                    random = random + RAND_MAX*part + rand() % j;
                else
                    random = random + RAND_MAX*(part-1) + rand();
            } else {
                random = random + RAND_MAX*part + rand();
            }
            printf("%s\n", words[random]);

        } else {
            int random = rand() % n;
            printf("%s\n", words[random]);

        }

            }
    }
     }
};


class Count
{
private:
    int points;
    int mark;
public:
    int Search()
    {
        char search[255], answer[255], stranswer[255], str[15000], base[9]={0}, * c; //search - что ищем; answer - ответ;
        //base - путь к базе;
            bool dialog = true;
         FILE * fbase;
            string s = "Korni_answers.txt";
        strcpy(base, s.c_str());
        fbase = fopen(base, "r");
            cout << "Слово: ";
            cin >> search;
            ifstream input(s.c_str());
            char buffer[1024];
            while(input.getline(buffer,1024)) {
            if(strstr(buffer, search))
points++;
    }

    }
    int True()
    {
        if((points=0)||(points=1))
            mark=2;
        if((points=2)||(points=3))
            mark=3;
        if((points=4)||(points=5))
            mark=4;
        if((points=6)||(points=7))
            mark=5;
        cout<<"Количество набранных баллов: "<<points;
        cout<<"Ваша оценка: "<<mark;
    }

};



int main()
    {
    setlocale(LC_CTYPE,"rus");
    Menu Open;
    Open.OpenMenu();
    //Points.OpenFiles();
    Tasks Ask;
    Ask.Answers();
    Count cnt;
    cnt.Search();
    cnt True();
    return 0;
    }
