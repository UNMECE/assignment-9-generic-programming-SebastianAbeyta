#include <iostream>

using namespace std;

template <typename T>
class Generic_Array
{
    public:
        Generic_Array() : data(nullptr), array_size(0) {}
        
        ~Generic_Array() {delete[] data;}
        
        void addElement(T element)
        {
            if (array_size == 0)
            {
                data = new T[1];
            }
            else
            {
                T* new_data = new T[array_size+1];
                copy(data, data + array_size, new_data);
                delete[] data;
                data = new_data;
            }
            data[array_size++] = element;
        }

        T at(int index)
        {
            if (index < 0 || index >= array_size)
            {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        int size() const {return array_size;}

        T sum() const
        {
            T sum = 0;
            for(int i = 0; i < array_size; i++)
            {
                sum += data[i];

            }
            return sum;

        }

        T max() const
        {
            if(array_size == 0) 
            {
                cout<<"The array is empty";
            }

            T value = data[0];

            for(int i = 1; i < array_size; i++) 
            {
                if (data[i] > value) 
                {
                    value = data[i];
                }   
            }
            return value;
        }

        T min() const
        {
            if(array_size == 0) 
            {
                cout<<"The array is empty";
            }

            T value = data[0];

            for(int i = 1; i < array_size; i++) 
            {
                if (data[i] < value) 
                {
                    value = data[i];
                }   
            }
            return value;

        }

        Generic_Array<T> slice(int begin, int end)
        {
            if(begin < 0 || end >= array_size || begin > end) 
            {
                throw std::out_of_range("Invalid slice indices");
            }

            Generic_Array<T> slice_array;

            for(int i = begin; i <= end; ++i) 
            {
                slice_array.addElement(data[i]);
            }
            return slice_array;
        }
    private:
        T* data;
        int array_size;
};




int main()
{
    Generic_Array<int> int_array;

    int_array.addElement(10);
    int_array.addElement(11);
    int_array.addElement(12);
    int_array.addElement(13);
    int_array.addElement(14);
    int_array.addElement(15);

    cout << "size of the array: " << int_array.size() << std::endl;

    std::cout << "sum of the array: " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array: " << int_array.max() << " and " << int_array.min() << std::endl;

    Generic_Array<int> sliced_array = int_array.slice(1,4);

    cout.flush();

    cout << "sliced array: ";
    for (int i = 0; i < sliced_array.size(); ++i) 
    {
        cout<< sliced_array.at(i) << " ";
    }
    cout << endl;
    return 0;
}