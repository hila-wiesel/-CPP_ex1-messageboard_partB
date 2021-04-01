#include <string>
#include <map>
#include "Direction.hpp"
#include <climits>

namespace ariel{
    class Board{

        private:
        std::map<unsigned int, std::map<unsigned int, char>> messages;
        unsigned int min_row=UINT_MAX;
        unsigned int min_col=UINT_MAX;

        unsigned int max_row=0;
        unsigned int max_col=0;

        public:

        Board(){}
        ~Board(){}
        
        void post(unsigned int row,unsigned int col, Direction d, std::string const &message);
        std::string read(unsigned int row, unsigned int  col, Direction d, unsigned int length);
        void show();
    };

}