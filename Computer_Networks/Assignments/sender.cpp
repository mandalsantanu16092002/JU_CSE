#include <iostream>
#include <fstream>

using namespace std;

class Sender
{
    int packet_size;

public:
    Sender(int sz = 1)
    {
        packet_size = sz;
    }
    void create_pac()
    {
        ifstream obj;
        obj.open("input.txt");
        char s1[packet_size + 1];
        obj.seekg(0, ios::beg);
        obj.read(s1, packet_size);
        s1[packet_size] = '\0';
        ofstream objj;
        objj.open("sender_data.txt", ios::trunc);
        objj << s1;
        objj << " ";
        while (obj.eof() == false)
        {
            obj.read(s1, packet_size);
            s1[packet_size] = '\0';
            if (obj.eof())
            {
                break;
            }
            objj << s1;
            objj << " ";
        }
        objj.close();
        obj.close();
    }
    void add_parity_longi()
    {
        string s1;
        static string s2;
        int i;
        ifstream in;
        in.open("input.txt");
        in >> s1;
        in.close();
        ifstream inn;
        inn.open("sender_data.txt");
        for (int i = 0; i < packet_size; i++)
        {
            int k = 0;
            inn.seekg(i, ios::beg);
            char ch[2];
            inn.read(ch, 1);
            ch[1] = '\0';
            if (ch[0] == '1')
            {
                k++;
            }
            int j = s1.length() / packet_size;
            while (j - 1)
            {
                inn.seekg(packet_size, ios::cur);
                char ch[2];
                inn.read(ch, 1);
                ch[1] = '\0';
                if (ch[0] == '1')
                {
                    k++;
                }
                j--;
            }
            if (k % 2 == 0)
            {
                s2.append("0");
            }
            else
                s2.append("1");
        }
        inn.close();
        ofstream outt;
        outt.open("sender_data.txt", ios::app);
        outt << s2;
        outt.close();
    }
    void add_parity_vertical()
    {
        string s1;
        string s3;
        char ch;
        ifstream ope;
        ope.open("input.txt");
        ope >> s3;
        ope.close();
        static string s2;
        ifstream opp;
        opp.open("sender_data.txt");
        opp >> s1;
        for (int i = 0; i < s3.size() / packet_size; i++)
        {
            opp.seekg((packet_size + 1) * i, ios::beg);
            int k = 0;
            for (int j = 0; j < packet_size; j++)
            {
                opp.get(ch);
                if (ch == '1')
                {
                    k++;
                }
            }
            if (k % 2 == 0)
            {
                s2.append("0");
            }
            else
                s2.append("1");
        }
        opp.close();
        ofstream outt;
        outt.open("sender_data.txt", ios::app);
        outt << s2;
        outt.close();
    }

    string divide(string s1, string gen)
    {
        string temp;
        for (int i = 0; i < gen.length() - 1; i++)
        {
            temp.append("0");
        }
        s1.append(temp);
        string s2 = s1;

        for (int i = 0; i <= (s1.length() - gen.length()); i++)
        {
        B:
            if (s1[i] == '0')
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
                    else if ((s1[i + j] == '1' && gen[j] == '0') || (s1[i + j] == '0' && gen[j] == '1'))
                        s1[i + j] = '1';
                    else
                        cout << "Error in program" << endl;
                }
            }
        }
        string tem = s1.substr(s1.length() - gen.length() + 1);
        return tem;
    }
    void crc()
    {
        ifstream op;
        op.open("input.txt");
        string s1;
        op >> s1;
        op.close();
        string s2 = s1;
        cout << "The string s2 is: " << s2 << endl;
        string gen;
        cout << "Enter the generator: ";
        cin >> gen;
        string str = divide(s1, gen);
        cout << "The crc is: " << str << endl;
        s2 = s2 + str;
        ofstream ofs;
        ofs.open("sender_data.txt");
        ofs << s2;
        ofs.close();
    }

    void checksum()
    {
        ifstream op;
        op.open("input.txt");
        string s1;
        op >> s1;
        op.close();
        ifstream inn;
        inn.open("sender_data.txt");
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
        inn.close();
        string stj = to_string(res);
        ofstream ofs;
        ofs.open("sender_data.txt", ios::app);
        ofs << stj;
        ofs.close();
    }
};

int main()
{
    cout << "Enter no. of bits to be entered: ";
    int j;
    cin >> j;
    ofstream oop;
    oop.open("input.txt", ios::trunc);
    string s;
    cout << "Enter the bits in form of string: ";
    cin >> s;
    oop << s;
    oop.close();
    int i;
    cout << "Enter packet size: ";
    cin >> i;
    Sender first(i);
    first.create_pac();
    // first.add_parity_longi();
    // first.add_parity_vertical();
    // first.crc();
    first.checksum();
    return 0;
}