#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Elem.h"

//const int n = 3;

//struct Sequence
//{
//	std::fstream file;
//
//
//	Elem elem; //заменить на структуру
//	bool eof, eor; //eor - принзак конца серии 
//	void read_next();
//	void star_read(std::string filename);
//	void star_write(std::string filename);
//	void close();
//	void copy(Sequence& x);
//	void copy_run(Sequence& x);
//};

class Sequence {
public:
    std::fstream file;
    Elem elem;
    bool eof;  //  онец файла
    bool eor;  //  онец серии

    Sequence();
    void open_read(const std::string& filename);
    void open_write(const std::string& filename);
    void close();
    void read_next();
    void write_element(const Elem& e, bool end_series = false);
};




//у мен€ должен быть массив файлов. потому что многопутева€ 
//sequence можно называть файлом

//void distribute(Sequence& f1, Sequence& f2, Sequence& f0, std::string filename) //здесь у каплиевой два файла, потому что двухпутевое, а у мен€ должен быть массив файлов
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
////в моем сли€ние равномерном должно быть показано, что количество серий отличаетс€ не более, чем на единицу 
//int merge(Sequence& f0, std::string filename, Sequence& f1, Sequence& f2)
//{
//	f1.star_read("f1.txt");
//	f2.star_read("f2.txt");
//	f0.star_write(filename);
//	
//	//вот здесь должен быть массив имен
//	//массив должен быть автоматически формироватьс€ 
//	//f+ to_string(1) + txt
//	//должна быть как то задействовано константа 
//	// должны в цикле наформировать эти файлики, которые завис€т от н
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
//	Sequence f0, f1, f2; //т.к. у мен€ многопутевое, то у мен€ должен остатьс€ f0 и потом будет массив вспомогательных файлов
//	int cnt{};
//
//	do
//	{
//		distribute(f1, f2, f0, filename);
//		cnt = merge(f0, filename, f1, f2);
//	} while (cnt > 1);
//	remove("f1.txt");
//	remove("f2.txt");
//	//у мен€ дл€ массива файлов 
//} 

//нужно написать функцию, котора€ создает случайный файл filename
//нужно написать функцию check_file, котора€ провер€ет, что файл упор€дочен, должна считать количество чисел, которое получаетс€ в файле, если что то неправильно
//то в результирующем файлике будет меньше чисел, чем в том, который изначально был
//в мейне должно быть create, sort, check и больше ничего не должно быть
//должно быть i, котора€ идет по кольцу, то есть дл€ трех файлов i = (i+1)%3 до тех пор, пока f0 не закончитс€
