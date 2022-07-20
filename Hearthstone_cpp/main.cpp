
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "card.h"
#include "axe.h"
#include "dog.h"
#include "candle.h"
#include "ninja.h"
#include "panther.h"
#include "wizard.h"
#include "spider.h"
#include "wasp.h"
#include "soldier.h"
#include "sword.h"
#include "snake.h"

using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);
void getPlayerAction(Board&, Board&);

int main(int argc, char * argv[]){
    srand(time(0));
    int turn = 1;
    
    int playerFirst = rand() % 2;                                               
    
    Board pb;
    for (int i = 0; i < 2; i++) {
        pb.addToDeckList(new Dog);
        pb.addToDeckList(new Candle);
        pb.addToDeckList(new Ninja);
        pb.addToDeckList(new Panther);
        pb.addToDeckList(new Wizard);
        pb.addToDeckList(new Spider);
        pb.addToDeckList(new Wasp);
        pb.addToDeckList(new Soldier);
        pb.addToDeckList(new Sword);
        pb.addToDeckList(new Snake);
    }
    
    pb.shuffleDeck();
    pb.draw(5);
    
    // Set up opponent board
    Board ob;
    for (int i = 0; i < 2; i++) {
        ob.addToDeckList(new Dog);
        ob.addToDeckList(new Candle);
        ob.addToDeckList(new Ninja);
        ob.addToDeckList(new Panther);
        ob.addToDeckList(new Wizard);
        ob.addToDeckList(new Spider);
        ob.addToDeckList(new Wasp);
        ob.addToDeckList(new Soldier);
        ob.addToDeckList(new Sword);
        ob.addToDeckList(new Snake);
    }
    
    ob.shuffleDeck();
    ob.draw(5);
    
    while(pb.getHP() > 0 && ob.getHP() > 0){                                        
        pb.unExhaustField();                                                        
        ob.unExhaustField();
        pb.setMana(turn);
        ob.setMana(turn);
        pb.draw(5 - pb.getHandSize());
        ob.draw(5 - ob.getHandSize());
        renderBoard(pb,ob);
        
        if (playerFirst == 1) {
            getPlayerAction(pb,ob);
            if (ob.getHP() > 0) {
                getOpponentAction(pb,ob);
            }
        }
        else {
            getOpponentAction(pb,ob);
            if (pb.getHP() > 0) {
                getPlayerAction(pb,ob);
            }
        }
        
        turn++;
        
    } 
    
    if (pb.getHP() <= 0) {
        cout << "Opponent wins!" << endl;
	cout << "DEFEAT!" << endl;
    }
    else {
        cout << "Victory!" << endl;
    }
    
    return 0;
}

void renderBoard(Board & pb, Board & ob){
    std::system("clear");                                                       

    
    ob.renderField();
    cout << endl;
    
    pb.renderField();
    pb.renderHand();
    
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    
    //clearScreen(1);
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    
    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(i);
        }
        
    }
   
    
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() >= playerBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destroy creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destroyed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                sleep(2);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
        }
                
    }
    sleep(3);                                                                                                                               
    renderBoard(playerBoard, opponentBoard);
}

void getPlayerAction(Board & pb, Board & ob) {
    int play = 1;
    int attack = 1;
    int target = 1;
    while(true) {                                                                                                                                               
        cout << "Draw a card, or press 9 to input attacks..." << endl;
        
        for (int i = 0; i < pb.getHandSize(); i++) {
            cout << i << ": " << pb.getCardInHand(i)->getName() << " Cost: " << pb.getCardInHand(i)->getManaCost() << endl;
        }
        cout << "9: Input attacks" << endl;
        
        cin >> play;
        
        if(play != 9) {
            if (play >= 0 && play < pb.getHandSize()) {
                pb.playCardFromHand(play);
                renderBoard(pb, ob);
            }
            else {
                cout << "Invalid input." << endl;
            }  
        }
        else {
            break;
        }
    }
    
    while(ob.getHP() > 0) {                                                                                                                                         
        sleep(1);
        renderBoard(pb, ob);
        cout << "Select a card to attack with. Press 9 to end your turn... " << endl;
        
        for (int i = 0; i < pb.getFieldSize(); i++) {
            cout << i << ": " << pb.getCardOnField(i)->getName() << " This card";
            if (pb.getCardOnField(i)->isExhausted()) {
                cout << " is sleepy..." << endl;
            }
            else {
                cout << " is wide awake!" << endl;
            }
        }
        cout << "9: End turn" << endl;
        
        cin >> attack;
        
        if (attack == 9) {
            break;
        }
        else if (attack >= 0 && attack < pb.getFieldSize()) {                                                                                                       
            if (!pb.getCardOnField(attack)->isExhausted()) {                                                                                                        
                cout << "Select which card to attack. Press 9 to attack the enemy summoner! " << endl;
                
                for (int i = 0; i < ob.getFieldSize(); i++) {
                    cout << i << ": " << ob.getCardOnField(i)->getName() << " Defense: " << ob.getCardOnField(i)->getDefense() << endl;;
                }
                cout << "9: Go for the face!" << endl;
                
                cin >> target;
                
                if(target == 9){
                    
                    cout << "Your " << pb.getCardOnField(attack)->getName() << " attacks the enemy player for " << pb.getCardOnField(attack)->getAttack() << " points of damage!" << endl;
                    	ob.setHP(ob.getHP() - pb.getCardOnField(attack)->getAttack());
                    	pb.getCardOnField(attack)->exhaustCard();
                    
                } 
                else if (target >= 0 && target < ob.getFieldSize()) {                                                                                               
                    if (pb.getCardOnField(attack)->getAttack() >= ob.getCardOnField(target)->getDefense()) {                                                        
                        cout << "Your " << pb.getCardOnField(attack)->getName() << " destroyed the enemy " << ob.getCardOnField(target)->getName() << "!" << endl;
                        ob.discardCardFromField(target);
                        pb.getCardOnField(attack)->exhaustCard();
                        sleep(2);
                        renderBoard(pb, ob);
                    }
                    else {
                        cout << "Your card is not strong enough to destroy the opponent's card." << endl;
                    }
                }
                else {
                    cout << "Invalid input." << endl;
                }
            }
            else {
                cout << "That card just arrived. Give it time to rest!" << endl;
            }
                
        }
        else {
            cout << "Invalid input." << endl;
        }
            
    }
    sleep(1);
    renderBoard(pb,ob);
    
}
