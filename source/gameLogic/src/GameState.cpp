#include <zconf.h>
#include <array>
#include "GameState.h"

bool GameState::gameOver() {
    return false;
}

/*
 * TIC TAC TOE
 *
 * Game
 * - Players
 * - Board
 * - - doMove
 * - - hasWin
 * - - isDraw
 * - Current Player
 */


enum Player : u_char {
    Player_X = 'X',
    PLAYER_O = 'O'
};


/*
 * A Board! Holds state, and provides mutation funcs
 * to make player moves.
 *
 * The board is laid out from the top left corner,
 * with x as right displacement and y as down displacement.
 *
 * TODO: Iterate more stylishly
 * TODO: Still hardcoded to 3.
 */
class Board {

    static const int SIZE = 3;
    std::array<std::array<char, SIZE>, SIZE> m_board;

public:
    /**
     * Do a move on the board.
     *
     * @param x horizontal displacement from top left
     * @param y vertical displacement from top left
     * @return  true if move was legal and the board has been
     * updated; false otherwise
     */
    bool doMove(Player player, int x, int y) {
        if (m_board[x][y]) {
            return false; // A player has already played here!
        }

        m_board[x][y] = player; // enum autocast to char :D
        return true;
    }
    /**
     * @return a player if they won, or NULL- however you do that
     */
    bool hasWin(Player p) {
        // Check rows and cols
        for (int i = 0; i < SIZE; i++) {
            if (checkCol(p, i)) return true;
            if (checkRow(p, i)) return true;
        }
        // Check diagonal: top left
        checkDiagonal(p, true);
        checkDiagonal(p, false);
    }
    bool isDraw() {
        for (int x = 0; x < SIZE; x++) {
            for (int y = 0; y < SIZE; y++) {
                if (!m_board[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool checkCol(Player p, int col) {
        for (int y = 0; y < SIZE; y++) {
            if (m_board[col][y] != p) {
                return false;
            }
        }
        return true;
    }

    bool checkRow(Player p, int row) {
        for (int x = 0; x < SIZE; x++) {
            if (m_board[x][row] != p) {
                return false;
            }
        }
        return true;
    }

    bool checkDiagonal(Player p, bool lowToHigh) {
        if (lowToHigh) {
            for (int i = 0; i < SIZE; i++) {
                if (m_board[i][i] != p) {
                    return false;
                }
            }
        } else {
            for (int i = SIZE; i > 0; i--) {
                if (m_board[i][i] != p) {
                    return false;
                }
            }
        }
        return true;
    }
};

