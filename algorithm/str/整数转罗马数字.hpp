/*
解法：贪心
*/
string intToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string res;
    
    for (int i = 0; i < 13; i ++ )  //这里不使用图里的count了，一遍一遍来就行了
        while(num >= values[i])
        {
            num -= values[i];
            res += reps[i];
        }
    return res;
}

string intToRoman(int num)
{
    char* c[4][10] = {
        {"","I","II","III","IV","V","VI","VII","VIII","IX"},
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"","M","MM","MMM"}
    };
    string roman;
    roman.append(c[3][num / 1000]);
    roman.append(c[2][num / 100 % 10]);
    roman.append(c[1][num / 10 % 10]);
    roman.append(c[0][num % 10]);
        
    return roman;
}
