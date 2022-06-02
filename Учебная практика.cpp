#include <iostream>
#include <Windows.h> 
#include <fstream>
#include <vector> 
#include <string>
#include <ctype.h>
#include <ctime>

using namespace std;

fstream file_input, file_output;

void Sortirovka_Rascheska(vector<string>& original_text);
vector <string> write_words();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <string> original_text;
    vector <string> result_text;

    file_input.open("C:\\Users\\hikao\\Desktop\\Проги\\Учебная практика\\original.txt",
        ios::in);// ввод в  файл 
    file_output.open("C:\\Users\\hikao\\Desktop\\Проги\\Учебная практика\\result.txt",
        ios::out);// ввод в  файл 
    cout << endl;
    if (file_input)  // Проверяем открыт ли файл
    {   
        if (file_output) 
        {    
            original_text = write_words();
            for (int i = 0; i < original_text.size(); i++)
             {
               cout << original_text[i];
             }
            cout << endl;
            Sortirovka_Rascheska(original_text);
            result_text = original_text;
            for (int i = 0; i < result_text.size(); i++)
            {
                cout << result_text[i];
            }

            file_input.close(); // Закрытие файла 
            file_output.close(); // Закрытие файла

        }
        else // Если файл не удалось открыть, тогда выдаем ошибку
            std::cout << "Файл output не открылся!" << std::endl;
    }
    else // Если файл не удалось открыть, тогда выдаем ошибку
        std::cout << "Файл input не открылся!" << std::endl;
}

vector <string> write_words()
{
    vector <string> words;
    string temp;
    while (file_input>>temp)
    {
        string new_word;

        for (int i = 0; i < temp.size(); i++)
        {

            if((temp[i] >= 'A' && temp[i] <= 'z')) 
            {
               
                    new_word += temp[i];
            }

        }
        words.push_back(new_word);;  //вывод слова

    }
    return words;
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
