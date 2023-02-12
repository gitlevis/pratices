#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* dst, const char* src)
{
    assert(dst && src);
    const char* pd = dst;
    const char* pdStart = dst;
    const char* ps = src;
    while(*pdStart)
    {
        while(*pd++==*ps++)
        {
            if(*ps=='\0')
            {
                return (char*)pdStart;
            }
        }
        pdStart++;
        pd = pdStart;
        ps = src;
    }
    return NULL;
}

void test01()
{
    char arr1[] = "hello";
    char arr2[] = "ll";
    char *p = my_strstr(arr1, arr2);
    printf("%s", p);
}

int main()
{
    test01();
    return 0;
}