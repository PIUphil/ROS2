#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//using namespace std;


int main()
{
	vector<string> words;
	vector<int> counts;

	string word;
	while (cin >> word) {
		vector<string>::size_type i;
		for ( i=0 ; i!=words.size() ; ++i) {
			if (word == words[i])
				break;	
		}

		if (i== words.size()) {
			words.push_back(word);
			counts.push_back(1);
		} else {
			++counts[i];
		}
	}

	for (vector<string>::size_type i=0 ; i!=words.size() ; ++i)
		cout << words[i] << " : " << counts[i] <<endl;

	return 0;
}


/*
butter

Smooth like butter, like a criminal undercover
Gon' pop like trouble breaking into your heart like that (ooh)
Cool shade, stunner, yeah, I owe it all to my mother
Hot like summer, yeah, I'm making you sweat like that (break it down)
Ooh, when I look in the mirror
I'll melt your heart into two
I got that superstar glow, so
Ooh (do the boogie, like)
*/

/*
Side step, right-left, to my beat
High like the moon, rock with me, baby
Know that I got that heat
Let me show you 'cause talk is cheap
Side step, right-left, to my beat
Get it, let it roll
Smooth like butter, pull you in like no other
Don't need no Usher to remind me you got it bad
Ain't no other that can sweep you up like a robber
Straight up, I (got ya)
Making you fall like that (break it down)
Ooh, when I look in the mirror
I'll melt your heart into two
I got that superstar glow, so
Ooh (do the boogie, like)
Side step, right-left, to my beat
High like the moon, rock with me, baby
Know that I got that heat
Let me show you 'cause talk is cheap
Side step, right-left, to my beat
Get it, let it roll
Get it, let it roll
Get it, let it roll
Ice on my wrist, I'm that nice guy
Got that right body and that right mind
Rolling up to party, got the right vibe
Smooth like (butter), hate us (love us)
Fresh, boy, pull up and we lay low
All the players get moving when the bass low
Got ARMY right behind us when we say so
Let's go
Side step, right-left, to my beat (right-left, to my beat)
High like the moon, rock with me, baby
Know that I got that heat
Let me show you 'cause talk is cheap (you know that talk is cheap)
Side step, right-left, to my beat
Get it, let it roll
Smooth like (butter), cool shade (stunner)
And you know we don't stop
Hot like (summer), ain't no (bummer)
You'll be like, "Oh my God"
We gon' make you rock, and you say (yeah)
We gon' make you bounce, and you say (yeah)
Hotter? Sweeter! Cooler? Butter!
Get it, let it roll
*/
