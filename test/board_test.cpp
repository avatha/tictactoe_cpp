#include "catch.hpp"
#include "../src/board.hpp"

SCENARIO ("Board") {
    vector<char> empty_board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    
    GIVEN("Empty Board") {
        Board board(9);

        WHEN("#getGrid is called"){
            THEN("return an empty grid") {
                REQUIRE(empty_board == board.getGrid());
            }
        }

        WHEN("#getSlot is called for the first slot") {
            THEN("return an empty slot") {
                char empty_slot = ' ';
                REQUIRE(empty_slot == board.getSlot(0));
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 0") {
                REQUIRE(0 == board.countMarker('X'));
            }
        }

        WHEN("#whoseTurn is called") {
            THEN("X always starts first") {
                REQUIRE('X' == board.whoseTurn());
            }
        }

        WHEN("#isFull is called") {
            THEN("returns false") {
                REQUIRE(false == board.isFull());
            }
        }

        WHEN("#validSlots is called") {
            THEN("returns the values from 0 to 8") {
                vector<int> valid_slots = {0, 1, 2, 3, 4, 5, 6, 7, 8};
                REQUIRE(valid_slots == board.validSlots());
            }
        }

        WHEN("#isEquals is called to compare the board to an empty board") {
            THEN("returns true") {
                REQUIRE(true == board.isEquals(empty_board));
            }
        }

        WHEN("#isEquals is called to compare the board to a marked board") {
            THEN("returns false") {
                vector<char> marked_board = {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
                REQUIRE(false == board.isEquals(marked_board));
            }
        }

        WHEN("#isEquals is called to compare the board to a marked board") {
            THEN("returns false") {
                vector<char> O_marked_board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O'};
                REQUIRE(false == board.isEquals(O_marked_board));
            }
        }
    }

    GIVEN("Marked Board with X on the first slot") {
        Board board(9);
        board.fillSlot(0);

        WHEN("#getSlot is called with the first slot") {
            THEN("return X since it was placed on the first slot") {
                REQUIRE('X' == board.getSlot(0));
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 1") {
                REQUIRE(1 == board.countMarker('X'));
            }
        }

        WHEN("#whoseTurn is called") {
            THEN("return O since X just moved") {
                REQUIRE('O' == board.whoseTurn());
            }
        }

        WHEN("#validSlots is called") {
            THEN("return a vector with values from 1 to 8") {
                vector<int> empty_slots = {1, 2, 3, 4, 5, 6, 7, 8};
                REQUIRE(empty_slots == board.validSlots());
            }
        }
    }

    GIVEN("A board that is active") {
        Board active_board(9);
        vector<char> current_board = {'X', 'X', 'X', ' ', ' ', ' ', 'O', 'O', ' '};
        active_board.setGrid(current_board);

        THEN("#countMarker return 3 for X and 2 for O"){
            REQUIRE(3 == active_board.countMarker('X'));
            REQUIRE(2 == active_board.countMarker('O'));
        }

        WHEN("#whoseTurn is called") {
            THEN("return O since X just moved") {
                REQUIRE('O' == active_board.whoseTurn());
            }
        }

        THEN("#validSlots returns the values from 0 to 8") {
            vector<int> valid_slots = {3, 4, 5, 8};
            REQUIRE(valid_slots == active_board.validSlots());
        }
    }

    GIVEN("A full 3x3 board") {
        Board full_board(9);
        vector<char> current_board = {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'};
        full_board.setGrid(current_board);

        WHEN("#getGrid is called") {
            THEN("return the board that it was set too") {
                REQUIRE(current_board == full_board.getGrid());
            }
        }

        WHEN("#countMarker is called") {
            THEN("return 5 for X and 4 for O") {
                REQUIRE(5 == full_board.countMarker('X'));
                REQUIRE(4 == full_board.countMarker('O'));
            }
        }

        WHEN("#isFull is called") {
            THEN("returns true") {
                REQUIRE(true == full_board.isFull());
            }
        }

        WHEN("#validSlots is called") {
            THEN("#returns 0") {
                vector<int> empty_slots = {};
                REQUIRE(empty_slots == full_board.validSlots());
            }
        }
    }
};
