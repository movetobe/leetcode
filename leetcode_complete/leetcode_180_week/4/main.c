#define MIN(a, b) ((a) < (b) ? (a) : (b))
long perf(int n, int *speed, int *effi, int *visited, int k, int now_speed, int now_effi)
{
    int i;
    int max_perf = 0, p, max_index;

    if (k == 0) {
        return now_speed * now_effi;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] || (speed[i] * effi[i] - now_speed * (now_effi - effi[i]) <= 0)) {
            continue;
        }
        visited[i] = 1;
        p = perf(n, speed, effi, visited, k - 1, now_speed + speed[i], MIN(now_effi, effi[i]));
        if (p > max_perf) {
            max_index = i;
        }
        visited[i] = 0;
    }
    return ((now_speed + speed[max_index]) * MIN(now_effi, effi[max_index]));
}
int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k)
{
    int i;
    int maxs = 0, mine = 0;
    int *visited = calloc(1, sizeof(int) * n);
    return perf(n, speed, efficiency, visited, k, speed[0], efficiency[0]);
}