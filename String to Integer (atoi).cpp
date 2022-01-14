//method 1usingint
class Solution {
public:
    //TC O(n)
    //SC O(1)
    //[-2^31, 2^31 - 1] = [INT_MIN, INT_MAX]
    int myAtoi(string str) {
         int sign = 1, num = 0, i = 0;
        while (str[i] == ' ') {  //discards all leading whitespaces
            i++;
        }
        if (str[i] == '-' || str[i]=='+') { //sign of the number
            if(str[i]=='-')sign = -1;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') { //forming our num
            if (num >  INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > 7)) {
                //handling overflow & underflow
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            num  = 10 * num + (str[i++] - '0');
        }
        return num * sign;  //returning final result;
    }
};

//method 2 using long longsimple solution
class Solution {
public:
    //TC O(n)
    //SC O(1)
    //[-2^31, 2^31 - 1] = [INT_MIN, INT_MAX]
    int myAtoi(string str) {
         int sign = 1, i = 0;
        long long num = 0;
        while (str[i] == ' ') {  //discards all leading whitespaces
            i++;
        }
        if (str[i] == '-' || str[i]=='+') { //sign of the number
            if(str[i]=='-')sign = -1;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') { //forming our num
            num  = 10 * num + (str[i++] - '0'); //'2'-'0'=2 //2+'0'='2'
            if (num >  INT_MAX) {
                //handling overflow & underflow
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
          
        }
        return num * sign;  //returning final result;
    }
};
