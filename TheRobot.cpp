//The Robot

#include "stdafx.h"
#include <iostream>
#include <stack>
#include<string.h>
using namespace std;

int c[25], n, a, b, i;
stack <int> s[25], aux;

/*
move a onto b: unde a și b sunt numere de blocuri,
pune blocul a peste blocul b după ce returnează toate
blocurile care sunt stivuite deasupra blocurilor a și b la pozițiile lor inițiale.
*/
void move_a_onto_b(int a, int b)
{
	while (s[c[a]].top() != a)
	{
		int vf = s[c[a]].top();
		s[vf].push(vf);
		c[vf] = vf;
		s[c[a]].pop();
	}

	while (s[c[b]].top() != b)
	{
		int vf = s[c[b]].top();
		s[vf].push(vf);
		c[vf] = vf;
		s[c[b]].pop();
	}

	s[c[b]].push(a);
	s[c[a]].pop();
	c[a] = c[b];
}

/*
move a over b: unde a și b sunt numere de blocuri,
pune blocul a în vârful stivei care conține blocul b,
după ce returnează toate blocurile care sunt stocate deasupra lui a in pozitiile lor initiale.
*/
void move_a_over_b(int a, int b)
{
	while (s[c[a]].top() != a)
	{
		int vf = s[c[a]].top();
		s[vf].push(vf);
		c[vf] = vf;
		s[c[a]].pop();
	}

	s[c[b]].push(a);
	s[c[a]].pop();
	c[a] = c[b];
}

/*
pile a onto b: unde a și b sunt numere de blocuri,
mută stiva de blocuri care începe cu blocul a, deasupra blocului b.
Toate blocurile stivuite deasupra blocului b sunt mutate la pozitiile lor
initiale inainte de a le mută pe cele de deasupra blocului a.
Blocurile stocate deasupra blocului a își mențin ordinea atunci când sunt mutate.
*/
void pile_a_onto_b(int a, int b)
{
	while (s[c[b]].top() != b)
	{
		int vf = s[c[b]].top();
		s[vf].push(vf);
		c[vf] = vf;
		s[c[b]].pop();
	}

	while (s[c[a]].top() != a)
	{
		aux.push(s[c[a]].top());
		s[c[a]].pop();
	}

	aux.push(a);
	s[c[a]].pop();
	c[a] = c[b];

	while (!aux.empty())
	{
		s[c[b]].push(aux.top());
		c[aux.top()] = c[b];
		aux.pop();
	}
}

/*
pile a over b: unde a și b sunt numere de blocuri,
mută stiva de blocuri care începe cu blocul a și toate blocurile
care sunt stivuite deasupra blocului a peste stiva de blocuri care îl conține pe blocul b.
*/
void pile_a_over_b(int a, int b)
{
	while (s[c[a]].top() != a)
	{
		aux.push(s[c[a]].top());
		s[c[a]].pop();
	}

	aux.push(a);
	s[c[a]].pop();

	while (!aux.empty())
	{
		s[c[b]].push(aux.top());
		c[aux.top()] = c[b];
		aux.pop();
	}
}

void afisare()
{
	for (int i = 0; i < n; i++)
	{
		cout << i << ":";
		if (s[i].empty())
			cout << endl;
		else
		{
			while (!s[i].empty())
			{
				aux.push(s[i].top());
				s[i].pop();
			}

			while (!aux.empty())
			{
				cout << " " << aux.top();
				aux.pop();
			}
			cout << endl;
		}
	}
}

int main()
{
	cin >> n;
	if (n > 0 && n<25)
		for (i = 0; i < n; i++)
		{
			s[i].push(i);
			c[i] = i;
		}
	char c1[5] = {}, c2[5] = {};
	while (cin >> c1)
	{
		if (strcmp(c1, "quit")==0)
			break;

		cin >> a >> c2 >> b;
		if (a == b || a > n - 1 || b > n - 1 || a < 0 || b < 0||c[a]==c[b]) continue;

		if (a != b && c[a] != c[b])

		{
			if (strcmp(c1, "move")==0 && strcmp(c2, "onto")==0)
				move_a_onto_b(a, b);
			else
				if (strcmp(c1, "move")==0 && strcmp(c2, "over")==0)
					move_a_over_b(a, b);
				else
					if (strcmp(c1, "pile")==0 && strcmp(c2, "onto")==0)
						pile_a_onto_b(a, b);
					else
						if (strcmp(c1, "pile")==0 && strcmp(c2, "over")==0)
							pile_a_over_b(a, b);
		}
	}

	afisare();
	return 0;
}

