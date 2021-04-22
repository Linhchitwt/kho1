#include <iostream>
#include <math.h>
using namespace std;

class number
{
public:
    int num;
    int pos;
    number *next;
    number()
    {
        num = 0;
        pos = 0;
        next = NULL;
    }
};
class change
{
public:
    number *head;
    change()
    {
        head = NULL;
    }
    change(number *head)
    {
        this->head = head;
    }
    void create(int num)
    {
        int tempPos = 0;
        while (num != 0)
        {
            number *temp = new number();
            temp->num = num % 10;
            temp->pos = tempPos;
            if (head == NULL)
                head = temp;
            else
            {
                temp->next = head;
                head = temp;
            }
            tempPos++;
            num /= 10;
        }
    }
    int trans()
    {
        number *p = head;
        int result = 0;
        while (p != NULL)
        {
            result += p->num * pow(3, p->pos);
            p = p->next;
        }
        return result;
    }
};
int main()
{
    int num;
    cout << "nhap vao so co co so 3: ";
    cin >> num;
    int check = num;
    bool can = true;
    while (check != 0)
    {
        int temp = num % 10;
        if (temp >= 3)
        {
            can = false;
            break;
        }
        check /= 10;
    }
    if (!can)
        cout << "so khong hop le" << endl;
    else
    {
        change *a = new change();
        a->create(num);
        int result = a->trans();
        cout << "gia tri co so 10: " << result;
    }
    return 0;
}
