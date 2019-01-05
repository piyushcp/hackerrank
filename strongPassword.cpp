#include <bits/stdc++.h>

using namespace std;


int minimumNumber(int n, string password) {
   
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    int low_case=0,up_case=0,sp_char=0,num=0,req_leng=0,j;

   for (int i=0;i<n;i++)
   {
       for(j=0;j<26;j++)
         if(password[i]==lower_case[j])
           low_case++;
        for(j=0;j<26;j++)
         if(password[i]==upper_case[j])
           up_case++;
        for(j=0;j<special_characters.length();j++)
           if(password[i]==special_characters[j])
           sp_char++;
        for(j=0;j<10;j++)
         if(password[i]==numbers[j])
           num++;
   }
    if(low_case ==0 )
        req_leng++;
    if(up_case ==0)
        req_leng++;
    if(sp_char ==0)
        req_leng++;
    if(num ==0)
        req_leng++;
    if (n+req_leng < 6)
      req_leng = req_leng + 6 - (req_leng + n );     

return req_leng;   
}  

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
