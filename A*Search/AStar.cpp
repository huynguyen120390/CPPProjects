#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;
using std::sort;

enum class State {kEmpty, kObstacle,kClosed,kPath};
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}
// TODO: Write the Heuristic function here.
int Heuristic(int x1, int x2, int y1, int y2){
    return abs(x1-x2) + abs(y1-y2);
}
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

bool CheckValidCell(int x, int y, vector<vector<State>> grid){
  	int rowNum = grid.size();
  	int colNum = grid[0].size();
  	if(x >= rowNum || y >= colNum){
    	return false;
    }
    if (grid[x][y] != State::kClosed && grid[x][y] != State::kObstacle){
        return true;
    }
    return false;
}


// TODO: Write the Search function stub here.
vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]){
    vector<vector<int>> open{};
    int g = 0;
    int x_init = init[0];
    int y_init = init[1];
    int x_goal = goal[0];
    int y_goal = goal[1];
    int h = Heuristic(x_init,y_init,x_goal,y_goal);
    AddToOpen(x_init,y_init,g,h,open,grid);
    while(open.size() > 0){
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x_init = current[0];
        y_init = current[1];
        grid[x_init][y_init] = State::kPath;
        if (x_init == x_goal && y_init == y_goal){
            return grid;
        }

    }

    cout << "No path found!" << "\n";
    return std::vector<vector<State>>{};
}


void ExpandNeighbors(vector<int> current, vector<vector<int>> *open, vector<vector<State>> grid, int goal[2]){
    int x = current[0];
    int y = current[1];
    int g = current[2] + 1;
    int goal_x = goal[0];
    int goal_y = goal[1];
    int neighbor_x, neighbor_y;
    int h;
    vector<int> neighborNode;
    for(int r = 0; r < 4; r++){
        neighbor_x = delta[r][0];
        neighbor_y = delta[r][1];
        if (CheckValidCell(neighbor_x,neighbor_y,grid)){
            h = Heuristic(neighbor_x,neighbor_y,goal_x,goal_y);
            AddToOpen(neighbor_x,neighbor_y,g,h,*open,grid);
        }
    }
}


// TODO: Write the AddToOpen function here.
void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &open, vector<vector<State>> &grid){
    vector<int> node = {x,y,g,h};
    open.push_back(node);
    grid[x][y] = State::kClosed;

}


bool Compare(vector<int> node1, vector<int> node2){
    int f1 = node1[2] + node1[3];
    int f2 = node2[2] + node2[3];

    if (f1 > f2){
        return true;
    }else{
        return false;
    }
}



string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}


void PrintBoard(const vector<vector<State>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}


int main() {
  // TODO: Declare "init" and "goal" arrays with values {0, 0} and {4, 5} respectively.
  auto board = ReadBoardFile("1.board");
  // TODO: Call Search with "board", "init", and "goal". Store the results in the variable "solution".
  // TODO: Change the following line to pass "solution" to PrintBoard.
  PrintBoard(board);
}
