#include <iostream>
#include <fstream>

using namespace std;

class Injector
{
    int ran;
    int packet_size;

public:
    void injection(int pac)
    {
        packet_size = pac;
        int i = rand() % packet_size;
        ifstream ip;
        ip.open("input.txt");
        string s1;
        ip >> s1;
        ip.close();
        int j = rand() % (s1.length() / packet_size);
        int ran = j * (packet_size + 1) + i;
        fstream obi;
        obi.open("sender_data.txt", ios::in | ios::out | ios::app);
        fstream obf;
        string line;
        obf.open("error_data.txt", ios::in | ios::out | ios::trunc);
        getline(obi, line);
        if (line[ran] == '0')
        {
            line[ran] = '1';
        }
        else if (line[ran] == '1')
        {
            line[ran] = '0';
        }
        obf << line;
        obi.close();
        obf.close();
    }
    void non_injection(int pac)
    {
        packet_size = pac;
        ifstream ip;
        ip.open("sender_data.txt");
        string str;
        getline(ip, str);
        ofstream op;
        op.open("error_data.txt");
        op << str;
        op.close();
        ip.close();
    }

    void injection_in_crc()
    {
        ifstream ifs;
        ifs.open("input.txt");
        string s1;
        ifs >> s1;
        ifs.close();
        int l = s1.length();
        ifstream ifso;
        ifso.open("sender_data.txt");
        ifso >> s1;
        ifso.close();
        ran = rand() % (l - 1);
        if (s1[ran] == '1')
        {
            s1[ran] = '0';
        }
        else
            s1[ran] = '1';
        ofstream ofs;
        ofs.open("error_data.txt", ios::trunc);
        ofs << s1;
        ofs.close();
    }
};

int main()
{
    Injector ij;
    int i;
    cout << "Enter packet length: ";
    cin >> i;
    // ij.injection(i);
    ij.non_injection(i);
    // ij.injection_in_crc();
    return 0;
}