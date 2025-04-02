class Solution {
public:
    int countDigit(int n) {
        if (n / 10 == 0)
            return 1;
        return 1 + countDigit(n / 10);
    }
    int toThePowerOf(int p) {
        int result = 1;
        for (int i = 0; i < p; i++)
            result *= 10;
        return result;
    }
    string dictionary(int subInt) {
        switch (subInt) {
        case 1:
            return "I";
            break;
        case 2:
            return "II";
            break;
        case 3:
            return "III";
            break;
        case 4:
            return "IV";
            break;
        case 5:
            return "V";
            break;
        case 6:
            return "VI";
            break;
        case 7:
            return "VII";
            break;
        case 8:
            return "VIII";
            break;
        case 9:
            return "IX";
            break;
        case 10:
            return "X";
            break;
        case 20:
            return "XX";
            break;
        case 30:
            return "XXX";
            break;
        case 40:
            return "XL";
            break;
        case 50:
            return "L";
            break;
        case 60:
            return "LX";
            break;
        case 70:
            return "LXX";
            break;
        case 80:
            return "LXXX";
            break;
        case 90:
            return "XC";
            break;
        case 100:
            return "C";
            break;
        case 200:
            return "CC";
            break;
        case 300:
            return "CCC";
            break;
        case 400:
            return "CD";
            break;
        case 500:
            return "D";
            break;
        case 600:
            return "DC";
            break;
        case 700:
            return "DCC";
            break;
        case 800:
            return "DCCC";
            break;
        case 900:
            return "CM";
            break;
        case 1000:
            return "M";
            break;
        default:
            return "";
        }
    }
    string biggerThan1000(int denominator, int digit, string roman) {
        if (denominator > 1000)
            denominator /= 10;
        for (int i = 0; i < digit / 1000; i++) {
            roman += dictionary(denominator);
        }
        return roman;
    }
    string intToRoman(int num) {
        string roman = "";
        int digit;
        while (num != 0) {
            int power = countDigit(num);
            int denominator = toThePowerOf(power - 1);
            digit = abs((num % denominator) - num);
            dictionary(digit) != ""
                ? roman += dictionary(digit)
                : roman += biggerThan1000(denominator, digit, roman);
            num %= denominator;
        }
        return roman;
    }
};