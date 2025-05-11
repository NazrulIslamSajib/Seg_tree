using namespace std;
#include <bits/stdc++.h>
const int MAXS =1e6+10;
string arr[MAXS];
const int MAXC = 26;
int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];
unordered_map<int,int>mp;
///Aho Corasick algoritm
///multiple string er jonno lage eta
///https://cses.fi/problemset/task/2103
int buildMatchingMachine(int k)
{
	memset(out, 0, sizeof out);
	memset(g, -1, sizeof g);
	int states = 1;
	for (int i = 0; i < k; ++i)
	{
		const string &word = arr[i];
		int currentState = 0;
		for (int j = 0; j < word.size(); ++j)
		{
			int ch = word[j] - 'a';
			if (g[currentState][ch] == -1)
				g[currentState][ch] = states++;

			currentState = g[currentState][ch];
		}
		out[currentState] |= (1 << i);
	}
	for (int ch = 0; ch < MAXC; ++ch)
		if (g[0][ch] == -1)
			g[0][ch] = 0;
	memset(f, -1, sizeof f);
	queue<int> q;
	for (int ch = 0; ch < MAXC; ++ch)
	{
		if (g[0][ch] != 0)
		{
			f[g[0][ch]] = 0;
			q.push(g[0][ch]);
		}
	}
	while (q.size())
	{
		int state = q.front();
		q.pop();
		for (int ch = 0; ch < MAXC; ++ch)
		{
			if (g[state][ch] != -1)
			{
				int failure = f[state];
				while (g[failure][ch] == -1)
					failure = f[failure];

				failure = g[failure][ch];
				f[g[state][ch]] = failure;

				out[g[state][ch]] |= out[failure];
				q.push(g[state][ch]);
			}
		}
	}

	return states;
}
int findNextState(int currentState, char nextInput)
{
	int answer = currentState;
	int ch = nextInput - 'a';
	while (g[answer][ch] == -1)
		answer = f[answer];

	return g[answer][ch];
}
void searchWords(int k, string text)
{
	buildMatchingMachine(k);
	int currentState = 0;
	for (int i = 0; i < text.size(); ++i)
	{
		currentState = findNextState(currentState, text[i]);
		if (out[currentState] == 0)
			continue;
		for (int j = 0; j < k; ++j)
		{
			if (out[currentState] & (1 << j))
			{
                mp[j]++;
			}
		}
	}
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    for(int j=1;j<=tt;j++)
    {
    mp.clear();
    int k;
    cin>>k;
	string text;
	cin>>text;
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
	searchWords(k,text);
	cout<<"Case "<<j<<":"<<endl;
	for(int i=0;i<k;i++)
    {
        cout<<mp[i]<<endl;
    }
    }
	return 0;
}
