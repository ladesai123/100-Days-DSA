class Solution {
public:
    int maximum69Number (int num) {
      
        string str = to_string(num);// convert to string

        for(int i=0; i<str.size(); i++){
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        return stoi(str); //string to int
    }
};
