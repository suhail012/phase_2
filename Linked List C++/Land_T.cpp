#include <iostream>
#include <vector>
using namespace std;
string one[] = {"", "One ", "Two ", "Three ", "Four ",
                "Five ", "Six ", "Seven ", "Eight ",
                "Nine ", "Ten ", "Eleven ", "Twelve ",
                "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ",
                "Nineteen "};

string ten[] = {"", "", "Twenty ", "Thirty ", "Forty ",
                "Fifty ", "Sixty ", "Seventy ", "Eighty ",
                "Ninety "};

string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}
string convertWord(int n)
{
    string out;

    out += numToWords((n / 10000000), "Crore ");

    out += numToWords(((n / 100000) % 100), "Lakh ");

    out += numToWords(((n / 1000) % 100), "Thousand ");

    out += numToWords(((n / 100) % 10), "Hundred ");

    if (n > 100 && n % 100)
        out += "And ";
    out += numToWords((n % 100), "");

    // Handling the n=0 case
    if (out == "")
        out = "Zero";

    return out;
}
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int solve(int n, vector<string> &ele, vector<string> &emotion)
{
    vector<int> freq;
    for (auto itm : ele)
    {
        string temp;
        for (unsigned int i = 0; i < itm.size(); i++)
        {
            if (isdigit(itm[i]))
                temp += itm[i];
        }
        freq.push_back(stoi(temp));
    }

    int totalScore = 0;
    for (int i = 0; i < n; i++)
    {
        if (emotion[i] == "Happy")
        {
            totalScore += (freq[i] * 10);
        }
        else if (emotion[i] == "Sad")
        {
            totalScore += (freq[i] * 5);
        }
        else if (emotion[i] == "Neutral")
        {
            totalScore += (freq[i] * 2);
        }
        else if (emotion[i] == "None")
        {
            totalScore += (freq[i] * 1);
        }
    }

    vector<int> vowel;
    for (auto item : ele)
    {
        int cnt = 0;
        for (unsigned int i = 0; i < item.size(); i++)
        {
            if (item[i] == 'a'|| item[i] == 'A'|| item[i] == 'e'|| item[i] == 'E'|| item[i] == 'i'|| item[i] == 'o'|| item[i] == 'u')
            {
                cnt++;
            }
        }
        vowel.push_back(cnt);
    }
    int totalVowel = 0;
    for (int i = 0; i < n; i++)
    {
        totalVowel += (freq[i] * vowel[i]);
    }

    return totalScore / totalVowel;
}
int main()
{
    int n;
    cin >> n;
    vector<string> ele(n);
    vector<string> emotion(n);
    for (int i = 0; i < n; i++)
    {

        cin >> ele[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> emotion[i];
    }
    int val = solve(n, ele, emotion);
    string temp;
    if (isPrime(val))
    {
        temp += "Yes";
    }
    else
    {
        temp += "No";
    }
    cout << temp << " " << convertWord(val) << " ";
}