#include <stdio.h>

int main()
{
    int fibonacci[100];      // Mảng lưu dãy Fibonacci
    int prev = -1, curr = 1; // Biến lưu hai giá trị trước của dãy Fibonacci
    int n;                   // Số lượng phần tử của dãy Fibonacci và mảng đầu vào

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    // Tính và in dãy Fibonacci
    printf("Day Fibonacci:\n");
    for (int i = 0; i < n; i++)
    {
        int next = prev + curr; // Tính phần tử tiếp theo của dãy Fibonacci
        prev = curr;            // Cập nhật giá trị trước đó
        curr = next;            // Cập nhật giá trị hiện tại
        printf("%d ", next);    // In phần tử của dãy Fibonacci
    }
    printf("\n");

    // Mảng đầu vào
    int inputArray[100];      // Mảng lưu giá trị đầu vào
    int max = -1000000;       // Biến lưu giá trị lớn nhất
    int secondMax = -1000000; // Biến lưu giá trị lớn thứ hai

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &inputArray[i]); // Nhập từng phần tử của mảng

        // Tìm giá trị lớn nhất và lớn thứ hai
        if (inputArray[i] > max)
        {
            secondMax = max;     // Cập nhật giá trị lớn thứ hai
            max = inputArray[i]; // Cập nhật giá trị lớn nhất
        }
        else if (inputArray[i] > secondMax && inputArray[i] < max)
        {
            secondMax = inputArray[i]; // Cập nhật giá trị lớn thứ hai
        }
    }

    // In kết quả
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri lon thu hai: %d\n", secondMax);

    return 0; // Kết thúc chương trình
}
