//1 текст - Arthur Conan Doyle - The Adventure of Sherlock Holmes (Приключения Шерлока Холмса) (3009 слов)
//2 текст - Herbert Wells - The Invisible Man (Человек-невидимка) (4508 слов)
//3 текст - Scott Fitzgerald - The Great Gatsby (Великий Гэтсби)
//4 текст - Mark Twain - The Adventures of Tom Sawyer (Приключения Тома Сойера)
//5 текст - Oscar Wilde - The Picture of Dorian Gray (Портрет Дориана Грея)
//6 текст - Charlotte Bronte - Jane Eyre (Джейн Эйр)
//7 текст - Bram Stoker - Dracula (Дракула)
//8 текст -Emily Jane Bronte - Wuthering Heights (Грозовой перевал)
//9 текст - Robert Louis Stevenson - Treasure Island (Остров сокровищ)
//10 текст - Jane Austen - Pride and Prejudice (Гордость и предубеждение)

#include <iostream>
#include <Windows.h> 
#include <fstream>
#include <vector> 
#include <string>
#include <ctype.h>
#include <ctime>
#include <intrin.h>
#include <time.h>

using namespace std;

void Sortirovka_Rascheska(vector<string>& original_text);//Функция сортировки
int check(int a);
vector <string> input_words(int n);//Функция заполнения исходного вектора и выбора файла
void analysis(vector <string> result_text, int n, unsigned long long resalt_time);//Запись данных в файлы
void result_output(vector <string> result_text, int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <string> original_text;
    vector <string> result_text;
    {
        int n = 0; //номер файла
        cout << "Введите номер файла (от 1 до 10): ";
        n = check(n);
        original_text = input_words(n);
        if (original_text.size() > 0)
        {
            unsigned int time_start = clock();
            Sortirovka_Rascheska(original_text);
            unsigned int time_end = clock();
            result_text = original_text; // присваиваем вектору уже отсортированный вектор   
            unsigned int result_time = time_end - time_start;
            analysis(result_text, n, result_time);
            result_output(result_text, n);
        }
        else cout << "Нужных слов нет" << endl;
    }
}

int check(int a)
{
    while (!(cin >> a) || (a > 10) || (a < 1))
    {
        cin.clear();                             // очистка буфера
        while (cin.get() != '\n')                // пока не дошли до конца строки, продолжаем 
            continue;
        cout << "Повторите попытку ввода " << endl;        // вывод ошибки на экран
    }
    return a;
}

vector <string> input_words(int n)
{
    ifstream file_input;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_1.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_2.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_3.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_4.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_5.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_6.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_7.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_8.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_9.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_10.txt", ios_base::in);// ввод в  файл 
        break;
    }
    }
    vector <string> words;
    string temp;
    if (file_input)
    {
        while (file_input >> temp)
        {
            string new_word;

            for (int i = 0; i < temp.size(); i++)
            {
                if ((temp[i] >= 'A' && temp[i] <= 'z'))
                {
                    new_word += temp[i];
                }
            }
            if (new_word.size() > 0)//Если слово было записано
                words.push_back(new_word);  //записываем в вектор слов
        }
        file_input.close();
        return words;
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
    {
        std::cout << "Файл input не открылся!" << std::endl;
        file_input.close(); // Закрытие файла 
        return words;//возвращаем это значение
    }
}

void Sortirovka_Rascheska(vector<string>& original_text)
{
    double factor = 1.2473309; // фактор уменьшения
    int step = original_text.size() - 1; // шаг сортировки

    //Последняя итерация цикла, когда step==1 эквивалентна одному проходу сортировки пузырьком
    while (step >= 1)
    {
        for (int i = 0; i + step < original_text.size(); i++)
        {
            if (original_text[i].size() < original_text[i + step].size())
            {
                swap(original_text[i], original_text[i + step]);
            }
        }
        step /= factor;  // step=step/ factor
    }
}

void analysis(vector <string> result_text, int n, unsigned long long result_time)
{
    ifstream file_input;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_1.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_2.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_3.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_4.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_5.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_6.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_7.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_8.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_9.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Texts\\original_10.txt", ios_base::in);// ввод в  файл 
        break;
    }
    }

    ofstream file_output_analysis;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_1.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_2.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_3.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_4.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_5.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_6.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_7.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_8.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_9.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Analysis\\analysis_10.txt", ios_base::out);// ввод в  файл 
        break;
    }
    }
    if (file_input)
    {
        char symbol;
        while (file_input.get(symbol))
        {
            file_output_analysis << symbol;
            /* cout << symbol;*/
        }
        file_input.close(); //закрытие файла
        cout << endl;
        file_output_analysis << endl << endl;
        int  k = result_text[result_text.size() - 1].size(); // количество символов в самом коротком слове
        int count = 0;                                         // счётчик слов
        file_output_analysis << "Вариант: Латиница,по количеству символов в слове, по убыванию, игнорировать числа, сортировка Расчёской \nВремя сортировки: " << result_time << "мс" << endl << endl;
        cout << "Вариант: Латиница,по количеству символов в слове, по убыванию, игнорировать числа, сортировка Расчёской \nВремя сортировки: " << result_time << " мс" << endl;
        cout << endl;
        cout << "Кол.-во слов в тексте: " << result_text.size();
        file_output_analysis << "Кол.-во слов в тексте: " << result_text.size() << endl;
        cout << endl;
        for (int i = result_text.size() - 1; i >= 0; i--)  // от конца по всему ветору слов
        {
            if (result_text[i].size() == k)      // если размер слова равен к, то увеличиваем счётчик
            {
                count++;
            }
            else
            {
                file_output_analysis << "Количество слов размерностью " << k << ": " << count << endl;
                cout << "Количество слов размерностью " << k << ": " << count << endl;
                count = 0;
                k = result_text[i].size();  // присваеваем к новый размер слова
                i++;
            }
        }
        file_output_analysis << "Количество слов размерностью " << k << ": " << count << endl;
        cout << "Количество слов размерностью " << k << ": " << count << endl;
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
    {
        cout << "Файл input не открылся!" << std::endl;
        file_input.close(); // Закрытие файла 
    }
}


void result_output(vector <string> result_text, int n)
{
    ofstream file_output;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_1.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_2.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_3.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_4.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_5.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_6.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_7.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_8.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_9.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\Практика учебная\\Results\\result_10.txt", ios_base::out);// ввод в  файл 
        break;
    }
    }
    {
        for (int i = 0; i < result_text.size(); i++)
        {
            file_output << result_text[i] << endl;
        }
    }
}