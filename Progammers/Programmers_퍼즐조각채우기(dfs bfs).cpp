//���α׷��ӽ�
//https://school.programmers.co.kr/learn/courses/30/lessons/84021
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void print_table(vector<vector<int>> m)
{
    int length = m.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
}
void print_cp(vector<pair<int, int>>& cp_vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        int judge = 0;
        for (int j = 0; j < n; j++) {
            for (auto p : cp_vec) {
                if (p.X == i && p.Y == j)
                {
                    cout << 1;
                    judge = 1;
                }

            }
            if (judge == 1)
            {
                judge = 0;
            }
            else
                cout << 0;
        }
        cout << '\n';
    }
}

void rotate(vector<vector<int>>& table)
{
    int length = table.size();
    vector<vector<int>> temp(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            temp[(length - 1) - j][i] = table[i][j];

    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            table[i][j] = temp[i][j];


}


void dfs(int x, int y, vector<vector<int>>& table, vector<pair<int, int>>& vec)
{
    if (x < 0 || x >= table.size() || y < 0 || y >= table.size())return;
    if (table[x][y] == 0)return;
    if (table[x][y] == 2)return;
    vec.push_back({ x,y });
    table[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        dfs(nx, ny, table, vec);
    }
}
//dfs�� ���� ���� �ϳ��� ��ǥ�� ��ȸ�ϸ鼭 �����ϱ�
vector<vector<pair<int, int>>> get_piece(vector<vector<int>>& table)
{
    vector<vector<pair<int, int>>> pieces;
    int n = table.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 1)
            {
                vector<pair<int, int>>vec;
                dfs(i, j, table, vec);
                pieces.push_back(vec);
            }
        }
    }
    //dfs��ȸ�ϸ鼭 2�� �湮ó���Ѱ��� ������� �ǵ���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] == 2)
            {
                table[i][j] = 1;
            }
        }
    }
    return pieces;
}
//������ �� �´� ���簢�� ��ǥ ã��
vector<int> get_box(vector<pair<int, int>>& vec)
{
    int minx = 50, miny = 50, maxx = 0, maxy = 0;
    for (auto p : vec)
    {
        minx = min(minx, p.X);
        maxx = max(maxx, p.X);

        miny = min(miny, p.Y);
        maxy = max(maxy, p.Y);

    }
    return { minx,miny,maxx,maxy };
}
//������ game_board ���� ��ȸ�ϸ鼭 ���� ��Ģ�� ���� �´��� Ȯ��
bool is_fit(vector<vector<int>>& game_board, vector<vector<int>>& table, vector<pair<int, int>> vec, int plusr, int plusc)
{
    int n = game_board.size();//game_board
    int length = vec.size();//������ũ��
    vector<pair<int, int>> cp(length);

    copy(vec.begin(), vec.end(), cp.begin());
    for (int i = 0; i < length; i++)
    {
        cp[i].first += plusr;
        cp[i].second += plusc;
    }
    int cnt = 0;
    cout << "r: " << plusr << " c:" << plusc << '\n';
    print_cp(cp, n);
    for (auto p : cp) {
        if (game_board[p.X][p.Y] == 0)
        {
            //cout << p.X << " " << p.Y << '\n';
            cnt++;
        }

    }
   //cout << "cnt: " << cnt << "size: " << length << '\n';
    
    if (cnt == length)
    {
        //������ game_board�� ���� ���� 
        for (auto p : cp)
        {
            int nx = p.X;
            int ny = p.Y;
            game_board[nx][ny] = 1;
        }
        for (auto p : cp)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = p.X + dir[i][0];
                int ny = p.Y + dir[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                //cout << "nx: " << nx << " ny: " << ny << '\n';
                //������ ���� �� gameboard�� ���� ������ ��ĭ�� ���� �� Ȯ��
                if (game_board[nx][ny] == 0)
                {
                    for (auto p : cp)
                    {
                        int nx = p.X;
                        int ny = p.Y;
                        game_board[nx][ny] = 0;
                    }
                    return false;
                }
                    
            }
        }
    }
    else
        return false;


    return true;
}
void find(vector<vector<int>>& game_board, vector<vector<int>>& table, vector<pair<int, int>> p_vec,vector<pair<int, int>> cp_vec, int& answer,int diffx,int diffy) {
    for (int r = 0; r <= diffx; r++) {
        for (int c = 0; c <= diffy; c++) {
            if (is_fit(game_board, table, cp_vec, r, c))
            {
                //print_cp(cp_vec, n);

                answer += cp_vec.size();
                //���� �پ��� table �湮ó��
                for (auto& it : p_vec)
                {
                    table[it.X][it.Y] = 0;
                }
                //print_table(table);
                cout << "ans: " << answer << '\n';
                //�ٷ� �������ͼ� ������ �ٸ� ��ġ�� �� �Ұ� �ϰ� ��
                return;
            }

        }
    }
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = table.size();
     for (int rot = 0; rot < 4; rot++)
    {
    rotate(table);
    //cout << "ȸ����\n";
    //print_table(table);
    //cout << '\n';
    vector<vector<pair<int, int>>> pieces = get_piece(table);
    for (auto p_vec : pieces) {

        vector<int> box = get_box(p_vec);
        int minx = box[0], miny = box[1], maxx = box[2], maxy = box[3];
        int w =maxx - minx + 1;
        int h =maxy - miny + 1;
        int diffx = n - w;
        int diffy = n - h;
        vector<pair<int, int>> cp_vec(p_vec.size());
        copy(p_vec.begin(), p_vec.end(), cp_vec.begin());
        for (auto &p : cp_vec) {
            p.X -= minx;
            p.Y -= miny;
        }
       // cout << "minx: " << minx << "miny: " << miny << '\n';
        //cout << "diffx: " << diffx << "diffy: " << diffy << '\n';
        //todo isfit ->true game_board ������ �ٲ����
        find(game_board, table, p_vec, cp_vec, answer, diffx, diffy);

        
    }

    }
     cout << "final_ans: " << answer << '\n';
    return answer;
}

void main()
{
    //vector<vector<int>> game_board, vector<vector<int>> table
    vector<vector<int>> game_board = { {1,1,0,0,1,0} ,{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0} };
    vector<vector<int>> table = { {1,0,0,1,1,0} ,{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0} };
    solution(game_board, table);
}