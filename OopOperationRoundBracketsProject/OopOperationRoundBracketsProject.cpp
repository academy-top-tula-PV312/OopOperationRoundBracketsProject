//#include <iostream>
//
//class ArraySortSelect;
//
//class ArrayInt
//{
//    int* items;
//    int size;
//public:
//    ArrayInt();
//    ArrayInt(int size);
//
//    void Init();
//
//    int Size();
//
//    friend std::ostream& operator<<(std::ostream& out, const ArrayInt& array);
//
//    int& operator[](int index);
//
//    void Sort();
//    void Sort(ArraySortSelect sort);
//};
//
//class ArraySortSelect
//{
//    ArrayInt* array;
//public:
//    ArraySortSelect() : array{ nullptr } {};
//    void SetArray(ArrayInt* array)
//    {
//        this->array = array;
//    }
//    void operator()();
//};
//
//
//
//int main()
//{
//    ArrayInt array(10);
//    array.Init();
//
//    std::cout << array << "\n";
//
//    //array.Sort();
//    array.Sort(ArraySortSelect());
//
//    std::cout << array << "\n";
//    
//}
//
//
//
//
//ArrayInt::ArrayInt() 
//    : items{ nullptr }, 
//      size{} { srand(time(nullptr)); }
//
//ArrayInt::ArrayInt(int size) 
//    : items{ new int[size] }, 
//    size{ size } { srand(time(nullptr)); }
//
//void ArrayInt::Init()
//{
//    for (int i{}; i < size; i++)
//        items[i] = rand() % 100;
//}
//
//int ArrayInt::Size(){ return size; }
//
//int& ArrayInt::operator[](int index)
//{
//    return items[index];
//}
//
//void ArrayInt::Sort()
//{
//    for (int i{}; i < size; i++)
//        for (int j{ size - 1 }; j > i; j--)
//            if (items[j] < items[j - 1])
//                std::swap(items[j], items[j - 1]);
//}
//
//void ArrayInt::Sort(ArraySortSelect sort)
//{
//    sort.SetArray(this);
//    sort();
//}
//
//std::ostream& operator<<(std::ostream& out, const ArrayInt& array)
//{
//    for (int i{}; i < array.size; i++)
//        out << array.items[i] << " ";
//    return out;
//}
//
//void ArraySortSelect::operator()()
//{
//    for (int i{}; i < array->Size(); i++)
//    {
//        int min{ i };
//        for (int j{ i + 1 }; j < array->Size(); j++)
//            if ((*array)[j] < (*array)[min])
//                min = j;
//        std::swap((*array)[min], (*array)[i]);
//    }
//}