#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
typedef map<PII, string> MPS;
typedef map<string, PII> MSP;
typedef map<PII, PII> MPP;
const int N = 1e7;


const char table1[16][16][20] = {
  "NUL","SOH","STX","ETX","","HT","","DEL","","","","VT","FF","CR","SO","SI",
  "DLE","DC1","DC2","DC3","","","BS","","CAN","EM","","","IFS","IGS","IRS","IUS ITB",
  "","","","","","LF","ETB","ESC","","","","","","ENQ","ACK","BEL",
  "","","SYN","","","","","EOT","","","","","DC4","NAK","","SUB",
  "SP","","","","","","","","","","",".","<","(","+","|",
  "&","","","","","","","","","","!","$","*",")",";","",
  "-","/","","","","","","","","","",",","%","_",">","?",
  "","","","","","","","","","`",":","#","@","'","=","\"",
  "","a","b","c","d","e","f","g","h","i","","","","","","",
  "","j","k","l","m","n","o","p","q","r","","","","","","",
  "","~","s","t","u","v","w","x","y","z","","","","","","",
  "^","","","","","","","","","","[","]","","","","",
  "{","A","B","C","D","E","F","G","H","I","","","","","","",
  "}","J","K","L","M","N","O","P","Q","R","","","","","","",
  "\\","","S","T","U","V","W","X","Y","Z","","","","","","",
  "0","1","2","3","4","5","6","7","8","9","","","","","",""
};
char table2[8][16][20]  = {
  "NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI",
  "DLE","DC1","DC2","DC3","DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","IFS","IGS","IRS","IUS ITB",
  "SP","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/",
  "0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?",
  "@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
  "P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","^","_",
    "`","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
  "p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","DEL",
};
MPS mps;
MSP msp;
MPP mpp;

void init() {
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++) 
      mps[PII(i, j)] = table1[i][j];
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 16; j++) 
      msp[table2[i][j]] = PII(i, j);
  for (MPS::iterator i = mps.begin(); i != mps.end(); i++)
    mpp[i->first] = msp[i->second];
}

char b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
  int r, c;
  for ( ; ~scanf("%1X%1X", &r, &c); ) {
    PII ans = mpp[PII(r, c)];
    printf("%X%X", ans.first, ans.second);
  }
  puts("");
  return 0;
}
