#include<iostream>
using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        if (num.length() < 3) return false;
        long long prev = num[0] - 48;
        long long rear = num[1] - 48;
        long long sum = num[2] - 48;
        if (prev == 0 && rear == 0 && sum == 0) return true;
        if (prev == 0)
        {
            for (int j = 1; j < num.length() - 1; j++)
            {
                int s = j + 1;
                while (sum == 0)
                {
                    j++;
                    s++;
                    rear = rear * 10 + (num[j] - 48);
                    sum = num[s] - 48;
                }
                if (prev + rear < sum && s < num.length() - 1)
                {
                    rear = rear * 10 + (num[j] - 48);
                    sum = num[s] - 48;
                }
                if (prev + rear == sum && isValid(num, prev, rear, sum)) return true;
                for (; prev + rear > sum && s < num.length() - 1; s++)
                {
                    sum = sum * 10 + (num[s + 1] - 48);
                    if (prev + rear == sum && isValid(num, prev, rear, sum, ++s)) return true;
                }
                if (rear == 0) break;

            }
        }
        else
        {
            for (int i = 0; i < num.length() - 2; i++)
            {
                if (i > 0)
                {
                    prev = prev * 10 + (num[i] - 48);
                    rear = num[i + 1] - 48;
                    sum = num[i + 2] - 48;
                }
                for (int j = i + 1; j < num.length() - 1; j++)
                {
                    int s = j + 1;

                    if (prev + rear < sum && s < num.length() - 1)
                    {
                        rear = rear * 10 + (num[j] - 48);
                        sum = num[s] - 48;
                    }
                    while (sum == 0)
                    {
                        j++;
                        s++;
                        rear = rear * 10 + (num[j] - 48);
                        sum = num[s] - 48;
                    }
                    if (prev + rear == sum)
                    {
                        if (isValid(num, prev, rear, sum, s))
                        {
                            return true;
                        }
                        else
                        {
                            //s--;
                            rear = rear * 10 + (num[j] - 48);
                            sum = num[s] - 48;
                        }
                    }
                    for (; prev + rear > sum && s < num.length() - 1; s++)
                    {
                        sum = sum * 10 + (num[s + 1] - 48);
                        if (prev + rear == sum)
                        {
                            if (isValid(num, prev, rear, sum, ++s))
                            {
                                return true;
                            }
                            else
                            { 
                                rear = rear * 10 + (num[j] - 48);
                                sum = num[s] - 48; 
                                s--;
                            }
                        }
                    }
                    if (rear == 0) break;

                }
            }
        }
        return false;
    }

    bool isValid(string num, int prev, int rear, int sum, int s = 2)
    {
        if (s == num.length() - 1) return true;
        prev = rear;
        rear = sum;
        if (s < num.length() - 1)
        {
            sum = num[s++ + 1] - 48;
            if (sum == 0) return false;
        }
        for (; prev + rear > sum && s < num.length() - 1; s++)
        {
            sum = sum * 10 + (num[s + 1] - 48);
            if (prev + rear == sum && s < num.length() - 2)
            {
                s++;
                return isValid(num, prev, rear, sum, s);
            }
        }
        if (prev + rear == sum && s < num.length() - 1 && !isValid(num, prev, rear, sum, s)) return false;
        if (prev + rear < sum || s > num.length() - 1) return false;
        if (prev + rear != sum) return false;
        return true;
    }
};