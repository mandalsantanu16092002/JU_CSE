#include <iostream>
#include <fstream>

using namespace std;

class receiver
{
    int packet_size;

public:
    receiver(int sz = 1)
    {
        packet_size = sz;
    }
    void result_of_lrc()
    {
        ifstream obj;
        obj.open("error_data.txt");
        string line;
        obj >> line;
        int k = 0;
        ifstream objj;
        objj.open("input.txt");
        string s1;
        objj >> s1;
        objj.close();
        for (int i = 0; i < s1.length() / packet_size; i++)
        {
            int k = 0;
            obj.seekg(i, ios::beg);
            char ch[2];
            obj.read(ch, 1);
            ch[1] = '\0';
            if (ch[0] == '1')
            {
                k++;
            }
            int j = s1.length() / packet_size;
            while (j)
            {
                obj.seekg(packet_size, ios::cur);
                char ch[2];
                obj.read(ch, 1);
                ch[1] = '\0';
                if (ch[0] == '1')
                {
                    k++;
                }
                j--;
            }
            if (k % 2 != 0)
            {
                cout << "Error detected" << endl;
                return;
            }
            else
                continue;
        }
        cout << "No error" << endl;
        return;
    }
    void result_of_crc()
    {
        string gen;
        cout << "Enter the generator: ";
        cin >> gen;
        string ss;
        cout << "add reqd remainder: ";
        cin >> ss;
        ifstream iff;
        string s1;
        iff.open("error_data.txt");
        iff >> s1;
        iff.close();

        for (int i = 0; i <= (s1.length() - gen.length()); i++)
        {
        B:
            if (gen[i] == '0')
            {
                i++;
                goto B;
            }
            else
            {
                for (int j = 0; j < gen.length(); j++)
                {
                    if ((s1[i + j] == '1' && gen[j] == '1') || (s1[i + j] == '0' && gen[j] == '0'))
                    {
                        s1[i + j] = '0';
                    }
                    else
                        s1[i + j] = '1';
                }
            }
        }
        string tem = s1.substr(s1.length() - gen.length() + 1);
        cout << ss << endl;
        cout << tem << endl;
        if (tem != ss)
        {
            cout << "Error present !" << endl;
            return;
        }
        else
            cout << "No error !" << endl;
        return;
    }
    void checksum_error_check()
    {
        ifstream op;
        op.open("input.txt");
        string s1;
        op >> s1;
        op.close();
        ifstream inn;
        inn.open("error_data.txt");
        char s[packet_size + 1];
        int res = 0;
        for (int i = 0; i < s1.length() / packet_size; i++)
        {
            inn.seekg(i * (packet_size + 1), ios::beg);
            for (int j = 0; j < packet_size; j++)
            {
                inn.get(s[j]);
            }
            s[packet_size] = '\0';
            string sss;
            sss = s;
            res += stoi(sss);
        }
        inn.seekg((s1.length() / packet_size) * (packet_size + 1), ios::beg);
        char ch[packet_size + 1];
        int check;
        for (int i = 0; i < packet_size; i++)
        {
            inn.get(ch[i]);
        }
        ch[packet_size] = '\0';
        string ssss;
        ssss = ch;
        check = stoi(ssss);
        inn.close();
        if (res == check)
        {
            cout << "No error" << endl;
            return;
        }
        else
            cout << "Error ! " << endl;
        return;
    }
};

int main()
{
    cout << "Enter packet size: ";
    int i;
    cin >> i;
    receiver rc(i);
    // rc.result_of_lrc();
    // rc.result_of_crc();
    rc.checksum_error_check();
    return 0;
}