#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int initialColour = image[sr][sc];
    int n = image.size(), m = image[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> dirns = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    dfs(image, vis, dirns, sr, sc, color, initialColour);
    return image;
  }

private:
  void dfs(vector<vector<int>> &image, vector<vector<bool>> &vis,
           vector<vector<int>> &dirns, int sr, int sc, int color,
           int initialColour) {
    int n = image.size(), m = image[0].size();
    vis[sr][sc] = true;
    image[sr][sc] = color;
    for (auto &dir : dirns) {
      int x = sr + dir[0];
      int y = sc + dir[1];
      if ((x >= 0 and x < n) and (y >= 0 and y < m) and !vis[x][y] and
          image[x][y] == initialColour) {
        dfs(image, vis, dirns, x, y, color, initialColour);
      }
    }
  }
};
