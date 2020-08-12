#include <exception>

int Partition(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw std::exception("Invalid Parameters");
    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);
    int samll = start - 1;
    for(index = start; index < end; ++index)
    {
        if(data[index] < data[end])
        {
            ++small;
            if(samll != index)
            {
                Swap(&data[index], &data[small]);
            }
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;
    int index = Partition(data, length, start, end);
    if(index > start)
        QuickSort(data, length, start, index - 1);
    if(index < end)
        QuickSort(data, length, index+1, end);
}