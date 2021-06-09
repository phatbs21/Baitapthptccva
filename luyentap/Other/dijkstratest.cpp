#include <iostream>
#include <vector>

#define MAXN 1001
#define MAXX 999999999

using namespace std;

int A[MAXN][MAXN];
int MinPath[MAXN];
int From[MAXN];
bool Free[MAXN];

int M, N, S, E;

void init()
{
    freopen("DIJKSTRA.INP", "r", stdin);
    freopen("DIJKSTRA.OUT", "w", stdout);

    //Doc file input
    scanf("%d %d %d %d", &N, &M, &S, &E);

    for (int i = 1; i <= M; i++)
    {
        int u, v, p;
        scanf("%d %d %d", &u, &v, &p);
        A[u][v] = A[v][u] = p;
    }

    //Gan duong di ngan nhat = MAXX
    for (int i = 1; i <= N; i++)
        MinPath[i] = MAXX;
    MinPath[S] = 0;
}

void DIJKSTRA()
{
    int g = S, minD;
    do
    {
        g = E;
        for (int i = 1; i <= N; i++)
            if (Free[i] == false && MinPath[g] > MinPath[i])
            {
                g = i;
            }
        Free[g] = true; //Gan nhan cho dinh G co' dinh

        if (MinPath[g] == MAXX || g == E)
            break;

        for (int v = 1; v <= N; v++)
        {
            if (A[g][v] > 0 && !Free[v])
            {
                if (A[g][v] + MinPath[g] < MinPath[v])
                {
                    MinPath[v] = A[g][v] + MinPath[g];
                    From[v] = g;
                }
            }
        }

    } while (true);
}

void TruyVet(int end)
{
    int u = end;
    vector<int> vet;
    while (u != S)
    {
        vet.push_back(u);
        u = From[u];
    }
    vet.push_back(S);
    printf("\nVet tim duoc: ");
    for (int i = vet.size() - 1; i >= 0; i--)
        printf("%3d", vet[i]);
    printf("\n");
}

void print()
{
    if (MinPath[E] == MAXX)
        printf("Khong co duong di!");
    else
        printf("Duong di ngan nhat la: %d", MinPath[E]);
    for (int i = 1; i <= N; i++)
    {
        if (MinPath[i] != 1)
            cout << MinPath[i] << " ";
        else
            cout << "-1 ";
    }
}

main()
{
    init();
    DIJKSTRA();
    print();
}
