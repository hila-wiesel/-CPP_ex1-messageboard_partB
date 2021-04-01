#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>


using namespace std;
//using namespace ariel;



namespace ariel{
    void Board::post(unsigned int row, unsigned int col, Direction d, string const &message){
        if (message.empty()){
            return;
        }
        if (this->min_row > row){
                this->min_row = row;
        }
        if (this->min_col > col){
            this->min_col = col;
        }
        if (d == Direction::Horizontal){
            if (this->max_row < row){
                this->max_row = row;
            }
            if (this->max_col < col+message.length()){
                this->max_col = col+message.length();
            }
            for (unsigned int i=0, c=col;  i<message.length(); ++i, ++c){
                this->messages[row][c]=message.at(i);
            }   
        }
        else{
            if (this->max_row < row+message.length()){
                this->max_row = row+message.length();
            }
            if (this->max_col < col){
                this->max_col = col;
            }

            for (unsigned int i=0, r=row; i<message.length(); ++i, ++r){
                this->messages[r][col]=message.at(i);
            } 
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length){
        string ans;
        if (d == Direction::Horizontal){
            for (unsigned int i=0, c=col; i<length; ++i, ++c){
                if(this->messages[row][c] != 0){
                    ans +=this->messages[row][c];
                }
                else{
                    ans += '_';
                }

            }
        }
        else{
            for (unsigned int i=0, r=row; i<length; ++i, ++r){  
                if(this->messages[r][col] != 0){
                    ans +=this->messages[r][col];
                }
                else{
                    ans += '_';
                }
            } 
        }        
        return ans;
    }

    void Board::show(){
        for (unsigned int row = this->min_row;  row <= this->max_row;   ++row){
            for (unsigned int col = this->min_col; col<=this->max_col; ++col){
                if(this->messages[row][col] != 0){
                    cout<<this->messages[row][col];
                }
                else{
                    cout<<'_';
                }
            }
            cout << endl;
        }
    };
}