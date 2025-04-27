#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class searchWord
{
	string word;
	public:
		searchWord(string w)
		{
			word=w;
		}
		string getWord()
		{
			return word;
		}
};
int countVowels(string word)
{
	int c=0,i,j;
	string v="aeyuioAEYUIO";
	for(i=0;i<word.size();i++)
	{
		for(j=0;j<v.size();j++)
		{
			if(word[i]==v[j])
			c++;
		}
	}
	return c;
}
vector<string> divideIntoWords(string text)
{
	vector<string> words;
	string word;
	int i;
	for(i=0;i<text.size();i++)
	{
		if(isalpha(text[i]))
			word=word+text[i];
		else if(!word.empty())
		{
			words.push_back(word);
			word.clear();
		}
	}
	if(!word.empty())
	{
		words.push_back(word);
		word.clear();
	}
	return words;
}
vector<string> divideIntoSentences(string text)
{
	int i;
	vector<string> sentences;
	string sentence;
	for(i=0;i<text.size();i++)
	{
		sentence=sentence+text[i];
		if(text[i]=='.'||text[i]=='!'||text[i]=='?')
		{
			sentences.push_back(sentence);
			sentence.clear();
		}
	}
	return sentences;
}
string toLower(string s)
{
	string s1=s;
	s1[0]=tolower(s1[0]);
	return s1;
}
int main()
{
	int i,j;
	ifstream file("z1.txt");
	string text;
	char a;
	while(file.get(a))
	{
		text=text+a;
	}
	file.close();
	cout<<text;
	cout<<endl;
	int c=-1;
	string result1;
	string result2;
	string result3;
	while(c!=0)
	{
		cout<<"1. Duplicate words with >2 vowels \n2. Top 3 words \n3. find key word in sentence \n4. write 1-3 in file \n5. cut the text \n6. merge and sort rows \n0. exit \n";
		cin>>c;
		switch(c)
		{
			case 1:{
				vector<string> words=divideIntoWords(text);
				result1+="Duplicate words with >2 vowels\n";
				for(i=0;i<words.size();i++)
				{
					cout<<words[i]<<" ";
					result1+=words[i];
					result1+=" ";
					if(countVowels(words[i])>2)
					{
						cout<<words[i]<<" ";
						result1+=words[i];
						result1+=" ";
					}
				}	
				result1+="\n";
				cout<<endl;
				break;
			}
			case 2:{
				vector<string> words=divideIntoWords(text);
				vector<string> uniqueWords;
				vector<int> count;
				for(i=0;i<words.size();i++)
				{
					bool found=false;
					for(j=0;j<uniqueWords.size();j++)
					{
						if(uniqueWords[j]==words[i])
						{
							count[j]++;
							found=true;
						}
					}
					if(!found)
					{
						uniqueWords.push_back(words[i]);
						count.push_back(1);
					}
				}
				cout<<"Top 3 words: "<<endl;
				result2+="Top 3 words: \n";
				for(i=0;i<3;i++)
				{
					int indexMax=0;
					for(j=0;j<uniqueWords.size();j++)
					{
						if(uniqueWords[j].size()>uniqueWords[indexMax].size())
						{
							indexMax=j;
						}
					}
					cout<<uniqueWords[indexMax]<<" count "<<count[indexMax]<<endl;
					result2+=uniqueWords[indexMax];
					result2+=" count ";
					result2+=to_string(count[indexMax]);
					result2+="\n";
					uniqueWords.erase(uniqueWords.begin()+indexMax);
					count.erase(count.begin()+indexMax);
				}
				break;
			}
			case 3:{
				vector<string> sentences=divideIntoSentences(text);
				cout<<text<<endl;
				string key;
				cout<<"enter key word ";
				cin>>key;
				result3+="key word - ";
				result3+=key;
				result3+="\n";
				bool found1=false;
				for(i=0;i<sentences.size();i++)
				{
					bool found=false;
					vector<string> words=divideIntoWords(sentences[i]);
					for(j=0;j<words.size();j++)
					{
						if(key==words[j])
						{
							found=true;
							found1=true;
						}
					}
					if(found)
					{
						cout<<sentences[i]<<endl;
						result3+=sentences[i];
						result3+="\n";
					}
				}
				if(!found1)
					{
						cout<<"not found"<<endl;
						result3+="not found \n";
					}
				break;
			}
			case 4:{
				cout<<"enter file ";
				string fileName;
				cin>>fileName;
				ofstream file(fileName);
				file<<result1<<result2<<result3;
				file.close();
				break;
			}
			case 5:{
				cout<<"enter word ";
				string word;
				cin>>word;
				searchWord w(word);
				string key=w.getWord();
				vector<string> words=divideIntoWords(text);
				int count=0;
				for(i=0;i<words.size();i++)
				{
					if(key==words[i])
						count++;
				}
				if(count<2)
				{
					cout<<"word occurs <2 times"<<endl;
					break;
				}
				int start=-1,end=-1;
				int count1=0;
				for(i=0;i<text.size();i++)
				{
					bool found=false;
					int k=0;
					for(j=0;j<key.size();j++)
					{
						if(text[i+j]==key[j])
							k++;
					}
					if(k==key.size())
					{
						found=true;
					}
					if(count1==0&&found)
					{
						start=i-1;
					}
					if(found)
						count1++;
					if(count1==count&&found)
					{
						end=i+1+key.size();
					}
				}
				if(end==-1||start==-1)
					cout<<"!!!!!!";
				ofstream file("z3.txt");
				string text1;
				for(i=start;i<end;i++)
				{
					text1+=text[i];
					a++;
				}
				cout<<text1<<endl;
				file<<text1;
				file.close();
				break;
			}
			case 6:{
				string s1(text);
				string s2;
				int count=0;
				int k=0;
				vector<string> wordsS1=divideIntoWords(text);
				count=wordsS1.size();
				ifstream file("t.txt");
				while(file.get(a)&&k!=count)
				{
					s2=s2+a;
					if(!isalpha(a))
						k++;
				}
				file.close();
				string s3;
				s3=s1+" "+s2;
				vector<string> words=divideIntoWords(s3);
				for(i=0;i<words.size();i++)
				{
					for(j=0;j<words.size()-1;j++)
					{
						if(toLower(words[j])>toLower(words[j+1]))
						{
							swap(words[j],words[j+1]);
						}
					}
				}
				ofstream file1("z4.txt");
				file1<<"s1: "<<endl<<s1<<endl<<"s2:"<<endl<<s2<<endl<<"s3: ";
				for(i=0;i<words.size();i++)
				{
					file1<<words[i]<<" ";
				}
				file1<<endl;
				file1.close();
				cout<<"done"<<endl;
				break;
			}
		}
	}
	return 0;
}