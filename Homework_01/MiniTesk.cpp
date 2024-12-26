#include "pch.h"
#include "MiniTesk.h"

using namespace std;

// ==========================================================
// 배열을 사용해 5개의 숫자를 입력받고, 합계와 평균을 반환해보자.
// Array_Add : 배열의 모든 원소를 더해주는 함수
// Array_Avg : 배열 원소의 평균을 구하는 함수
// Array_Tesk : 실행 함수
// ==========================================================

int* Create_Array(int _Cnt)
{
	int* New_Arry_ptr = new int[_Cnt];

	return New_Arry_ptr;
}

void Del_Array(int* _Arr_ptr)
{
	if (_Arr_ptr != nullptr)
		delete _Arr_ptr;

	return;
}

int Array_Add(int* _Arr_int_ptr, int _Arr_Cnt)
{
	int Acc_Num = 0;
	for (int i = 0; i < _Arr_Cnt; ++i)
	{
		Acc_Num += _Arr_int_ptr[i];
	}

	return Acc_Num;
}

float Array_Avg(int* _Arr_int_ptr, int _Arr_Cnt)
{
	float Avg_Num = 0;
	Avg_Num = (float)Array_Add(_Arr_int_ptr, _Arr_Cnt) / (float)_Arr_Cnt;

	return Avg_Num;
}

void Array_Tesk()
{
	int Arr_Count = 0;
	int SortType = 0;

	cout << "만들 배열의 원소 수를 입력해주세요." << endl;
	cin >> Arr_Count;

	int* New_Arr_ptr = Create_Array(Arr_Count);

	cout << "배열에 들어갈 수를 전부 입력해주세요." << endl;

	for (int i = 0; i < Arr_Count; ++i)
	{
		cin >> New_Arr_ptr[i];
	}

	cout << "정렬방법을 선택해 주세요!\n오름차순 : 1\n내림차순 : 2\n";
	cin >> SortType;

	heapSort(New_Arr_ptr, Arr_Count, SortType);

	cout << "배열 정렬 결과 : ";
	for (int i = 0; i < Arr_Count; ++i)
	{
		cout << New_Arr_ptr[i] << " ";
	}
	cout << endl;

	cout << "배열 원소의 총합은 " << Array_Add(New_Arr_ptr, Arr_Count) << "입니다." << endl;
	cout << "배열 원소의 평균은 " << Array_Avg(New_Arr_ptr, Arr_Count) << "입니다." << endl;

	Del_Array(New_Arr_ptr);

	return;
}


// ==========================================================
// 사용자가 입력한 숫자 배열을 정렬하는 프로그램 구현하기
// 조건 1. 오름차순, 내림차순 정렬이 가능해야 한다.
// 조건 2. 숫자 1을 입력하면 오름차순 정렬, 2를 누르면 내림차순 정렬을 해야한다.
// 조건 3. algorithm의 sort()를 사용하면 안된다.
// 조건 4. 오름차순과 내림차순 정렬을 각각 함수로 구현할 것.
// ==========================================================

void Heapify(int* _Arr_ptr, int _CurIdx, int _Cnt, int _SortType)
{
	int left = _CurIdx * 2 + 1;
	int right = _CurIdx * 2 + 2;
	int MinMax = _CurIdx;

	if (_SortType == 1)
	{
		if (left < _Cnt && _Arr_ptr[left] > _Arr_ptr[MinMax])
			MinMax = left;
		if (right < _Cnt && _Arr_ptr[right] > _Arr_ptr[MinMax])
			MinMax = right;
	}
	else if (_SortType == 2)
	{
		if (left < _Cnt && _Arr_ptr[left] < _Arr_ptr[MinMax])
			MinMax = left;
		if (right < _Cnt && _Arr_ptr[right] < _Arr_ptr[MinMax])
			MinMax = right;
	}

	if (MinMax != _CurIdx)
	{
		Arr_Swap(_Arr_ptr, MinMax, _CurIdx);
		Heapify(_Arr_ptr, MinMax, _Cnt, _SortType);
	}
}

void Arr_Swap(int* _Arr_ptr, int fst, int sec)
{
	int temp = _Arr_ptr[fst];
	_Arr_ptr[fst] = _Arr_ptr[sec];
	_Arr_ptr[sec] = temp;
}

void BuildHeap(int* _Arr_ptr, int _Cnt, int _SortType)
{
	for (int i = _Cnt / 2 - 1; i >= 0; --i)
	{
		Heapify(_Arr_ptr, i, _Cnt, _SortType);
	}
}

void heapSort(int* _Arr_ptr, int _Cnt, int _SortType)
{
	BuildHeap(_Arr_ptr, _Cnt, _SortType);
	for (int TreeSize = _Cnt - 1; TreeSize >= 0; --TreeSize)
	{
		Arr_Swap(_Arr_ptr, 0, TreeSize);
		Heapify(_Arr_ptr, 0, TreeSize, _SortType);
	}
}