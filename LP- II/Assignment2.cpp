#include <bits/stdc++.h>
using namespace std;

class node {
private:
    int val;
    int x, y;
    int f, g, h;
    node* parent;
public:
    node() {
        x = 0;
        y = 0;
        f = 0;
        g = 0;
        h = 0;
        val = 0;
        parent = nullptr;
    }

    bool operator<(const node& rhs) const {
        return f > rhs.f;
    }

    friend int aStar();
};


int aStar() {
    int row, col;
    cout << "\nEnter row and col : ";
    cin >> row >> col;
    vector<vector<node>> grid(row, vector<node>(col));
    set<pair<int, int>> closed;
    priority_queue<node> open;
    int dx[4] = { 1,0,0,-1 };
    int dy[4] = { 0,1,-1,0 };

    cout << "\n------------ Map ---------------" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            cout << grid[i][j].val << " ";

        }
        cout << endl;
    }
    while (true) {
        int x, y;
        cout << "Enter cells with obstacles (-1,-1 to end): ";
        cin >> x >> y;
        if (x == -1 || y == -1) {
            break;
        }
        grid[x][y].val = 1;
    }
    cout << "\n------------ New Map ---------------" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << grid[i][j].val << " ";
        }
        cout << endl;
    }
    pair<int, int> src, dst;
    cout << "\nEnter start node : ";
    cin >> src.first >> src.second;
    cout << "\nEnter dst node : ";
    cin >> dst.first >> dst.second;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j].g = abs(i - src.first) + abs(j - src.second);
            grid[i][j].h = abs(i - dst.first) + abs(j - dst.second);
            grid[i][j].f = grid[i][j].g + grid[i][j].h;
        }
    }

    open.push(grid[src.first][src.second]);
    closed.insert(src);

    while (!open.empty()) {
        node current = open.top();
        open.pop();
        int r = current.x;
        int c = current.y;

        if (r == dst.first && c == dst.second) {
            node* path = &grid[r][c];
            while (path != nullptr) {
                cout << "[ " << path->x << " , " << path->y << " ]<---";
                path = path->parent;
            }
            return current.g; // return the cost of the path
        }

        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny].val == 0 && closed.count({ nx,ny }) <= 0) {
                grid[nx][ny].g = current.g + 1; // Update g value
                grid[nx][ny].f = grid[nx][ny].g + grid[nx][ny].h;
                grid[nx][ny].parent = &grid[r][c];
                open.push(grid[nx][ny]);
                closed.insert({ nx,ny });
            }
        }
    }
    return -1; // If no path found
}

int main() {
    int sum = aStar();
    if (sum == -1) {
        cout << "\nNo path Found";
    }
    else {
        cout << "\nLength of path : " << sum;
    }
    return 0;
}

