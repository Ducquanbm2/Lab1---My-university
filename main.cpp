#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;



struct Num { 
    char sign;
    string value = "";
};



bool CompareNum(Num &a, Num &b) { 
    if (a.sign == '+' && b.sign == '-') { 
        return false;
    }
    if (a.sign == '-' && b.sign == '+') { 
        return true;
    }
    if (a.sign == '-') { // Nếu a và b đều âm
        if (a.value.size() < b.value.size()) return false;
        if (a.value.size() > b.value.size()) return true;
        for (int i = 0; i < a.value.size();i++) {
            if (a.value[i] < b.value[i]) return false;
            else if (a.value[i] > b.value[i]) return true; 
        }
        return true;
    }
    else { // Nếu a và b đều dương
        if (a.value.size() < b.value.size()) return true;
        if (a.value.size() > b.value.size()) return false;
        for (int i = 0; i < a.value.size();i++) {
            if (a.value[i] < b.value[i]) return true;
            else if (a.value[i] > b.value[i]) return false;
        }
        return true;
    }
}


int level(char t) {
    if (t == '*' || t == '/') { 
        return 2; 
    } 
    else if (t == '+' || t == '-') return 1; 
    return 0;
}


Num add(Num &a, Num &b) { 
    if (a.sign == '+' && b.sign == '-') { 
        Num c;
        c.sign = '+';
        b.sign = '+';
        if (CompareNum(a, b) == true) { 
            swap(a, b);
            c.sign = '-';
        }
        while (a.value.size() < b.value.size()) a.value = '0' + a.value; 
        while (a.value.size() > b.value.size()) b.value = '0' + b.value;
        int tmp = 0;
        for (int i = a.value.size() - 1; i >= 0;i--) { 
            int k = a.value[i] - '0';
            int kk = b.value[i] - '0';
            int cur = k - kk - tmp; 
            if (cur < 0) { 
                tmp = 1;
                cur = cur + 10; 
            }
            else { 
                tmp = 0;
            }
            char r = (cur + '0');
            c.value = r + c.value;
        }
        while (c.value.size() > 1 && c.value[0] == '0') { 
            c.value.erase(0, 1);
        }
        return c;
    }
    else if (a.sign == '-' && b.sign == '+') { 
        Num c;
        a.sign = '+';
        if (CompareNum(b, a) == true) { 
            swap(a, b);
            c.sign = '-';
        }
        while (a.value.size() < b.value.size()) a.value = '0' + a.value;
        while (a.value.size() > b.value.size()) b.value = '0' + b.value;
        int tmp = 0;
        for (int i = b.value.size() - 1; i >= 0;i--) {
            int k = b.value[i] - '0';
            int kk = a.value[i] - '0';
            int cur = k - kk - tmp;
            if (cur < 0) {
                tmp = 1;
                cur = cur + 10;
            }
            else {
                tmp = 0;
            }
            char r = (cur + '0');
            c.value = r + c.value;
        }
        while (c.value.size() > 1 && c.value[0] == '0') {
            c.value.erase(0, 1);
        }
        return c;
    }
    while (a.value.size() < b.value.size()) { 
        a.value = '0' + a.value;
    }
    while (a.value.size() > b.value.size()) {
        b.value = '0' + b.value;
    }
    Num c;
    int nho =  0;
    for (int i = a.value.size() - 1; i >= 0;i--) { 
        int k = a.value[i] - '0';
        int kk = b.value[i] - '0';
        char r = (k + kk + nho) % 10 + '0'; 
        c.value = r + c.value;
        nho = (k + kk + nho) / 10;
    }
    if (nho > 0) { 
        char r = nho + '0';
        c.value = r + c.value;
    }
    c.sign = a.sign;
    return c;
}


Num sub(Num a, Num b) { 
    if (b.sign == '-') { 
        Num c = b;
        c.sign = '+';
        return add(a, c);
    }
    if (a.sign == '-' && b.sign == '+') { 
        Num d = a;
        d.sign = '+';
        d = add(d, b);
        d.sign = '-';
        return d;
    }

    Num c;
    c.sign = '+';
    if (CompareNum(a, b) == true) {
        swap(a, b);
        c.sign = '-';
    }
    while (a.value.size() < b.value.size()) a.value = '0' + a.value;
    while (a.value.size() > b.value.size()) b.value = '0' + b.value;
    int tmp = 0;
    for (int i = a.value.size() - 1; i >= 0;i--) {
        int k = a.value[i] - '0';
        int kk = b.value[i] - '0';
        int cur = k - kk - tmp;
        if (cur < 0) {
            tmp = 1;
            cur = cur + 10;
        }
        else {
            tmp = 0;
        }
        char r = (cur + '0');
        c.value = r + c.value;
    }
    while (c.value.size() > 1 && c.value[0] == '0') {
        c.value.erase(0, 1);
    }
    return c;
}



Num mul(Num &a, char b) { 
    Num c;
    c.sign = '+';
    c.value = "";
    int nho = 0;
    for (int i = a.value.size() - 1; i >= 0; i--) { 
        int k = a.value[i] - '0';
        int kk = b - '0';
        int cur = k * kk + nho;
        char r = (cur % 10) + '0';
        nho = cur / 10;
        c.value = r + c.value;
    }
    if (nho > 0) {
        char r = nho + '0';
        c.value = r + c.value;
    }
    return c;
}



Num mul(Num &a, Num &b) { 
    if (a.value.size() < b.value.size()) {
        swap(a, b);
    }
    Num ans;
    ans.sign = '+';
    ans.value = "";
    for (int i = b.value.size() - 1; i >= 0;i--) {
        Num c = mul(a, b.value[i]);
        c.value.insert(c.value.size(), b.value.size() - i - 1, '0');
        ans = add(ans, c);
    }
    if (a.sign != b.sign) {
        ans.sign = '-';
    }
    else {
        ans.sign = '+';
    }
    return ans;
}




char find(Num &a, Num &b) { 
    int d = 1, c = 9;
    char anss = '1';
    
    while (d <= c) {
        int g = (d + c) / 2;
        char r = g + '0';
        Num res = mul(b, r);
        if (CompareNum(res ,a) == true) {
            anss = r;
            d = g + 1;
        }
        else {
            c = g - 1;
        }
    }
    return anss;
}


Num div(Num &a, Num &b) { 
    Num c;
    c.value = "";
    c.sign = (a.sign == b.sign) ? '+' : '-';
    a.sign = b.sign = '+';  
    Num cur;
    cur.value = "";
    cur.sign = '+';
    while (b.value.size() > 1 && b.value[0] == '0') {
        b.value.erase(0, 1);
    } 
    for (int i = 0; i < a.value.size(); ++i) {
        cur.value += a.value[i];
        while (cur.value.size() > 1 && cur.value[0] == '0') {
            cur.value.erase(0, 1);
        }
        if (CompareNum(b, cur)) { 
            char r = find(cur, b);
            c.value += r;
            Num res = mul(b, r);
            res.sign = '+';
            cur = sub(cur, res);
            cur.sign = '+';
        } else {
            c.value += '0';
        }
    }
    while (c.value.size() > 1 && c.value[0] == '0') {
        c.value.erase(0, 1);
    }
    if (c.value == "0") c.sign = '+';
    cur.value = "";
    return c;
}




Num cal(Num &a, Num &b, char &op) { 
    if (op == '+') {
        return add(a, b);
    }
    if (op == '-') {
        return sub(a, b);
    }
    if (op == '*') {
        return mul(a, b);
    }
    return div(a, b);
}


bool isDigit(const char t) { 
    if (t >= '0' && t <= '9') return true;
    return false;
}



bool isOperator(char t) { 
    return (t == '+' || t == '-' || t == '*' || t == '/');
}

bool preSolve(string &s) { 
    stack<int>bracket; 
    bool checkNum = false; 
    bool checkOperator = true; 
    for (int i = 0; i < s.size();i++) { 
        if (isDigit(s[i]) == true) {
            if (i > 0 && isDigit(s[i - 1]) == false && checkNum == true) {
                return false;
            }
            checkNum = true;
            checkOperator = false;
        }
        else if (s[i] == '(') { 
            if (checkNum == true) {
                return false;
            }
            checkOperator = false;
            bracket.push(1);
        }
        else if (s[i] == ')') { 
            if (checkNum == false) { 
                return false;
            }
            if (bracket.empty()) return false; 
            bracket.pop(); 
            checkOperator = false;
        }
        else if (isOperator(s[i]) == true) { 
            if (checkOperator == true) { 
                return false;
            }
            checkOperator = true; 
            checkNum = false;
        }
    }
    if (!bracket.empty()) return false; 
    return true; 
}






bool isZero(Num b) { 
    for (int i = 0; i < b.value.size();i++) {
        if (b.value[i] != '0') return false;
    }
    return true;
}



void solve(ostream &fout, string s) { 
    if (preSolve(s) == false) { 
        fout << "Error" << '\n';
        cout << "Error" << '\n';
        return;
    }
    stack<Num>val; 
    stack<char>Operator; 
    while (!val.empty()) val.pop();
    while (!Operator.empty()) Operator.pop();
    string curValue = ""; 
    char curSign = '+'; 
    int i = 0;
    bool checkNum = false, ok = false; 
    while (i < s.size()) { 
        while (i < s.size() && isDigit(s[i]) == true) { 
            curValue += s[i];
            i++;
            checkNum = true; 
        }
        if (s[i] == '(') { 
            Operator.push(s[i]); 
            checkNum = false; 
            ok = false; 
        }
        else if (isOperator(s[i]) == true) { 
            if (checkNum == true) { 
                if (curValue != "") { 
                    Num cur;
                    cur.sign = curSign;
                    cur.value = curValue;
                    curValue = "";
                    curSign = '+';
                    val.push(cur);
                }
                while (!Operator.empty() && level(Operator.top()) >= level(s[i])) { 
                    char op = Operator.top();
                    Operator.pop();
                    if (val.empty()) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    Num b = val.top();
                    val.pop();
                    if (val.empty()) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    Num a = val.top();
                    val.pop();
                    if (op == '/' && isZero(b) == true) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    Num c = cal(a, b, op);
                    val.push(c);
                }
                Operator.push(s[i]);
                ok = false; 
            }
            else {
                curSign = s[i];
                ok = true; 
            }
            checkNum = false;
        }
        else if (s[i] == ')') { 
            if (ok == true) { 
                Num cur;
                cur.sign = curSign;
                cur.value = curValue;
                val.push(cur);
                curValue = "";
                curSign = '+';
                Operator.pop();
            }
            else { 
                if (checkNum == true && curValue != "") {  
                    Num cur;
                    cur.sign = curSign;
                    cur.value = curValue;
                    curValue = "";
                    curSign = '+';
                    val.push(cur);
                }
                while (!Operator.empty() && Operator.top() != '(') { 
                    char op = Operator.top();
                    Operator.pop();
                    if (val.empty()) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    Num b = val.top();
                    val.pop();
                    Num a = val.top();
                    if (val.empty()) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    val.pop();
                    if (op == '/' && isZero(b) == true) {
                        fout << "Error" << '\n';
                        cout << "Error" << '\n';
                        return;
                    }
                    Num c = cal(a, b, op);
                    val.push(c);
                }
                Operator.pop();
            }
            checkNum = true;
            ok = false;
        }
        i++;
    }
    if (checkNum == true && curValue != "") { 
        Num cur;
        cur.sign = curSign;
        cur.value = curValue;
        curValue = "";
        curSign = '+';
        val.push(cur);
    }
    while (!Operator.empty()) { 
        char op = Operator.top();
        Operator.pop();
        if (val.empty()) {
            fout << "Error" << '\n';
            cout << "Error" << '\n';
            return;
        }
        Num b = val.top();
        val.pop();
        if (val.empty()) {
            fout << "Error" << '\n';
            cout << "Error" << '\n';
            return;
        }
        Num a = val.top();
        val.pop();
        if (op == '/' && isZero(b) == true) {
            fout << "Error" << '\n';
            cout << "Error" << '\n';
            return;
        }
        Num c = cal(a, b, op);
        val.push(c);
        
    }
    Num c = val.top();
    val.pop();
    if (c.sign == '-' && c.value != "0") { 
        fout << "-";
        cout << "-";
    }
    cout << c.value << '\n'; 
    fout << c.value << '\n';
    return;
}





int main(int argc, char* argv[]) {
    if (argc != 3) { 
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }
    string inputPath = argv[1];
    string outputPath = argv[2];
    ifstream fin(inputPath);
    if (!fin.is_open()) { 
        cerr << "Error: Could not open input file '" << inputPath << "'\n";
        return 1;
    }
    ofstream fout(outputPath);
    if (!fout.is_open()) { 
        cerr << "Error: Could not open output file '" << outputPath << "'\n";
        fin.close();
        return 1;
    }
    string s;
    while (getline(fin, s)) {
        solve(fout, s); 
    }
    if (fin.bad()) {
        cerr << "Error: An error occurred while reading the input file\n";
        fin.close();
        fout.close();
        return 1;
    }
    fin.close();
    fout.close();

    return 0;
}