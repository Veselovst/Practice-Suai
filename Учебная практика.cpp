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
    ofstream file_output, file_output_analysis;

    if ((file_output) && (file_output_analysis)) // Проверяем открыт ли файл
    {
        int n = 0; //номер файла
        cout << "Введите номер файла (от 1 до 10): ";
        n = check(n);
        /*cout<<endl;*/
        original_text = input_words(n);
        if (original_text.size() > 0)
        {
            unsigned long long start = __rdtsc();//Измеряет время в тактах процессора 
            Sortirovka_Rascheska(original_text);
            unsigned long long result_time = __rdtsc() - start;//Такты в конце - такты в начале 
            result_text = original_text; // присваиваем вектору уже отсортированный вектор                
            analysis(result_text, n, result_time);

            result_output(result_text, n);
            file_output_analysis.close(); // Закрытие файла 
            file_output.close(); // Закрытие файла
        }
        else cout << "Нужных слов нет" << endl;
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл output или file_output_analysis не открылся!" << std::endl;
}

int check(int a)
{
    while (!(cin >> a) || (a > 10) || (a < 1)) // пока не будет введено целое число до 31 включительно
    {
        if ((cin.fail()) || (a > 10) || (a < 1)) // если ошибка ввода 
        {
            cout << "Повторите попытку ввода " << endl;
            cin.clear(); // Очищаем буфер ввода 
            cin.ignore(1000, '\n'); // Убирает новую строку из cin 
        }
    } return a; // возвращение функцией числа, прошедшего проверку 
}

vector <string> input_words(int n)
{
    ifstream file_input;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_1.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_2.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_3.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_4.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_5.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_6.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_7.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_8.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_9.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_10.txt", ios_base::in);// ввод в  файл 
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

void Sortirovka_Rascheska(vector<string>& original_text) // data — название вектора  (передаём по ссылке, чтобы вызов comb(array) менял вектор array)
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
        step /= factor;
    }
}

void analysis(vector <string> result_text, int n, unsigned long long result_time)
{
    ifstream file_input;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_1.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_2.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_3.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_4.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_5.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_6.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_7.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_8.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_9.txt", ios_base::in);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_input.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\original_10.txt", ios_base::in);// ввод в  файл 
        break;
    }
    }

    ofstream file_output_analysis;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_1.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_2.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_3.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_4.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_5.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_6.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_7.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_8.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_9.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_output_analysis.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\analysis_10.txt", ios_base::out);// ввод в  файл 
        break;
    }
    }
    char symbol;
    while (file_input.get(symbol))
    {
        file_output_analysis << symbol;
    }
    file_input.close(); //закрытие файла
    cout << endl;
    file_output_analysis << endl << endl;
    int  k = result_text[result_text.size() - 1].size(); // количество символов в самом коротком слове
    int count = 0;                                         // счётчик слов
    file_output_analysis << "Вариант: Латиница,по количеству символов в слове, по убывани, игнорировать числа, сортировка Расчёской \nВремя сортировки: " << result_time / 1000 << "сек" << endl << endl;
    cout << "Вариант: Латиница,по количеству символов в слове, по убывани, игнорировать числа, сортировка Расчёской \nВремя сортировки: " << result_time / 2.50 << " мксек" << endl;
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
    file_output_analysis << "Количество слов размерностью " << k << " " << count << endl;
    cout << "Количество слов размерностью " << k << ": " << count << endl;
}

void result_output(vector <string> result_text, int n)
{
    ofstream file_output;
    switch (n)//Выбираем файл на открытие в зависимости от n
    {
    case(1):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_1.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(2):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_2.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(3):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_3.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(4):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_4.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(5):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_5.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(6):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_6.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(7):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_7.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(8):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_8.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(9):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_9.txt", ios_base::out);// ввод в  файл 
        break;
    }
    case(10):
    {
        file_output.open("C:\\Users\\hikao\\Desktop\\УЧЕБНАЯ ПРАКТИКА\\Учебная практика\\result_10.txt", ios_base::out);// ввод в  файл 
        break;
    }
    }

    for (int i = 0; i < result_text.size(); i++)
    {
        file_output << result_text[i] << endl;
    }
}
