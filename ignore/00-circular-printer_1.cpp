int timeToPrint(char a, char b) {
  int p = abs(a - b); 
  int q = 26 - p ;
  return min(p, q); 

  //  one of them represent clockwise swing time and other represent
  //  anticlockwise swing time take which one is best 
}

int getTime(string& s) {
  int cnt = 0 ; 
  char last = 'A';
  for( auto curr : s )
  {
    cnt += timeToPrint( last , curr ); 
    last = curr ; 
  }
  return cnt ; 
} 
