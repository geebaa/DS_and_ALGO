#include <bits/stdc++.h>
using namespace std;
/*
    Given an input of cards that have suits { +, -, = }, values { A, B, C },
    and different counts of values [1 - 3]. Find a valid hand.
    A valid hand consists of 3 cards.
    Where all the suits are different or the same
                    &&
    all the values are different or the same
                    && 
    all counts are different or the same.
*/

char get_suite(string &card)
{
    return card[0];
}
char get_value(string &card)
{
    return card[1];
}
char get_count(string &card)
{
    // "-1" is because the card always has one character 
    // dedicated for suite
    return card.size() - 1;
}

typedef enum {eSuite,eValue,eCount} CardProperty;

bool is_same_property(CardProperty p,string &c1,string &c2,string &c3)
{
    bool result=false;
    cout << " is_same ";
    switch(p){
        case  eSuite :
            result = (get_suite(c1)==get_suite(c2))?(get_suite(c2) == get_suite(c3)):false;
            cout << "eSuite : result " << result<<endl; 
            break;
        case eValue :
            result = (get_value(c1)==get_value(c2))?(get_value(c2) == get_value(c3)):false;
            cout << "eValue : result " << result<<endl; 
            break;
        case eCount :
            result = (get_count(c1)==get_count(c2))?(get_count(c2) == get_count(c3)):false;
            cout << "eCount : result " << result<<endl; 
            break;
    }
    return result;
}

bool is_diff_property(CardProperty p,string &c1,string &c2,string &c3)
{
    bool result=false;
    cout << " is_diff ";
    switch(p){
        case  eSuite :
            result = (get_suite(c1)!=get_suite(c2))?( (get_suite(c1) != get_suite(c3)) && (get_suite(c2) != get_suite(c3))):false;
            cout << "eSuite : result " << result<<endl; 
            break;
        case eValue :
            result = (get_value(c1)!=get_value(c2))?( (get_value(c1) != get_value(c3)) && (get_value(c2) != get_value(c3))):false;
            cout << "eValue : result " << result<<endl; 
            break;
        case eCount :
            result = (get_count(c1)!=get_count(c2))?( (get_count(c1) != get_count(c3)) && (get_count(c2) != get_count(c3))):false;
            cout << "eCount : result " << result<<endl; 
            break;
    }
    return result;
}

bool is_valid_hand(string &c1,string &c2,string &c3)
{
    if(is_same_property(eSuite,c1,c2,c3) || is_diff_property(eSuite,c1,c2,c3)){
        if(is_same_property(eValue,c1,c2,c3) || is_diff_property(eValue,c1,c2,c3)){
            if(is_same_property(eCount,c1,c2,c3) || is_diff_property(eCount,c1,c2,c3)){
                return true;
            }
        }
    }
    return false;
}

vector<string> get_a_valid_hand(vector<string> &cards)
{
    /*
        we make choices of 3 cards 
        return if they are valid, else 
        proceed picking a different three
        until all possibilities are exhausted
    */
    for(int i=0;i<cards.size();i++){
        for(int j=i+1;j<cards.size();j++){
            for(int k=j+1;k<cards.size();k++){
                if(is_valid_hand(cards[i],cards[j],cards[k])){
                    return {cards[i],cards[j],cards[k]};
                }
            }
        }
    }
    return {};
}

int main()
{
    vector<string> cards;
    string card;
    int numcards;
    cout << " Number of cards : ";
    cin >> numcards;
    for(int i=0;i<numcards;i++){
        cin >> card;
        cards.push_back(card);
    }

    vector<string> valid_hand=get_a_valid_hand(cards);
    cout << endl << "Valid Hand : ";
    for(auto card : valid_hand){
        cout << " " << card;
    }
    cout <<endl;
}

