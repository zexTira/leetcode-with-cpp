/*//
//  In this question we need to list all sorts of conditions that would happen in a number, which shows a reflecting relationship between number and Roman.
//  Function convertIntToRoman suggests this relationship, and it can convert num to a corresponding Roman.
//  Function intToRoman is in response of converting every digit in this num from beginning to end, using converting function, and add the output string to the result.
//  *Still we can use hash table to solve this question.
//*/

class Solution {
public:
    string convertIntToRoman(int num) {
        switch (num) {
        case 1000: return "M"; break;
        case 900: return "CM"; break;
        case 500: return "D"; break;
        case 400: return "CD"; break;
        case 100: return "C"; break;
        case 90: return "XC"; break;
        case 50: return "L"; break;
        case 40: return "XL"; break;
        case 10: return "X"; break;
        case 9: return "IX"; break;
        case 5: return "V"; break;
        case 4: return "IV"; break;
        case 1: return "I"; break;
        }
        return NULL;
    }

    string intToRoman(int num) {
        string res = "";
        if (num >= 1000) {
            for (int i = 0; i < num / 1000; i++) {
                res += convertIntToRoman(1000);
            }
            num = num % 1000;
        }
        if (num >= 900) {
            for (int i = 0; i < num / 900; i++) {
                res += convertIntToRoman(900);
            }
            num = num % 900;
        }
        if (num >= 500) {
            for (int i = 0; i < num / 500; i++) {
                res += convertIntToRoman(500);
            }
            num = num % 500;
        }
        if (num >= 400) {
            for (int i = 0; i < num / 400; i++) {
                res += convertIntToRoman(400);
            }
            num = num % 400;
        }
        if (num >= 100) {
            for (int i = 0; i < num / 100; i++) {
                res += convertIntToRoman(100);
            }
            num = num % 100;
        }
        if (num >= 90) {
            for (int i = 0; i < num / 90; i++) {
                res += convertIntToRoman(90);
            }
            num = num % 90;
        }
        if (num >= 50) {
            for (int i = 0; i < num / 50; i++) {
                res += convertIntToRoman(50);
            }
            num = num % 50;
        }
        if (num >= 40) {
            for (int i = 0; i < num / 40; i++) {
                res += convertIntToRoman(40);
            }
            num = num % 40;
        }
        if (num >= 10) {
            for (int i = 0; i < num / 10; i++) {
                res += convertIntToRoman(10);
            }
            num = num % 10;
        }
        if (num >= 9) {
            for (int i = 0; i < num / 9; i++) {
                res += convertIntToRoman(9);
            }
            num = num % 9;
        }
        if (num >= 5) {
            for (int i = 0; i < num / 5; i++) {
                res += convertIntToRoman(5);
            }
            num = num % 5;
        }
        if (num >= 4) {
            for (int i = 0; i < num / 4; i++) {
                res += convertIntToRoman(4);
            }
            num = num % 4;
        }
        if (num >= 1) {
            for (int i = 0; i < num / 1; i++) {
                res += convertIntToRoman(1);
            }
            num = num % 1;
        }
        return res;
    }
};