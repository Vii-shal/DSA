// k Knights

#include<iostream>
#include<vector>
using namespace std;

bool canWePlace(vector<vector<char>> &grid, int i, int j) {
    if (i - 1 >= 0 and j - 2 >= 0 and grid[i - 1][j - 2] == 'K') return false;
    if (i - 1 >= 0 and j + 2 < grid[0].size() and grid[i - 1][j + 2] == 'K') return false;
    if (i - 2 >= 0 and j - 1 >= 0 and grid[i - 2][j - 1] == 'K') return false;
    if (i - 2 >= 0 and j + 1 < grid[0].size() and grid[i - 2][j + 1] == 'K') return false;
    return true;
}

void knights(vector<vector<char>> &grid, int k, int i, int j) {
    if (k == 0) {
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                cout << grid[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;  // Separate different solutions with a blank line
        return;
    }

    if (j == grid[0].size()) {
        knights(grid, k, i + 1, 0);
        return;
    }
    if (i == grid.size()) {
        return;
    }

    if (canWePlace(grid, i, j)) {
        grid[i][j] = 'K';
        knights(grid, k - 1, i, j + 1);
        grid[i][j] = '.'; // Revert the change after recursive call
    }

    knights(grid, k, i, j + 1); // Skip placing a knight in this cell
}

int main() {
    int m = 3, n = 3, k = 5;
    vector<vector<char>> grid(m, vector<char>(n, '.'));
    knights(grid, k, 0, 0);
    return 0;
}
