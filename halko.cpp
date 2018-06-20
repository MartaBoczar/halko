#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <stdio.h>      
#include <stdlib.h> 

using namespace std;

map<char, int> mapofletters()
{
	map<char, int>mapofletters;
	mapofletters['a'] = 0;
	mapofletters['b'] = 0;
	mapofletters['c'] = 0;
	mapofletters['d'] = 0;
	mapofletters['e'] = 0;
	mapofletters['f'] = 0;
	mapofletters['g'] = 0;
	mapofletters['h'] = 0;
	mapofletters['i'] = 0;
	mapofletters['j'] = 0;
	mapofletters['k'] = 0;
	mapofletters['l'] = 0;
	mapofletters['m'] = 0;
	mapofletters['n'] = 0;
	mapofletters['o'] = 0;
	mapofletters['p'] = 0;
	mapofletters['r'] = 0;
	mapofletters['s'] = 0;
	mapofletters['t'] = 0;
	mapofletters['u'] = 0;
	mapofletters['v'] = 0;
	mapofletters['w'] = 0;
	mapofletters['x'] = 0;
	mapofletters['y'] = 0;
	mapofletters['z'] = 0;

	return mapofletters;
}
map<char, double> fofletters()
{
	map<char, double>fofletters;
	fofletters['a'] = 0.0;
	fofletters['b'] = 0.0;
	fofletters['c'] = 0.0;
	fofletters['d'] = 0.0;
	fofletters['e'] = 0.0;
	fofletters['f'] = 0.0;
	fofletters['g'] = 0.0;
	fofletters['h'] = 0.0;
	fofletters['i'] = 0.0;
	fofletters['j'] = 0.0;
	fofletters['k'] = 0.0;
	fofletters['l'] = 0.0;
	fofletters['m'] = 0.0;
	fofletters['n'] = 0.0;
	fofletters['o'] = 0.0;
	fofletters['p'] = 0.0;
	fofletters['r'] = 0.0;
	fofletters['s'] = 0.0;
	fofletters['t'] = 0.0;
	fofletters['u'] = 0.0;
	fofletters['v'] = 0.0;
	fofletters['w'] = 0.0;
	fofletters['x'] = 0.0;
	fofletters['y'] = 0.0;
	fofletters['z'] = 0.0;

	return fofletters;
}
void languagefr(string source)
{

	string src = source + ".txt";
	string frq = "fr" + src;
	char character;
	double counter = 0;
	map<char, int>language = mapofletters();
	map<char, int>::iterator it;
	fstream fin(src, fstream::in);
	while (fin >> noskipws >> character)
	{
		for (it = language.begin(); it != language.end(); ++it)
		{
			if (it->first == character)
			{
				it->second++;
				counter++;
			}
		}
		
	}


	double tmp;
	map<char, double>languagefr = fofletters();
	map<char, double>::iterator ft;
	for (it = language.begin(); it != language.end(); ++it)
	{
		for (ft = languagefr.begin(); ft != languagefr.end(); ++ft)
		{
			if (it->first == ft->first)
			{
				tmp = it->second;
				ft->second = (tmp / counter) * 100;
			}
		}
	}

	ofstream frplik(frq);

	for (ft = languagefr.begin(); ft != languagefr.end(); ++ft)
	{
		frplik << ft->first << " " << ft->second << endl;

	}

	frplik.close();

}
map<char, double> rfrequency(string source)
{
	source = "fr" + source + ".txt";
	char character;
	int counter = 1;
	string check = "";
	double tmp;
	map<char, double>frequency;
	map<char, double>::iterator frq;
	fstream txt(source, fstream::in);

	while (txt >> noskipws >> character)
	{
		if (character != '\n')
		{
			if (counter == 1)
			{
				frequency.insert(pair<char, double>(character, 0));
				frq = frequency.find(character);
				counter++;
			}
			else if (counter == 2)
			{
				counter++;
			}
			else if (counter == 3)
			{
				check.push_back(character);
			}
		}
		else
		{
			tmp = atof(check.c_str());
			frq->second = tmp;
			check = "";
			counter = 1;
		}
	}

	return frequency;
}

int frequencycheck(map<char, double>testing, map<char, double>check)
{
	map<char, double>::iterator ts;
	map<char, double>::iterator ch;
	int counter=0;
	
	for (ts = testing.begin(); ts != testing.end(); ++ts)
	{
		for (ch = check.begin(); ch != check.end(); ++ch)
		{
			if ((ts->first) == (ch->first))
			{
				double tmpt = ts->second;
				double tmpc = ch->second;
				double tmpm = tmpc - 0.05;
				double tmpp = tmpc + 0.05;
				if ((tmpm < tmpt) && (tmpt < tmpp))
				{
					counter++;
				}
			}
		}
		
	}
	return counter;

}

int main()
{
	languagefr("french");
	languagefr("english");
	languagefr("spanish");
	languagefr("polish");
	map<char, double> frenchfrequency = rfrequency("french");
	map<char, double> englishfrequency = rfrequency("english");
	map<char, double> spanishfrequency = rfrequency("spanish");
	map<char, double> polishfrequency = rfrequency("polish");

	cout << "wpisz nazwe tekstu, ktorego jezyk chcesz sprawdzic" << endl;
	string tekst;
	getline(cin, tekst);

	languagefr(tekst);
	map<char, double>test = rfrequency(tekst);
	int frfrq = frequencycheck(test, frenchfrequency);
	int egfrq = frequencycheck(test, frenchfrequency);
	int spfrq = frequencycheck(test, spanishfrequency);
	int plfrq = frequencycheck(test, polishfrequency);

	if ((frfrq > egfrq) && (frfrq > spfrq) && (frfrq > plfrq))
		cout << "najprawdopodobniej jest to tekst w jezyku francuskim." << endl;
	else if ((egfrq > frfrq) && (egfrq > spfrq) && (egfrq > plfrq))
		cout << "najprawdopodobniej jest to tekst w jezyku angielskim." << endl;
	else if ((spfrq > frfrq) && (spfrq > egfrq) && (spfrq > plfrq))
		cout << "najprawdopodobniej jest to teskt w jezyku hiszpanskim." << endl;
	else if ((plfrq > frfrq) && (plfrq > egfrq) && (plfrq > spfrq))
		cout << "najprawdopodobniej jest to tekst w jezyku polskim" << endl;

	system("pause");

	return 0;
}