//#include <iostream>
//#include <string>
//#include <fstream>
//#include "Elem.h"
//#include "Sequence.h"
//
////const int n = 3;
//
////у меня должен быть массив файлов. потому что многопутевая 
////sequence можно называть файлом
//void distribute(Sequence& f1, Sequence& f2, Sequence& f0, std::string filename) //здесь у каплиевой два файла, потому что двухпутевое, а у меня должен быть массив файлов
//{
//	f0.star_read(filename);
//	f1.star_write("f1.txt");
//	f2.star_write("f1.txt");
//	//мне здесь нужно приготовить массив файлов
//
//	while (!f0.eof)
//	{
//		f1.copy_run(f0);
//		if (!f0.eof)
//			f2.copy_run(f0);
//	}
//	f0.close();
//	f1.close();
//	f2.close();
//}
//
////в моем слияние равномерном должно быть показано, что количество серий отличается не более, чем на единицу 
//int merge(Sequence& f0, std::string filename, Sequence& f1, Sequence& f2)
//{
//	f1.star_read("f1.txt");
//	f2.star_read("f2.txt");
//	f0.star_write(filename);
//
//	//вот здесь должен быть массив имен
//	//массив должен быть автоматически формироваться 
//	//f+ to_string(1) + txt
//	//должна быть как то задействовано константа 
//	// должны в цикле наформировать эти файлики, которые зависят от н
//
//	int count{}; //это количество серий
//
//
//	while (!f1.eof && !f2.eof)
//	{
//		while (!f2.eor && !f1.eor)
//		{
//
//			if (f1.elem <= f2.elem)
//				f0.copy(f1);
//			else
//				f0.copy(f2);
//		}
//		if (!f1.eor)
//			f0.copy_run(f1);
//		if (!f2.eor)
//			f0.copy_run(f2);
//		f1.eor = f1.eof;
//		f2.eor = f2.eof;
//		++count;
//	}
//
//	//вот здесь надо будет переписать под копирование только одной серии 
//	while (!f1.eof)
//	{
//		f0.copy_run(f1);
//		++count;
//	}
//
//	while (!f2.eof)
//	{
//		f0.copy_run(f2);
//		++count;
//	}
//	//у равномерного только copy_run и ++cnt
//
//	f0.close();
//	f1.close();
//	f2.close();
//	return count;
//}
//
//void sort(std::string filename)
//{
//	Sequence f0, f1, f2; //т.к. у меня многопутевое, то у меня должен остаться f0 и потом будет массив вспомогательных файлов
//	int cnt{};
//
//	do
//	{
//		distribute(f1, f2, f0, filename);
//		cnt = merge(f0, filename, f1, f2);
//	} while (cnt > 1);
//	remove("f1.txt");
//	remove("f2.txt");
//	//у меня для массива файлов 
//}
//
////нужно написать функцию, которая создает случайный файл filename
////нужно написать функцию check_file, которая проверяет, что файл упорядочен, должна считать количество чисел, которое получается в файле, если что то неправильно
////то в результирующем файлике будет меньше чисел, чем в том, который изначально был
////в мейне должно быть create, sort, check и больше ничего не должно быть
////должно быть i, которая идет по кольцу, то есть для трех файлов i = (i+1)%3 до тех пор, пока f0 не закончится
