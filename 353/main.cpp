#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class SnakeGame {
public:
    int width;
    int height;
    int score;
    queue<vector<int>> food;

    vector<vector<int>> snakeBody;
    vector<int> snakeHead;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        snakeBody.push_back({0, 0});
        snakeHead = {0, 0};
        this->width = width;
        this->height = height;
        for (vector<int> f : food) this->food.push(f);
        score = 0;
    }

    bool outOfBound(vector<int> pos) {
        return pos[0] < 0 || pos[0] >= height || pos[1] < 0 || pos[1] >= width;
    }

    bool eatSelf(vector<int> pos) {
        bool ans = false;
        for (int i = 1; i < snakeBody.size(); ++i) {
            if (snakeBody[i][0] == pos[0] && snakeBody[i][1] == pos[1]) ans = true;
        }
        return ans;
    }

    bool containFood(vector<int> pos) {
        if (food.empty()) return false;
        return food.front()[0] == pos[0] && food.front()[1] == pos[1];
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        vector<int> nextPos;
        switch (direction[0]) {
            case 'U':
                nextPos = {snakeHead[0]-1, snakeHead[1]};
                break;
            case 'L':
                nextPos = {snakeHead[0], snakeHead[1] - 1};
                break;
            case 'R':
                nextPos = {snakeHead[0], snakeHead[1] + 1};
                break;
            case 'D':
                nextPos = {snakeHead[0]+1, snakeHead[1]};
                break;
        }
        if (outOfBound(nextPos) || eatSelf(nextPos)) return -1;
        snakeHead = nextPos;
        snakeBody.push_back(nextPos);
        if (containFood(nextPos)) {
            food.pop();
            return ++score;
        } else {
            snakeBody.erase(snakeBody.begin());
            return score;
        }
    }
};

 int main() {

}
