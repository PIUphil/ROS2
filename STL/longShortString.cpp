#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main()
{
	vector<string> words;
	vector<int> word_len;

	string word;
	while (cin >> word) {
		words.push_back(word);
	}

	string longest = words[0];
	string shortest = words[0];

	for (vector<string>::size_type i=1; i!=words.size(); i++) {
//	for (int i=1; i!=words.size(); i++) {
		if (longest.size() < words[i].size())
			longest = words[i];
		if (shortest.size() > words[i].size())
			shortest = words[i];
	}


	cout << "longest word : " << longest << endl;
	cout << "shortest word : " << shortest << endl;

	return 0;
}
