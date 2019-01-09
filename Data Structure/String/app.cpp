/*****************************************
Title
	Chandu and Consecutive Letters
Autor
	Juan Eizmendi
*****************************************/
/*****************************************
Title
	Chandu and Consecutive Letters
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int T;

	cin >> T;
	while(T--)
	{
		cin >> str;
		for (string::iterator i = str.begin()+1; i != str.end(); ++i)
			if(*i == *(i-1)) 
				str.erase(i), i--;
		cout << str << endl;
	}
	return 0;
}
*/
/*****************************************
Title
	Unique Strings
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	bool alphabet[26];
	string temp, out;
	cin >> T;
	T++;
	while(T--)
	{
		cin >> temp;
		out = "";
	
		for (int i = 0; i < 26; i++) 
		{
			alphabet[i] = 0;
		}
	
		for (int i = 0; i < temp.length(); i++)
		{
			if(!alphabet[temp[i]-97])
			{
				alphabet[temp[i]-97] = 1;
				out.push_back(temp[i]);
			}
		}
		cout << out << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Anagrams
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Anagrams {
    string A, B;
    vector<int> alph;

public:
    Anagrams(string a, string b)
    {
    	A = a;
    	B = b;
    	alph.resize(26);
    	for (int i = 0; i < 26; i++)
    	{
    		alph[i] = 0;
    	}
    }

    string Solve()
    {
    	renderIN();

    	if(areAnagrams())
    	{
    		return "YES";
    	}

    	if(A.length() == B.length())
    	{
    		return "NO LUCK";
    	}
		
		return findPalindrome();

    }

    string findPalindrome()
    {
    	int sum = 0;
    	int odds = 0;
    	string::iterator itA = A.begin(), itB = B.begin();

		while(itA != A.end())
		{
			alph[*itA-97]++;
			itA++;
		}
		while(itB != B.end())
		{
			alph[*itB-97]--;
			itB++;
		}

    	for (vector<int>::iterator it = alph.begin(); it != alph.end(); it++)
    	{
    		*it = abs(*it);
    		if((*it)%2 == 1) odds++;
			sum += *it;
    	}

    	if(odds > 1)
    	{
    		return "NO LUCK";
    	}
		
		string concat = "";
    	
    	if(sum == 1)
    	{
			for (vector<int>::iterator it = alph.begin(); it != alph.end(); it++)
	    	{
	    		if(*it != 0) 
	    		{
	    			return concat + (char)((it-alph.begin())+97);
	    		}
	    	}    		
    	}

    	
    	int ii = 0;
		for (int i = 0; i < 26; i++)
    	{
   			while(alph[i] > 1)
   			{
   				concat.insert(concat.begin()+ii, (char)i+97);
   				concat.insert(concat.end()-ii, (char)i+97);
   				ii++;
   				alph[i] -= 2;
   			}
    	}

    	if(odds == 1)
    	{
			for (int i = 0; i < 26; i++)
	    	{
	    		if(alph[i] != 0)
	    		{
	    			concat.insert(concat.begin()+ii, (char)i+97);
	    		}
	    	}
    	}

    	return concat;
    }
	
	bool areAnagrams()
	{
		if(A.length() != B.length())
		{
			return false;
		}

		string::iterator itA = A.begin(), itB = B.begin();

		while(itA != A.end())
		{
			alph[*itA-97]++;
			alph[*itB-97]--;
			itA++;
			itB++;
		}

		for (vector<int>::iterator it = alph.begin(); it != alph.end(); it++)
		{
			if(*it != 0) 
			{
				return false;
			}
		}

		return true;
	}

    void renderIN()
    {
    	string::iterator it;
    	it = A.begin();
    	while(it != A.end())
    	{
    		if(*it < 91 && *it > 64)
    		{
    			*it += 32;
    		}
    		else if(*it > 122 || *it < 97)
    		{
    			A.erase(it);
    			it--;
    		}
    		it++;
    	}
    	it = B.begin();
    	while(it != B.end())
    	{
    		if(*it < 91 && *it > 64)
    		{
    			*it += 32;
    		}
    		else if(*it > 122 || *it < 97)
    		{
    			B.erase(it);
    			it--;
    		}
    		it++;
    	}
    }
};

int main()
{
	int T;
	string A, B;
	Anagrams *ana;
	cin >> T;
	cin.ignore();
	while(T--)
	{
		getline(cin, A);
		getline(cin, B);
		ana = new Anagrams(A, B);
		cout << ana->Solve() << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Missing Alphabets 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Comparator {
    string alphabet;
public:
    Comparator(string a) : alphabet(a) {}

    bool operator()(string a, string b) {
        int i = 0;
		while(a[i] == b[i] && i != a.length() && i != b.length()) i++;
		if(i == a.length()) return true;
		if(i == b.length()) return false;
		return ccSort(a[i], b[i]);
    }
    
    bool ccSort(char a, char b)
	{
		int ia, ib;
		for (int i = 0; i < alphabet.length(); i++)
		{
			if(alphabet[i] == a) ia = i;
			if(alphabet[i] == b) ib = i;
		}
		return ia < ib;
	}
};

int main()
{
	int T, N, n;
	string alphabet, temp;
	vector<string> *words;
	cin >> T;

	while(T--)
	{
		cin >> alphabet >> N;
		words = new vector<string>();
		n = N;
		while(n--)
		{
			cin >> temp;
			words->push_back(temp);
		}

		sort(words->begin(), words->end(), Comparator(alphabet));

		for (int i = 0; i < N; i++)
			cout << words->at(i) << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Swapping Game 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Encrypt
string iteration(string temp)
{
	string newstring = "";
	string::iterator itA, itB;
	itA = temp.begin();
	itB = temp.end()-1;
	while(itA < itB)
	{
		newstring.push_back(*itA);
		newstring.push_back(*itB);
		itA++;
		itB--;
	}
	if(itA == itB)
		newstring.push_back(*itA);

	return newstring;
}

int main()
{
	long long int T;
	string temp, aux, aux2;
	cin >> T >> temp;

	while(T--)
	{
		int a = 0;
		aux = "";
		aux2 = "";
		while(a < temp.length())
		{
			if(a%2 == 1)
			{
				aux.push_back(temp[a]);
				//temp.erase(a,1);
			}
			else
			{
				aux2.push_back(temp[a]);
			}
			a++;
		}
		reverse(aux.begin(), aux.end());
		temp = aux2+aux;
		cout << temp << endl;
	}

	cout << temp << endl;
    return 0;
}
*/
/*****************************************
Title
	The Cheapest Palindrome
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, aCost, bCost;
	long long int cost;
	string temp;
	string::iterator itA, itB;
	cin >> T;
	
	while(T--)
	{
		cin >> temp >> aCost >> bCost;
		cost = 0;
		itA = temp.begin();
		itB = temp.end()-1;
		while(itA < itB && cost != -1)
		{
			if(*itA == '/' && *itB != '/')
			{
				if(*itB == 'a')
					cost += aCost;
				else
					cost += bCost;
			}
			else if(*itA != '/' && *itB == '/')
			{
				if(*itA == 'a')
					cost += aCost;
				else
					cost += bCost;
			}
			else if(*itA == *itB && *itA == '/')
			{
				if(aCost < bCost)
					cost += 2*aCost;
				else
					cost += 2*bCost;
			}
			else if(*itA != *itB)
			{
				cost = -1;
			}
			itA++;
			itB--;
		}
		cout << cost << endl;
	}

    return 0;
}
*/
/*****************************************
Title
	Don't Jump 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct Stack
{
	int s[10000], i;
	bool values[10000];
	void Init(int T){
		i = 0;
		for (int i = 1; i < T; i++)
			values[i] = true;
		values[0] = false;
		return;
	}

	int Push(){
		int v = Top()+1;
		while(values[v] == false) v++;
		s[i++] = v;
		return v;
	}

	int Pop(){
		if(Empty())
			return -1;
		i--;
		values[s[i]] = false;
		return s[i];
	}

	int Top(){
		return Empty() ? -1 : s[i-1];
	}

	bool Empty()
	{
		return i==0 ? true : false;
	}

	void Print()
	{
		for (int v = i-1; v > -1; v--)
		{
			cout << s[v] << " ";
		}
		cout << endl;
	}
};

string Solve(string temp, int T)
{
	vector<int> nums;
	int num = 0;
	string internal;
	Stack stack;
	stack.Init(T);
	int mult = 0;
	
	if(temp.length() == 0)
		return "";
	
	for (string::iterator it = temp.end()-1; it > temp.begin(); it--)
	{
		if(*it != ' ')
		{
			num += ((*it)-48)*pow(10, mult++);
		}
		else
		{
			if(num > T) return "-1";
			nums.push_back(num);
			num = 0;
			mult = 0;
		}
	}

	num += ((temp[0])-48)*pow(10, mult++);
	if(num > T) return "-1";
	nums.push_back(num);
	
	for (vector<int>::iterator it = nums.end()-1; it >= nums.begin(); it--)
	{
		if(stack.Top() < *it)
		{
			internal += "C";
			while(stack.Push() < *it) internal += "C";
			if(stack.Top() != *it) return "-1";
			stack.Pop();
			internal += "K";
		}else if(stack.Top() > *it)
		{
			internal += "K";
			while(stack.Pop() > *it) internal += "K";
			if(stack.Top() == -1) return "-1";
		}else
		{
			stack.Pop();
			internal += "K";
		}
	}

	return internal;
}

int main()
{
	int T;
	
	string temp;
	
	cin >> T;
	cin.ignore();
	
	while(getline(cin, temp))
	{
		cout << Solve(temp, T) << endl;
		cin >> T;
		cin.ignore();
	}

    return 0;
}
*/
/*****************************************
Title
	Find Substring
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T, count;
    bool a, b, c;
    string temp;
    string::iterator it, _it;
    
    cin >> T;

    while(T--)
    {
    	cin >> temp;
    	it = temp.begin();
    	count = 0;

    	while(it != temp.end())
    	{
    		_it = it;
			a = 0;
    		b = 0;
    		c = 0;
    		
    		while(_it != temp.end())
    		{
    			if(*_it == 97) a = 1;
    			if(*_it == 98) b = 1;
    			if(*_it == 99) c = 1;

    			if(a && b && c) break;

   				count++;
    			_it++;
    		}
    		it++;
    	}
    	cout << count << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Karan and Strings 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    string temp;
    string::iterator it;
    
    cin >> T;

    while(T--)
    {
    	cin >> temp;
    	it = temp.begin();
    	while(it != temp.end())
    	{
    		cout << *it;
    		while(*it == *(++it));
    	}
    	cout << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Sorted String
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T, alphabet[27], max, min;
    string temp;
    string::iterator it;
    
    cin >> T;

    while(T--)
    {
    	cin >> temp;
    	for (int i = 0; i < 27; ++i)
    		alphabet[i] = 0;

		for (it = temp.begin(); it != temp.end(); it++)
			alphabet[(*it)-97]++;

		min = temp.length();
		max = 0;
		for (int i = 0; i < 27; ++i)
		{
    		if(alphabet[i] > max) max = alphabet[i];
    		if(alphabet[i] < min) min = alphabet[i];
		}
		if(min == 0) min = 1;
		max++;
		while(min != max)
		{
			for (int i = 0; i < 27; ++i)
			{
    			if(alphabet[i] == min)
    			{
    				for (int j = 0; j < min; j++)
    				{
    					cout << (char)(i+97);
    				}
    			}
			}
			min++;
		}    	
		cout << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Marut and Strings
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T, a, A;
    string temp;
    string::iterator it;
    
    cin >> T;
    if(T < 1 || T > 10)
    {
    	cout << "Invalid Test" << endl;
    	return 0;
    }

    while(T--)
    {
    	cin >> temp;
    	a = 0;
    	A = 0;
		
		if(temp.length() > 0 && temp.length() < 101)
		{
			for (it = temp.begin(); it != temp.end(); it++)
			{
				if(*it < 123 && *it > 96) a++;
				if(*it < 91 && *it > 64) A++;
				cout << *it << endl;
			}    	

			if(a == 0 && A == 0)
			{
				cout << "Invalid Input" << endl;
			}else if(a > A)
			{
				cout << A << endl;
			}else
			{
				cout << a << endl;
			}
		}else
		{
			cout << "Invalid Input" << endl;	
		}
    }
    return 0;
}
*/
/*****************************************
Title
	Password
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    string temp;
    vector<string> vec;
    vector<string>::iterator it, _it;

    cin >> T;
    while(T--)
    {
    	cin >> temp;
    	vec.push_back(temp);
    }

    for (it = vec.begin(); it != vec.end(); it++)
    {
    	temp = *it;
    	reverse(temp.begin(), temp.end());
		for (_it = it+1; _it != vec.end(); _it++)
		{
			if(*_it == temp)
			{
				cout << temp.length() << " " << temp[(temp.length()>>1)] << endl;
				break;
			}
		}
    }

    return 0;
}
*/
/*****************************************
Title
	Remove Duplicates
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    bool alphabet[26];
    string str;
    string::iterator it;
    getline(cin, str);

    for (int i = 0; i < 26; ++i)
    	alphabet[i] = 0;

    for (it = str.begin(); it != str.end(); it++)
    {
    	if(alphabet[(*it)-97])
    	{
    		str.erase(it);
    		it--;
    	}else
    	{
    		alphabet[(*it)-97] = 1;	
    	}
    }
    cout << str << endl;
    return 0;
}
*/
/*****************************************
Title
	Count Enemies 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter))
		internal.push_back(tok);

	return internal;
}
int main()
{
    int T, c;
    bool attack;
    string str;
    vector<string> vec;
    vector<string>::iterator it;
    string::iterator _it;
    cin >> T;
    while(T--)
    {
    	cin >> str;
    	vec = split(str, '*');
    	c = 0;
    	for (it = vec.begin(); it != vec.end(); it++)
    	{
    		attack = true;
			for (_it = it->begin(); _it != it->end(); _it++)
	    	{
				if(*_it == 'X')
				{
					attack = false;
					break;
				}
	    	}
	    	if(attack) c += it->length();
    	}
    	cout << c << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	UpUp
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    string str;
    string::iterator it;
    getline(cin, str);

    it = str.begin();
    if(*it != ' ')
    	*it = toupper(*it);

    for (it = str.begin()-1; it != str.end(); it++)
    {
    	if(*(it-1) == ' ' &&  *(it) != ' ')
    		*it = toupper(*it);
    }
    cout << str << endl;
    return 0;
}
*/
/*****************************************
Title
	Nobita and String
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter))
		internal.push_back(tok);

	return internal;
}

int main()
{
    int T;
    string str;
    vector<string> vec;
    vector<string>::iterator itB, itE;
    cin >> T;
    cin.ignore();
    while(T--)
    {
    	getline(cin, str);
    	vec = split(str, ' ');
    	itB = vec.begin();
    	itE = vec.end()-1;

    	while(itB < itE)
    	{
    		swap(*itB, *itE);
    		itB++;
    		itE--;
    	}

		itB = vec.begin();
    	itE = vec.end();    	
    	while(itB != itE)
    	{
    		cout << *itB << " ";
    		itB++;
    	}
    	cout << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Ashish and Binary Matrix
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool Sovle()
{
	int rows, columns;
    vector<string> matrix, _matrix;
    vector<string>::iterator it, _it;
    bool flag;
    cin >> rows >> columns;
    
	matrix.resize(rows);
	_matrix.resize(rows);
    for (int i = 0; i < rows; i++)
    	cin >> matrix[i];

    if(pow(2, columns)-1 < rows)
    	return false;

    _matrix = matrix;

    for (int i = 0; i < rows; i++)
		_matrix[i][0] = 0;

    for (int ignore = 0; ignore < columns; ignore++)
    {

    	flag = true;

    	for (int i = 0; i < rows-1; i++)
	    {
	    	for (int j = i+1; j < rows; j++)
		    {
		    	if(_matrix[i] == _matrix[j])
		    	{
		    		flag = false;
		    		i = rows;
		    		j = rows;
		    	}
		    }
	    }
    	
	    if(flag)
	    	return true;

	    for (int i = 0; i < rows; i++)
	    {
	    	_matrix[i][ignore] = matrix[i][ignore];
	    	_matrix[i][ignore+1] = 0;
	    }
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, rows, columns;
    string str;
    cin >> T;
    
    while(T--)
    {
    	if(Sovle())
    		cout << "Yes" << endl;
    	else
    		cout << "No" << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Palindromes 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

bool isPalindromes(string str)
{
	string::iterator itB = str.begin(), itE = str.end()-1;
	if(str.length() == 1)
		return true;
	while(itB < itE)
	{
		if(*itB++ != *itE--)
			return false;
	}
	return true;
}

bool sameChar(string str)
{
	if(str.length() == 1)
		return false;
	string::iterator itB = str.begin(), itE = str.end()-1;
	while(itB < itE)
	{
		if(*itB++ != *itE--)
			return false;
	}
	if(str.length()%2 != 1)
		return true;
	itB++;
	if(*itB != *itE)
		return false;
	return true;
}

int ssno(string str)
{
	long int N = str.length();

    while(N)
    {
    	for (int i = 0; i <= str.length()-N; i++)
    	{
    		if(!isPalindromes(str.substr(i,N)))
    			return N;
    	}
    	N--;
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;

    if(sameChar(str))
    	cout << 0 << endl;	
    else
    	cout << ssno(str) << endl;

    return 0;
}
*/
/*****************************************
Title
	Xenny and Partially Sorted Strings
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool doSwap(string strA, string strB, int M)
{
	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		if(strA[i] > strB[i])
			flag = true;
	}
	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, K, M, n, newn;
    string temp;
	vector<string> strs;
	cin >> T;

	while(T--)
	{
		cin >> N >> K >> M;
		//strs.resize(N);
		while(strs.begin() != strs.end())
			strs.pop_back();
		n = N;
		while(N--)
		{
			cin >> temp;
			strs.push_back(temp);
		}
		N = n;
		do
		{
			newn = 0;
			for (int i = 1; i < n; i++)
			{
				if(doSwap(strs[i-1], strs[i], M))
				{
					swap(strs[i-1], strs[i]);

					newn = i;
				}
			}
			n = newn;
			cout << "Now:" << endl;
			for (int i = 0; i < N; i++)
				cout << strs[i] << endl;
		}while(n != 0);
		
		cout << strs[K-1] << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	String Division
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

bool StringDivision(string str)
{
	int N = str.length();
	if(N < 4)
		return false;
	if(N > 9)
		return true;

	int l1 = 1, l2 = 1, l3 = 1, l4 = 1;
	string s1, s2, s3, s4;
	while(l1 != N)
	{
		while(l2 != N)
		{
			while(l3 != N)
			{
				while(l4 != N)
				{
					if(l1+l2+l3+l4 == N)
					{
						s1 = str.substr(0, l1);
						s2 = str.substr(l1, l2);
						s3 = str.substr(l1+l2, l3);
						s4 = str.substr(l1+l2+l3);

						if(s1 != s2 && s1 != s3 && s1 != s4 && s2 != s3 && s2 != s4 && s3 != s4)
							return true;
					}
					l4++;
				}
				l4 = 1;
				l3++;
			}
			l3 = 1;
			l2++;
		}
		l2 = 1;
		l1++;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
	string str;
	cin >> T;

	while(T--)
	{
		cin >> str;
		if(StringDivision(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	The Strongest String - 1 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, chr = 122;
	string str, sub;
	cin >> T >> str;

	string::iterator it, _it;
	_it = str.begin();
	while(chr >= 'a')
	{
		it = _it;
		while(it < str.end())
		{
			if(*it == chr)
			{
				sub.push_back((char)chr);
				_it = it;
				break;
			}
			it++;
		}
		chr--;
	}

	cout << sub << endl;
    return 0;
}
*/
/*****************************************
Title
	 Sumit And Rohil 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

class SolveAnagram
{
	//string strA, strB;
	int alphabet[27];
public:
	void InitAlphabet()
	{
		for (int i = 0; i < 27; i++)
		{
			alphabet[i] = 0;
		}
	}

	bool Solve(string a, string b)
	{
		InitAlphabet();
		
		if(a[0] != b[0])
			return false;

		if(a[a.length()-1] != b[b.length()-1])
			return false;

		for (int i = 1; i < a.length()-1; i++)
		{
			alphabet[a[i]-97]++;
			alphabet[b[i]-97]++;
		}

		for (int i = 0; i < 27; i++)
		{
			if(alphabet[i]%2 != 0)
				return false;
		}

		return true;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, c=0;
	SolveAnagram *ana = new SolveAnagram();
	string strA, strB;
	cin >> T;
	T = T>>1;
	while(T--)
	{
		cin >> strA >> strB;
		if(ana->Solve(strA, strB)) c++;
	}
	cout << c << endl;
    return 0;
}
*/
/*****************************************
Title
	Chotu and Palindromic Strings 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
	bool flag;
	string strA, strB, str;
	string::iterator itB, itE;
	cin >> T;
	while(T--)
	{
		cin >> strA >> strB;
		
		str = strA + strB;
		itB = str.begin();
		itE = str.end()-1;
		flag = true;
		while(itB < itE && flag)
		{
			if(*itB != *itE) flag = false;
			itB++;
			itE--;
		}

		if(!flag)
		{
			str = strB + strA;
			itB = str.begin();
			itE = str.end()-1;
			flag = true;
			while(itB < itE && flag)
			{
				if(*itB != *itE) flag = false;
				itB++;
				itE--;
			}			
		}

		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Compiler Version 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin.ignore(' ');
	bool flag;
	string str;
	while(getline(cin, str) != NULL)
	{
		flag = false;
		for (int i = 0; i < str.length()-1; i++)
		{
			if(str[i] == '-' && str[i+1] == '>' && !flag)
			{
				str.erase(i, 1);
				str[i] = '.';
			}
			if(str[i] == '/' && str[i+1] == '/')
			{
				flag = true;
			}
		}
		cout << str << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool desc (int i,int j) { return (i>j); }

int main()
{
	int T, N, M;
	char aux;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str >> N >> M;
		sort(&str[N], &str[M+1], desc);
		cout << str << endl;
	}
    return 0;
}
*/