#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
float wordCount(char word[],const char* filename)
{
   ifstream fin;
   fin.open(filename);
   int count=0,d=0,sum=0,l;
   char ch[20],a;
   float ans;


    while(fin)
        {
            fin>>ch;
            for(l=0;ch[l]!='\0';l++);
            if(l==1)
            {
                if(ch[0]=='0'||ch[0]=='1'||ch[0]=='2'||ch[0]=='3'||ch[0]=='4')
                d=ch[0]-'0';

            }
            if(strcmp(ch,word)==0)
            {
                count++;
                sum=sum+d;
            }
        }
    fin.close();
    if(count==0)
    {
        cout<<"\n\nWord not appearing in the review file : asdf-2\n";
        return 2;
    }
    else
    {
        ans=(sum)/count;
        return ans;
    }
}
float wordScoreDriver(char word[],const char* filename)
{
    float k;
    k=wordCount(word,filename);
    return k;

}
void reviewScore(float d,char word[])
{
    if(d<1.9)
        cout<<"Negative word: "<<word<<" - "<<d<<"\n\n";
    else if(d>2.1)
        cout<<"Positive word: "<<word<<" - "<<d<<"\n\n";
    else if(d>=1.9&&d<=2.1)
        cout<<"Neutral word: "<<word<<" - "<<d<<"\n\n";
}
int main(int argc, char* argv[])
{
    char filename[20];
    char word[20];
    float k;
    cout<<"Enter the review file:\n";
    cin>>filename;
    int ch=0;
    while(ch!=3)
    {
        cout<<"1.Get the score of the word\n\n2.Get the average score of a review\n\n3. Exit the program\n\n";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter the word you want:\n";
                   cin>>word;
                   k=wordScoreDriver(word,filename);
                   cout<<"The word score of your desired word is: "<<word<<" - ";
                   cout<<fixed<<setprecision(4)<<k<<"\n\n\n";
                   break;
            case 2:cout<<"Provided review file is : "<<filename<<" - ";
                   k=wordScoreDriver(word,filename);
                   cout<<fixed<<setprecision(4)<<k<<"\n\n";
                   reviewScore(k,word);
                   break;
            case 3:cout<<"\n\nThank you!!!Bye\n";
                  break;
        }
    }
    return 0;
}
