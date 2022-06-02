# Программа сортировки слов текста
Программа выполняет сортировку слов в тексте.

## Параметры сортировки
+ Латиница: Работа с символами «abcdefghijklmnopqrstuvwxyz1234567890»;
+ Слова сортируются по длине
+ Числа не учитываются
+ Слова сортируются в порядке убывания
+ В программе используется сортировка расчёской
___

## Параметры входных и выходных данных

На вход программа принимает номер нужного текстового файла. 
В результате выполнения программной функции создаются два выходных файла Вывод и Анализ.

Первый файл содержит результат работы программы:
+ Слова из исходного файла отсортированные по длине в порядке убывания

![image](https://user-images.githubusercontent.com/104787756/171735544-8cc8621f-2b3d-441b-93ed-70208b6b99bd.png)

*Пример файла Результат*

Второй файл содержит анализ работы программы:
+ Исходный текст;
+ Параметры варианта;
+ Количество слов; 
+ Время выполнения программы;
+ Количество слов с определённым размером.

![image](https://user-images.githubusercontent.com/104787756/171736401-9b429346-0742-4170-8ede-b2ca3221a689.png)

*Пример файла Анализ*
___

# Описание программной функции

В начале работы программа запрашивает номер файла, который нужно отсортировать. Происходит проверка введённого значения:
```C++
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
```
При успешном прохождении проверки программа открывает нужный файл с помощью конструкции switch case:
```C++
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
```
После программа начинает заполнять вектор словами из выбранного текста, игнорируя числа, другие символы не являющиеся буквой латинского алфавита:
```C++
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
```
Далее программа идёт в функцию сортировки. Пока работает сортировка, программа фиксирует время её действия. Сортирока осуществляется алгоритмом под названием расчёска:
```C++
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
```
Далее происходит вывод анализа на консоль и в файл анализ с таким же номером, что и исходный текст. Выбор в какой файл выводить реализован с помощью switch case.
(2 конструкции switch case пропущены так как были представлены выше)
```C++
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
```
![image](https://user-images.githubusercontent.com/104787756/171741086-d797fb0f-9e00-4f43-97f4-6534f45872e1.png)

*Пример вывода на консоль*

После вывода анализа программа выводит отсортированный массив в файл result с помощью switch case.
(switch case пропущен, так как представлен выше)
```C++
    {
        for (int i = 0; i < result_text.size(); i++)
        {
            file_output << result_text[i] << endl;
        }
    }
 ```
