#include <bits/stdc++.h>

using namespace std;

bool is_valid(string expression) {

    // General idea is to use 2 stacks one for the paranthesis+operator and
    // other for the integers
    // push open paranthesis , operators in the paranthesis_operator_stack
    // push numbers in the number_stack
    // when a closed paranthesis is encountered - pop paranthesis_operator_stack
    // if an operator is encountered in the popping of paranthesis_operator_stack
    // pop 2 elements from number_stack evaluate and push the result back into number_stack
    // if the operation cannot be completed because of stack being empty or encountering a
    // wrong open paranthesis then return false
    // when the complete string "expression" processed ,
    // paranthesis_operator_stack should be empty and number_stack should have just one value
    // then return true else return false

    stack<char> paranthesis_operator_stack;
    stack<int> number_stack;

    unordered_set<char> open_paranthesis({ '(','[','{' });
    unordered_set<char> close_paranthesis({ ')',']','}' });
    unordered_set<char> operators({ '+','-' ,'*' });
    unordered_map<char,char> correct_paranthesis(3);
    correct_paranthesis[')']='(';
    correct_paranthesis[']']='[';
    correct_paranthesis['}']='{';
    int curr_num_count=0,curr_operator_count=0;

    for(auto elem:expression){
        if(close_paranthesis.find(elem) != close_paranthesis.end()){
            //elem is closed paranthesis
            // pop until open_paranthesis
            char top_operator_paranthesis;
            // while processing the stacks , found_closing will be true only
            // when a matching paranthesis has been found . it is used to
            // determins if the below while exited without finding a matching paranthesis.
            bool found_opening=false;
            while(!paranthesis_operator_stack.empty()){
                top_operator_paranthesis = paranthesis_operator_stack.top();
                paranthesis_operator_stack.pop();
                // top_operator_paranthesis could be a operator or open paranthesis
                // if it is a open paranthesis it has to be matched with correct_paranthesis
                // for the elem
                // if it is a operator , number_stack should be popped and evaluated
                // result pushed back into number stack

                if(operators.find(top_operator_paranthesis) != operators.end()){
                    // top_operator_paranthesis is an operator
                    if(number_stack.size() < 2){
                        return false;
                    }
                    int operand2,operand1;
                    operand1=number_stack.top();
                    number_stack.pop();
                    operand2=number_stack.top();
                    number_stack.pop();
                    int result;
                    switch(top_operator_paranthesis){
                        case '*' : result=operand1*operand2;
                                   break;
                        case '+' : result=operand1+operand2;
                                   break;
                        case '-' : result=operand1-operand2;
                                   break;
                    }
                    number_stack.push(result);
                    //continue processing for the current "elem"
                    continue;
                }else{
                    // top_operator_paranthesis is a paranthesis
                    if(correct_paranthesis[elem] != top_operator_paranthesis){
                        return false;
                    }else{
                        // encountered a correct paranthesis
                        // proceeed with the next elem in "expression"
                        found_opening=true;
                        break;
                    }
                }
            }
            if(!found_opening){
                return false;
            }

        } else
        if(open_paranthesis.find(elem) != open_paranthesis.end() ||
           operators.find(elem) != operators.end()
          )
        {
            if(operators.find(elem) != operators.end()){
                curr_operator_count++;
                // if elem is an operator , make sure the operator_count is always less than 
                // curr_num_count
                if( curr_operator_count > curr_num_count){
                    return false;
                }
                
            }
            //elem is a open paranthesis or operator,push to paranthesis_operator_stack
            paranthesis_operator_stack.push(elem);
        }else{
            curr_num_count++;
            // numbers have to exactly be 1 more than operators
            if( (curr_num_count - curr_operator_count) != 1){
                return false;
            }
            // elem is number , push to number stack
            number_stack.push(atoi(&elem));
        }
    }
    // processed all elements in "expression"
    // process remaining elements in the stacks
    // at this point the paranthesis_operator_stack will have only operators
    while(!paranthesis_operator_stack.empty()){
        if(number_stack.size()<2){
            return false;
        }
        int operand2,operand1;
        int result;
        char top_operator;

        operand1=number_stack.top();
        number_stack.pop();
        operand2=number_stack.top();
        number_stack.pop();
        top_operator = paranthesis_operator_stack.top();
        paranthesis_operator_stack.pop();
        switch(top_operator){
            case '*' : result=operand1*operand2;
                       break;
            case '+' : result=operand1+operand2;
                       break;
            case '-' : result=operand1-operand2;
                       break;

        }
        number_stack.push(result);
    }

    // all operators have been processed and only one value is expected in number_stack
    if(number_stack.size() > 1){
        return false;
    }
    return true;

}


int main()
{
    ostream &fout = cout;

    string expression;
    getline(cin, expression);

    bool result = is_valid(expression);

    fout << result << "\n";

    return 0;
}

