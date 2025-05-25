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
//	Elem elem; //�������� �� ���������
//	bool eof, eor; //eor - ������� ����� ����� 
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
    bool eof;  // ����� �����
    bool eor;  // ����� �����

    Sequence();
    void open_read(const std::string& filename);
    void open_write(const std::string& filename);
    void close();
    void read_next();
    void write_element(const Elem& e, bool end_series = false);
};




//� ���� ������ ���� ������ ������. ������ ��� ������������ 
//sequence ����� �������� ������

//void distribute(Sequence& f1, Sequence& f2, Sequence& f0, std::string filename) //����� � ��������� ��� �����, ������ ��� �����������, � � ���� ������ ���� ������ ������
//{
//	f0.star_read(filename);
//	f1.star_write("f1.txt");
//	f2.star_write("f1.txt");
//	//��� ����� ����� ����������� ������ ������
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
////� ���� ������� ����������� ������ ���� ��������, ��� ���������� ����� ���������� �� �����, ��� �� ������� 
//int merge(Sequence& f0, std::string filename, Sequence& f1, Sequence& f2)
//{
//	f1.star_read("f1.txt");
//	f2.star_read("f2.txt");
//	f0.star_write(filename);
//	
//	//��� ����� ������ ���� ������ ����
//	//������ ������ ���� ������������� ������������� 
//	//f+ to_string(1) + txt
//	//������ ���� ��� �� ������������� ��������� 
//	// ������ � ����� ������������� ��� �������, ������� ������� �� �
//
//	int count{}; //��� ���������� �����
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
//	//��� ����� ���� ����� ���������� ��� ����������� ������ ����� ����� 
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
//	//� ������������ ������ copy_run � ++cnt
//
//	f0.close();
//	f1.close();
//	f2.close();
//	return count;
//}
//
//void sort(std::string filename)
//{
//	Sequence f0, f1, f2; //�.�. � ���� ������������, �� � ���� ������ �������� f0 � ����� ����� ������ ��������������� ������
//	int cnt{};
//
//	do
//	{
//		distribute(f1, f2, f0, filename);
//		cnt = merge(f0, filename, f1, f2);
//	} while (cnt > 1);
//	remove("f1.txt");
//	remove("f2.txt");
//	//� ���� ��� ������� ������ 
//} 

//����� �������� �������, ������� ������� ��������� ���� filename
//����� �������� ������� check_file, ������� ���������, ��� ���� ����������, ������ ������� ���������� �����, ������� ���������� � �����, ���� ��� �� �����������
//�� � �������������� ������� ����� ������ �����, ��� � ���, ������� ���������� ���
//� ����� ������ ���� create, sort, check � ������ ������ �� ������ ����
//������ ���� i, ������� ���� �� ������, �� ���� ��� ���� ������ i = (i+1)%3 �� ��� ���, ���� f0 �� ����������
