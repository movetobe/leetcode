

#define TWEET_NAME_LEN 1024
#define TWEET_OPERATE_NUM 10240
typedef struct {
	char tweetName[TWEET_NAME_LEN];
	int times[TWEET_OPERATE_NUM];
	int times_num;
} TweetRecord;
typedef struct {
	TweetRecord records[TWEET_OPERATE_NUM];   
	int records_num;
} TweetCounts;


TweetCounts* tweetCountsCreate() {
    TweetCounts *obj = calloc(1, sizeof(TweetCounts));

	return obj;
}

void tweetCountsRecordTweet(TweetCounts* obj, char * tweetName, int time) {
	int i = 0;

	for (i = 0; i < obj->records_num; i++) {
		if (strcmp(obj->records[i].tweetName, tweetName) == 0) {
			obj->records[i].times[obj->records[i].times_num] = time;
			obj->records[i].times_num++;
		} else {
			memcpy(obj->records[obj->records_num].tweetName, tweetName, strlen(tweetName));
			obj->records[obj->records_num].times[obj->records[obj->records_num].times_num] = time;
			obj->records_num++;
			obj->records[obj->records_num].times_num++;
		}
	}
}

int* tweetCountsGetTweetCountsPerFrequency(TweetCounts* obj, char * freq, char * tweetName, int startTime, int endTime, int* retSize) {
	int delta = 0;
	int i = 0, j = 0;
	int *count = calloc(1, sizeof(int) * TWEET_OPERATE_NUM);

	*retSize = 0;

	if (strcmp(freq, "minute") == 0) {
		delta = 60;
	} else if (strcmp(freq, "hour") == 0) {
		delta = 3600;
	} else if (strcmp(freq, "day") == 0) {
		delta = 86400;
	} else (
		return NULL;
	)

	for (i = 0; i < obj->records_num; i++) {
		if (strcmp(obj->records[i].tweetName, tweetName) == 0) {
			break;
		}
	}

	if (i >= obj->records_num) {
		return NULL;
	}

	TweetRecord *r = (obj->records[i]);
	for (i = 0; i < r->times_num; i++) {
		for (j = 0; j <= (endTime / delta); j++) {
			if ((r->time[i] >= (startTime + j * delta)) && (r->time[i] <= min(endTime, startTime + (j + 1) * delta))) {
				count[j]++;
			}
		}
	}
	*retSize = endTime / delta + 1;

	return count;
}

void tweetCountsFree(TweetCounts* obj) {
    
}

/**
 * Your TweetCounts struct will be instantiated and called as such:
 * TweetCounts* obj = tweetCountsCreate();
 * tweetCountsRecordTweet(obj, tweetName, time);
 
 * int* param_2 = tweetCountsGetTweetCountsPerFrequency(obj, freq, tweetName, startTime, endTime, retSize);
 
 * tweetCountsFree(obj);
*/
