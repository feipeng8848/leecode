#include<stdio.h>
#include <malloc.h>
int* plusOne(int* digits, int digitsSize, int* returnSize);
void swap(int *p1, int *p2);

int main()
{
    int testArray[]={1,2,3,4};
    int *returnSize = malloc(sizeof(int));
    int *result;
    result = plusOne(testArray,4,returnSize);
    printf("the resultarray size is %d\n",*returnSize);

    for(int i=0;i<4;i++)
    {
         printf("the value of result[%d] is %d\n",i,result[i]);
    }    
    return 0;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //思路：
    //倒叙遍历数组，如果数字小于9直接加一返回
    //如果数字刚好等于9，那么就涉及到进位，变为0，然后执行上一位。
    //如果遍历完所有的数组元素还没返回，那就涉及到数组最高位的进位，数组多加一个元素，新加的元素是1，其余元素的值是0

    int *resultArray;

    for(int i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]<9)
        {
            digits[i]++;
            *returnSize =  digitsSize;
            return digits;
        }
        digits[i]=0;
    }

    *returnSize =  digitsSize+1;
    resultArray = malloc(sizeof(int)*(*returnSize));
    resultArray[0]=1;
    for(int i = 1;i<(*returnSize);i++)
    {
        resultArray[i]=0;
    }
    return resultArray;
    
}


/*
遇到的坑：
1、*p 不能赋值，出现错误。
指针作为函数的参数的时候，要先分配内存。
如上述程序line9：int *returnSize = malloc(sizeof(int));
之前一直使用 int *returnSize;，然后就一直报错。

2、*returnSize 在plusOne函数中是正确的值，当函数执行到return的时候就显示为0
未找到原因，后来执行成功了。
*/