/*
Jin Ge Jin Qu [h]ao

(If you smiled when you see the title, this problem is for you ^_^)

For those who don¡®t know KTV, see: http://en.wikipedia.org/wiki/Karaoke_box

There is one very popular song called Jin Ge Jin Qu(¾¢¸è½ðÇú). It is a mix of 37 songs, and is extremely long (11 minutes and 18 seconds)[1].

Why is it popular? Suppose you have only 15 seconds left (until your time is up), then you should select another song as soon as possible, because the KTV will not crudely stop a song before it ends (people will get frustrated if it does so!). If you select a 2-minute song, you actually get 105 extra seconds! ....and if you select Jin Ge Jin Qu, you¡®ll get 663 extra seconds!!!

Now that you still have some time, but you¡®d like to make a plan now. You should stick to the following rules:

Don¡®t sing a song more than once (including Jin Ge Jin Qu).
For each song of length t, either sing it for exactly t seconds, or don¡®t sing it at all.
When a song is finished, always immediately start a new song.
Your goal is simple: sing as many songs as possible, and leave KTV as late as possible (since we have rule 3, this also maximizes the total lengths of all songs we sing) when there are ties.

Input

The first line contains the number of test cases T(T<=100). Each test case begins with two positive integers n,t(1<=n<=50, 1<=t<=109), the number of candidate songs (BESIDES Jin Ge Jin Qu) and the time left (in seconds). The next line contains n positive integers, the lengths of each song, in seconds. Each length will be less than 3 minutes[2]. It is guaranteed that the sum of lengths of all songs (including Jin Ge Jin Qu) will be strictly larger than t.

Output

For each test case, print the maximum number of songs (including Jin Ge Jin Qu), and the total lengths of songs that you¡®ll sing.

Sample Input

2
3 100
60 70 80
3 100
30 69 70
Output for the Sample Input

Case 1: 2 758
Case 2: 3 777
*/
#include <iostream>
#include <cstring> 
using namespace std;

const int MAXSIZE = 180*50;

int main()
{
	int n, t;
	int time[MAXSIZE];
	int dp[MAXSIZE];

	int kase = 0;
	cin >> kase;
	for(int i = 1; i <= kase; i++){
		memset(time, 1000000, sizeof(time));
		memset(dp, -1, sizeof(dp));
		cin >> n >> t;
		while(n--){
			int ti;
			cin >> ti;
			if(dp[1] == -1){
				for(int i = t; i >= 0; i--){
					if(i >= ti){
						dp[i] = 1;
						time[i] = ti;
					}
					else{
						dp[i] = 0;
						time[i] = 0;
					}
				}
			}
			else{
				for(int i = t; i >= 0; i--){
					if(i > ti){
						if(dp[i-ti]+1 > dp[i]){
							dp[i] = dp[i-ti]+1;
							time[i] = time[i-ti] + ti;
						}
						if(dp[i-ti]+1 == dp[i] && time[i-ti]+ti>time[i]){
							time[i] = time[i-ti] + ti;
						}
					}
				}
			}
		}
		cout << "case " << i << ": " << dp[t] + 1 << ' ' << time[t-1]+678 << "\n";
	}

	return 0;
}
