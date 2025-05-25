//#pragma once
//
//#include <string>
//#include <cstdio>
//#include <sstream>
//#include "Sequence.h"
//
//const int n = 3;
//
//void distribute(Sequence& f0, Sequence* files, std::string filename) {
//    f0.star_read(filename);
//    for (int i = 0; i < n; ++i) {
//        files[i].star_write("f" + std::to_string(i + 1) + ".txt");
//    }
//
//    int i = 0;
//    while (!f0.eof) {
//        files[i].copy_run(f0);
//        i = (i + 1) % n;
//    }
//
//    f0.close();
//    for (int j = 0; j < n; ++j) files[j].close();
//}
//
//int merge(Sequence& f0, std::string filename, Sequence* files) {
//    for (int i = 0; i < n; ++i)
//        files[i].star_read("f" + std::to_string(i + 1) + ".txt");
//
//    f0.star_write(filename);
//    bool done[n] = {};
//    int count = 0;
//
//    while (true) {
//        int active = 0;
//        for (int i = 0; i < n; ++i)
//            if (!files[i].eof) ++active;
//        if (active == 0) break;
//
//        while (true) {
//            int min_idx = -1;
//            for (int i = 0; i < n; ++i) {
//                if (!files[i].eof && !files[i].eor) {
//                    if (min_idx == -1 || files[i].elem <= files[min_idx].elem) {
//                        min_idx = i;
//                    }
//                }
//            }
//
//            if (min_idx == -1) break;
//
//            f0.copy(files[min_idx]);
//        }
//
//        for (int i = 0; i < n; ++i) {
//            if (!files[i].eor && !files[i].eof) {
//                f0.copy_run(files[i]);
//            }
//        }
//        ++count;
//    }
//
//    for (int i = 0; i < n; ++i)
//        while (!files[i].eof) {
//            f0.copy_run(files[i]);
//            ++count;
//        }
//
//    f0.close();
//    for (int i = 0; i < n; ++i)
//        files[i].close();
//    return count;
//}
//
//void sort(std::string filename) {
//    Sequence f0;
//    Sequence files[n];
//    int cnt = 0;
//
//    do {
//        distribute(f0, files, filename);
//        cnt = merge(f0, filename, files);
//    } while (cnt > 1);
//
//    for (int i = 0; i < n; ++i)
//        std::remove(("f" + std::to_string(i + 1) + ".txt").c_str());
//}