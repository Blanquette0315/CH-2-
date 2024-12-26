#pragma once

int* Create_Array(int _Cnt);
void Del_Array(int* _Arr_ptr);
int Array_Add(int* _Arr_int_ptr, int _Arr_Cnt);
float Array_Avg(int* _Arr_int_ptr, int _Arr_Cnt);
void Array_Tesk();


void Heapify(int* _Arr_ptr, int _CurIdx, int _Cnt, int _SortType);
void Arr_Swap(int* _Arr_ptr, int fst, int sec);
void BuildHeap(int* _Arr_ptr, int _Cnt, int _SortType);
void heapSort(int* _Arr_ptr, int _Cnt, int _SortType);